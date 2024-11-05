#ifndef UROCKGYRO_H
#define UROCKGYRO_H

#include <ICM_20948.h>

#define SERIAL_PORT Serial
#define WIRE_PORT Wire
#define AD0_VAL 1

ICM_20948_I2C myICM;

bool initialized = false;

void setupGyro() {
	WIRE_PORT.begin();
	WIRE_PORT.setClock(400000);

	while (!initialized) {
		myICM.begin(WIRE_PORT, AD0_VAL);

    if (myICM.status != ICM_20948_Stat_Ok) {
      SERIAL_PORT.println(F("Trying again..."));
      delay(500);
    } else {
      initialized = true;
    }
  }

  bool success = true;

  success &= (myICM.initializeDMP() == ICM_20948_Stat_Ok);
  success &= (myICM.enableDMPSensor(INV_ICM20948_SENSOR_GAME_ROTATION_VECTOR) == ICM_20948_Stat_Ok);
  success &= (myICM.setDMPODRrate(DMP_ODR_Reg_Quat6, 0) == ICM_20948_Stat_Ok); // Set to the maximum

  // Enable the FIFO
  success &= (myICM.enableFIFO() == ICM_20948_Stat_Ok);

  // Enable the DMP
  success &= (myICM.enableDMP() == ICM_20948_Stat_Ok);

  // Reset DMP
  success &= (myICM.resetDMP() == ICM_20948_Stat_Ok);

  // Reset FIFO
  success &= (myICM.resetFIFO() == ICM_20948_Stat_Ok);

  // Check success
  if (success) {
    #ifndef QUAT_ANIMATION
    //SERIAL_PORT.println(F("DMP enabled!"));
    #endif
  } else {
    //SERIAL_PORT.println(F("Enable DMP failed!"));
    while (1);
  }
  
}

void getCurrentGyro(double *pitch, double *yaw)
{
	double roll;

  icm_20948_DMP_data_t data;
  myICM.readDMPdataFromFIFO(&data);
  
  if ((myICM.status == ICM_20948_Stat_Ok) || (myICM.status == ICM_20948_Stat_FIFOMoreDataAvail)) {
    while(myICM.status == ICM_20948_Stat_FIFOMoreDataAvail) {
      myICM.readDMPdataFromFIFO(&data);
    }

    if ((data.header & DMP_header_bitmap_Quat6) > 0) // We have asked for GRV data so we should receive Quat6
    {
      // Q0 value is computed from this equation: Q0^2 + Q1^2 + Q2^2 + Q3^2 = 1.
      // In case of drift, the sum will not add to 1, therefore, quaternion data need to be corrected with right bias values.
      // The quaternion data is scaled by 2^30.

      ////SERIAL_PORT.printf("Quat6 data is: Q1:%ld Q2:%ld Q3:%ld\r\n", data.Quat6.Data.Q1, data.Quat6.Data.Q2, data.Quat6.Data.Q3);

      // Scale to +/- 1
      double q1 = ((double)data.Quat6.Data.Q1) / 1073741824.0; // Convert to double. Divide by 2^30
      double q2 = ((double)data.Quat6.Data.Q2) / 1073741824.0; // Convert to double. Divide by 2^30
      double q3 = ((double)data.Quat6.Data.Q3) / 1073741824.0; // Convert to double. Divide by 2^30
      double q0 = sqrt(1.0 - ((q1 * q1) + (q2 * q2) + (q3 * q3)));
	  
      double q2sqr = q2 * q2;

      // roll (x-axis rotation)
      double t0 = +2.0 * (q0 * q1 + q2 * q3);
      double t1 = +1.0 - 2.0 * (q1 * q1 + q2sqr);
      roll = atan2(t0, t1) * 180.0 / PI;

      // pitch (y-axis rotation)
      double t2 = +2.0 * (q0 * q2 - q3 * q1);
      t2 = t2 > 1.0 ? 1.0 : t2;
      t2 = t2 < -1.0 ? -1.0 : t2;
      *pitch = asin(t2) * 180.0 / PI;

      // yaw (z-axis rotation)
      double t3 = +2.0 * (q0 * q3 + q1 * q2);
      double t4 = +1.0 - 2.0 * (q2sqr + q3 * q3);
      *yaw = atan2(t3, t4) * 180.0 / PI;
	  
    }
  }

  if (myICM.status != ICM_20948_Stat_FIFOMoreDataAvail) // If more data is available then we should read it right away - and not delay
  {
    delay(10);
  }
  
  return ;
}

void getInitialGyro(double *initial_pitch, double *initial_yaw) {
	double yaw_difference,yaw_now,yaw_prev;

  double pitch_difference, pitch_now, pitch_prev;
	unsigned long currentMillis = 0, lastPrintMillis = 0;
	//Serial.println("getting initial yaw");
  while ( *initial_yaw == 0 && *initial_yaw ==0) {
    getCurrentGyro(&pitch_now, &yaw_now);
    pitch_difference = pitch_now - pitch_prev;
    pitch_prev = pitch_now;

    yaw_difference = yaw_now - yaw_prev;
    yaw_prev = yaw_now;

      //Serial.print("Yaw_difference\t");
      //Serial.println(yaw_difference);
      //Serial.println("here ok");
    if(fabs(yaw_difference)<0.01 && fabs(pitch_difference < 0.01)) {
      *initial_pitch = pitch_now;   
		  *initial_yaw = yaw_now;
    }    
	}
}

#endif