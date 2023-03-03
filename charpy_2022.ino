#include <mcp_can.h>
#include <SPI.h>
#include <PID_v1.h>
#include <I2Cdev.h>
#include <Arduino.h>
#include <MPU6050_6Axis_MotionApps20.h>
#include <Wire.h>


#define STANDARD_CAN_FRAME 0
#define OPTIMUM_SPEED_M1 7100   //need to be divided with 19 to get actual rpm, max = 8911(with 3Nm torque)or 9158 (without load)         
#define OPTIMUM_SPEED_M2 7000   //need to be divided with 19 to get actual rpm, max = 8911(with 3Nm torque)or 9158 (without load)  
#define MAX_CURRENT_M1 2000     //max 16384
#define MIN_CURRENT_M1 -300  
#define MAX_CURRENT_M2 2000     //max 16384
#define MIN_CURRENT_M2 -300
#define SPD_CHG_PER_DEG 90      //how much speed change for every degree change in gyroscope              
#define LEFT_MAXIMUM_yaw_angle -0.3   //minimum allowable angle diversion 
#define RIGHT_MAXIMUM_yaw_angle 0.3 
#define LEFT_ADJUSTMENT_ANGLE -10     //angle given to adjust back if border is touched  //
#define RIGHT_ADJUSTMENT_ANGLE 10
#define LOOP_BEFORE_START_SENSOR 20
#define ADJUSTMENT_LOOP 15            // how many loop it takes to adjust back the position of robot if border is touched
#define INTERRUPT_PIN 2               //Interrupt pin for MPU9150
#define SDA 21                        //Define pin for SDA
#define SCL 22                        //Define pin for SCL
#define LINE_SENSOR_1 25              //Input Pin for Keyence Sensor 1
#define LINE_SENSOR_2 32              //Input Pin for Keyence Sensor 2


/***********************************
**MPU 6065 variables
***********************************/

/*********************Define the object "mpu" with the class "MPU6050"**********************/
/*Refer to https://www.w3schools.com/cpp/cpp_classes.asp for detailed explanation in class */ 
MPU6050 mpu;
            
/*other variables to store status or data from FIFO register of MPU6050*/
bool dmpReady = false;  // set true if DMP init was successful
uint8_t mpuIntStatus;   // holds actual interrupt status byte from MPU
uint8_t devStatus;      // return status after each device operation (0 = success, !0 = error)
uint16_t packetSize;    // expected DMP packet size (default is 42 bytes)
uint16_t fifoCount;     // count of all bytes currently in FIFO
uint8_t fifoBuffer[64]; // FIFO storage buffer
volatile bool mpuInterrupt = false;     // indicates whether MPU interrupt pin has gone high
/*Refer here for volatile data type : https://www.geeksforgeeks.org/understanding-volatile-qualifier-in-c/ */

/* orientation/motion vars */
Quaternion q;           // [w, x, y, z]         quaternion container
VectorFloat gravity;    // [x, y, z]            gravity vector
float euler[3];         // [psi, theta, phi]    Euler angle container
float ypr[3];           // [yaw, pitch, roll]   yaw/pitch/roll container and gravity vector

/*offset of gyroscope and accelerometer when initializing the MPU6050 */
int16_t* offsets;


//yaw angle
float total_yaw_angle;
float yaw_angle_now ;
float yaw_angle_prev = 0 ;
float spd_chg;        
            
bool turned_left;
bool turned_right;

/*function dmpDataReady() obtained from example in the MPU6050 library (not sure about the exact usage)*/
void dmpDataReady() {
    mpuInterrupt = true;
}

/*use fucntion PrintActiveOffsets to print the current offset of accelerometer and gyroscope in MPU6050 */
void PrintActiveOffsets() {
    offsets = mpu.GetActiveOffsets();
  //  A_OFFSET_H_READ_A_OFFS(Data);
    Serial.print((float)offsets[0], 2); Serial.print(",\t");
    Serial.print((float)offsets[1], 2); Serial.print(",\t");
    Serial.print((float)offsets[2], 2); Serial.print(",\t");
  
  //  XG_OFFSET_H_READ_OFFS_USR(Data);
    Serial.print((float)offsets[3], 2); Serial.print(",\t");
    Serial.print((float)offsets[4], 2); Serial.print(",\t");
    Serial.print((float)offsets[5], 2); Serial.print("\n\n");
}


/***********************************
**CAN BUS variables
***********************************/

MCP_CAN CAN0(5);     // Set CS pin to pin 5 of ESP32

/*Create 3 structure variables : can_output , can_input , can_motor_msg[2] */
/*With members of :
 * can_id to store CAN Id of the device
 * can_dlc to store data length in byte
 * data[8] to store the data transferred */
/*Refer to https://www.w3schools.com/cpp/cpp_structs.asp for detailed explanation in structure*/
struct can_frame {
    unsigned long   can_id;       // CAN_ID 
    byte            can_dlc;      // frame data length in byte 
    byte            data[8]={0};  // CAN_DATA 
}
can_output,         //CAN struct to store id,dlc and data for output from MCU to Speed controller
can_input,          //CAN struct to store id,dlc and data for input  from Speed controller to MCU
can_motor_msg[2];   //CAN struct to store id,dlc and data for M1 and M2


int retry,i;
int flag_motor1,flag_motor2;  //flags to indicate whether the feedback for both motor are received
char msgString[128];          //An array of char to store the msg string for printing
uint16_t feedback_M[2];


/***********************************
**PID variables
***********************************/

bool PID_completed=false;       //flag to indicate whether pid is conducted

//Define Variables and initial tuning parameters for PID
double Setpoint_M[2], Input_M[2], Output_M[2]; 
double Kp_M1=0.5, Ki_M1=0.1, Kd_M1=0.00;       //Kp,Ki,Kd for motor 1
double Kp_M2=0.5, Ki_M2=0.1, Kd_M2=0.00;       //Kp,Ki,Kd for motor 2

//Specify the links and Initiate the PID
PID PID_M1(&Input_M[0], &Output_M[0], &Setpoint_M[0], Kp_M1, Ki_M1, Kd_M1, DIRECT);
PID PID_M2(&Input_M[1], &Output_M[1], &Setpoint_M[1], Kp_M2, Ki_M2, Kd_M2, DIRECT);

/***********************************
**Keyence Line Sensor variables
***********************************/
bool line_touched_1;
bool line_touched_2;
int left_touched;
int right_touched;
bool border_touched_left = false;
bool border_touched_right = false;
int adjust_loop = 0 ;
int running_loop;


void setup()
{
  Serial.begin(115200);

/************************************************************************************************
 ** Initilizing the MPU6050
************************************************************************************************/ 
  Wire.begin(SDA, SCL, 400000);                      //initialize I2C bus for MPU 6065

  mpu.initialize();
  //mpu.setFullScaleGyroRange(MPU6050_GYRO_FS_1000); //use to set the range of gyroscope  if neccessary
  pinMode(INTERRUPT_PIN, INPUT_PULLUP);
  
  // verify connection
  Serial.println(F("Testing device connections..."));
  Serial.println(mpu.testConnection() ? F("MPU6050 connection successful") : F("MPU6050 connection failed"));
  
  devStatus = mpu.dmpInitialize();
  // make sure it worked (returns 0 if so)
  if (devStatus == 0) {
    // Calibration Time: generate offsets and calibrate our MPU6050

/************************************************************************************************
 ** Automatic Calibration:
 ** automatic tuning the offset for gyro and accelerometer using function: 
 ** "mpu.CalibrateAccel()" and "mpu.CalibrateGyro()" .
 ** number inside the bracket indicate the number of loop for tuning.
 ** The larger the number, the more accurate the gyroscope and accelerometer.
 ** The larger the number, the longer the time it takes to calibrate.
************************************************************************************************/ 
    mpu.CalibrateAccel(80);  // 
    mpu.CalibrateGyro(80);   // 

/************************************************************************************************
 ** Manual Calibration:
 ** manual tuning the offset for gyro and accelerometer, not neccessary if it is auto calibrated
************************************************************************************************/ 
//  supply your own gyro and accelermeter offsets here, scaled for min sensitivity
//  mpu.setXGyroOffset(-31.00);
//  mpu.setYGyroOffset(-6.00);
//  mpu.setZGyroOffset(24.00);
//  mpu.setXAccelOffset(564.00); 
//  mpu.setYAccelOffset(-1287.00);
//  mpu.setZAccelOffset(-550.00);

    mpu.GetActiveOffsets();
    PrintActiveOffsets();
    
    // turn on the DMP, now that it's ready
    Serial.println(F("Enabling DMP..."));
    mpu.setDMPEnabled(true);
    
    // enable Arduino interrupt detection
    Serial.print(F("Enabling interrupt detection (Arduino external interrupt "));
    Serial.print(digitalPinToInterrupt(INTERRUPT_PIN));
    Serial.println(F(")..."));
    attachInterrupt(digitalPinToInterrupt(INTERRUPT_PIN), dmpDataReady, RISING);
    mpuIntStatus = mpu.getIntStatus();
    
    // set our DMP Ready flag so the main loop() function knows it's okay to use it
    Serial.println(F("DMP ready! Waiting for first interrupt..."));
    dmpReady = true;
    // get expected DMP packet size for later comparison
    packetSize = mpu.dmpGetFIFOPacketSize();
    } 
    else 
    {
      // ERROR!
      // 1 = initial memory load failed
      // 2 = DMP configuration updates failed
      // (if it's going to break, usually the code will be 1)
        Serial.print(F("DMP Initialization failed (code "));
        Serial.print(devStatus);
        Serial.println(F(")"));
    }

/************************************************************************************************
 ** Initilizing the MCP2515 (CAN BUS)
************************************************************************************************/ 
  // Initialize MCP2515 running at 8MHz with a baudrate of 1Mb/s and the masks and filters disabled.
  if(CAN0.begin(MCP_ANY, CAN_1000KBPS,MCP_8MHZ) == CAN_OK) Serial.println("MCP2515 Initialized Successfully!");
  else Serial.println("Error Initializing MCP2515...");

  CAN0.setMode(MCP_NORMAL);   // Change to normal mode to allow messages to be transmitted
  can_output.can_id = 0x200;
  can_output.can_dlc = 8;

/************************************************************************************************
 ** Initilizing the PID
************************************************************************************************/ 
  //Initial values for PID
  Input_M[0] = Input_M[1] = 0;
  Setpoint_M[0]= OPTIMUM_SPEED_M1 ; //RPM
  Setpoint_M[1]= OPTIMUM_SPEED_M2 ; //RPM
  
  //turn the PID on
  PID_M1.SetMode(AUTOMATIC);
  PID_M1.SetOutputLimits(MIN_CURRENT_M1, MAX_CURRENT_M1);
  PID_M2.SetMode(AUTOMATIC);
  PID_M2.SetOutputLimits(MIN_CURRENT_M2, MAX_CURRENT_M2);

/************************************************************************************************
 ** Initilizing the Keyence Line Sensor
************************************************************************************************/ 
  pinMode(LINE_SENSOR_1, INPUT_PULLUP);
  pinMode(LINE_SENSOR_2, INPUT_PULLUP);
  pinMode(2, OUTPUT);
  
}

void loop()
{
  // if programming for MPU 6065 failed, don't try to do anything
  if (!dmpReady) return;
    
/****************************************************************************************
** Obtain feedback from both motor:
** retry is needed because the CAN message from both motor may arrive in the same time, 
** resulting only the data that has higher priority(smaller ID) to be accepted. 
****************************************************************************************/
  retry = 0;
  flag_motor1 = flag_motor2 = 0;
  while(retry<20){
    CAN0.readMsgBuf(&can_input.can_id, &can_input.can_dlc, can_input.data);      // Read data: len = data length, buf = data byte(s)
    switch(can_input.can_id){
      case 0x201:
      {
        can_motor_msg[0]=can_input;
        feedback_M[0] = (unsigned int) can_input.data[3]|(can_input.data[2]<<8);
        flag_motor1 = 1;
        break;
      }
      case 0x202:
      {
        can_motor_msg[1]=can_input;
        feedback_M[1] = (unsigned int)  can_input.data[3]|(can_input.data[2]<<8);
        flag_motor2 = 1;
        break;
      }
    }
    if(flag_motor1&&flag_motor2)
      break;
    else
      retry++;
  }

  Input_M[0]= feedback_M[0];  
  feedback_M[1]=(~feedback_M[1])+1;      //double compliments the feedback from motor 2 because of reverse direction
  Input_M[1]=feedback_M[1];
  
  for(i=0;i<2;i++)
  {
    sprintf(msgString, "Standard ID: 0x%.3lX       DLC: %1d  Speed Now(RPM): ", can_motor_msg[i].can_id, can_motor_msg[i].can_dlc);
    Serial.print(msgString);
    Serial.println(feedback_M[i]);
  }  

/*Only start the line sensor after the number of LOOP_BEFORE_START_SENSOR to avoid scanning the white starting line*/
  if(running_loop > LOOP_BEFORE_START_SENSOR)
  {
  line_touched_1 = digitalRead(LINE_SENSOR_1);
  line_touched_2 = digitalRead(LINE_SENSOR_2);
  Serial.print(" line touched :");
  Serial.print(" left :");
  Serial.print(line_touched_1);;
  Serial.print(" right :");
  Serial.println(line_touched_2);

  /*check whether the robot touched the line border */
  if(border_touched_left==false && border_touched_right==false)
  {
  if( line_touched_1 == false) 
  {
    total_yaw_angle = LEFT_ADJUSTMENT_ANGLE;
    turned_left = true;
    turned_right = false;
    border_touched_left = true;
    adjust_loop = ADJUSTMENT_LOOP;
    Serial.println(" left touched.");    
  }
  
  if (line_touched_2 == false) 
  {
    total_yaw_angle = RIGHT_ADJUSTMENT_ANGLE;
    turned_right = true;
    turned_left = false;
    border_touched_right = true;
    adjust_loop = ADJUSTMENT_LOOP;
    Serial.println(" right touched ");
  }
  }
  }

  /* Use the MPU6050 to check the yaw angle if robot is not touching the line border*/
  if(border_touched_left==false && border_touched_right==false)
  {
  if (mpu.dmpGetCurrentFIFOPacket(fifoBuffer)) { // Get the Latest packet 
    // display Euler angles in degrees
            mpu.dmpGetQuaternion(&q, fifoBuffer);
            mpu.dmpGetGravity(&gravity, &q);
            mpu.dmpGetYawPitchRoll(ypr, &q, &gravity);
            Serial.print("ypr\t");
            Serial.print((ypr[0] * 180/M_PI));
            Serial.print("\t");
            Serial.print(ypr[1] * 180/M_PI);
            Serial.print("\t");
            Serial.println(ypr[2] * 180/M_PI);
   }          
   
   total_yaw_angle = ypr[0] * 180/M_PI;
   Serial.println(total_yaw_angle);

  /* Check whether the yaw angle had divert from the maximum allowable angle */
  if(total_yaw_angle<0 && (turned_left==false));
  {
    turned_right=false;
  if(total_yaw_angle<LEFT_MAXIMUM_yaw_angle)
    {
      turned_left=true;
    }
  }
  
  if(total_yaw_angle>0 && (turned_right==false))
  {
    turned_left=false;
  if(total_yaw_angle>RIGHT_MAXIMUM_yaw_angle)
    {
      turned_right=true;
    }
  }
  }

/*Change the Setpoint of speed for PID in the robot based on the yaw angle if the robot had diverted*/
  if(turned_left||turned_right)
  {
    spd_chg = total_yaw_angle * SPD_CHG_PER_DEG;
    Setpoint_M[0]=OPTIMUM_SPEED_M1 + spd_chg;
    Setpoint_M[1]=OPTIMUM_SPEED_M2 - spd_chg;
  }
  else{
      Setpoint_M[0]=OPTIMUM_SPEED_M1;
      Setpoint_M[1]=OPTIMUM_SPEED_M2;
  }

  /* Use PID to calculate the output current based on the setpoint of speed*/

  Serial.print("setpoint of motor 1 and 2 now :");
  Serial.print(Setpoint_M[0]);
  Serial.println(Setpoint_M[1]);
   PID_completed = false;
   while(PID_completed==false)
   {
     PID_completed = (PID_M1.Compute()&&PID_M2.Compute());
   }

  /* The value 400 is used as a constant to startup the motor faster, might had better solution in here */
  Output_M[1]=(-Output_M[1])-400;
  Output_M[0]=Output_M[0]+400;

  /*Send out the current output value to the motor using bit operator ">>" */
  /*Refer to here for more explanation on bitwise operators.
   * https://www.programiz.com/cpp-programming/bitwise-operators */

/************************************IMPORTANT********************************************************************
**REMEMBER TO CONVERT THE OUTPUT INTO UNSIGNED INT(OR uint16_t), BECAUSE DATA IS TRANSFERRED IN UNSIGNED 2 BYTES
*****************************************************************************************************************/
  can_output.data[0]= (unsigned int) (Output_M[0]) >> 8;
  can_output.data[1]= (unsigned int) (Output_M[0]) ;
  can_output.data[2]= (unsigned int) (Output_M[1]) >> 8;
  can_output.data[3]= (unsigned int) (Output_M[1]) ;
  
  // send data:  ID , Standard CAN Frame, Data length = 8 bytes, 'data' = array of data bytes to send
  byte sndStat = CAN0.sendMsgBuf(can_output.can_id, STANDARD_CAN_FRAME, can_output.can_dlc, can_output.data);
  if(sndStat == CAN_OK){
    Serial.println("Output NOW:");
    Serial.print (" Motor 1: ");
    Serial.println(Output_M[0],DEC);
    Serial.print (" Motor 2: ");
    Serial.println(Output_M[1],DEC);
    //Serial.println("Message Sent Successfully!");
  } else {
    Serial.println("Error Sending Message...");
  }

/* adjust_loop is used to determine the number of loop for adjustment of robot if touched the border*/
  if(adjust_loop>0)
  {
    adjust_loop--;
    if(adjust_loop <= 0)
    {
      border_touched_left = false;
      border_touched_right = false;
      left_touched = 0;
      right_touched = 0;
    }
  }
  else
  {
    border_touched_left = false;
    border_touched_right = false;
  }

  /*running_loop calculate the number of loop run by the whole program*/
  running_loop++;
  // started=true;    
}
