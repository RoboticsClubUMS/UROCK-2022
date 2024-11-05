#include "main.h"
/*
FL = FRONT LEFT = 0
FR = FRONT RIGHT = 1
RL = REAR LEFT = 2
RR = REAR RIGHT = 3
*/
// Initialization Servo

bool hasReady = false;
bool hasRealign = false;

bool isClimb = false;
bool isDescend = false;
bool isWalk = true;
String mode = "Walking";

unsigned long previousMillis = 0;
unsigned long interval = 1500;

double yaw, pitch;
double initialYaw, initialPitch; 
double differenceYaw, differencePitch;
double oldDifferenceYaw, oldDifferencePitch;

int distance;

Dog Doggo;

void setup() {
  Serial.begin(115200);

  // Setup DOG
  Doggo.setupLeg();
  Doggo.readyLeg();


  // Setup SUNX
  //setupSUNX();

  // Setup GYRO
  setupGyro();
  getInitialGyro(&initialPitch, &initialYaw);

  // Setup ULTRASONIC
  setupUS();

  // Setup LCD
  //setupLCD();

  //attachInterrupt(digitalPinToInterrupt(SUNX_PIN_1), leftTouched, CHANGE);
  //attachInterrupt(digitalPinToInterrupt(SUNX_PIN_2), rightTouched, CHANGE);
  //previousMillis = millis();
  previousMillis = millis();
}
void loop() {

  //getCurrentGyro(&pitch, &yaw);

  //differenceYaw = initialYaw - yaw;
  //differencePitch = initialPitch - pitch;
  
  if (isWalk) {
    if (millis() - previousMillis > 10000) {
      Doggo.turnLeft();
      Doggo.turnLeft();
      Doggo.turnLeft();
      Doggo.readyLeg();
      distance = getUS();
      
      previousMillis = millis();
      hasReady = false;
    }
    if (!hasReady) {
      delay(1000);
      Doggo.initialLift();
      hasReady = true;
    }

    //calculatingLCD();
    Doggo.walk();
/*
    if (millis() - previousMillis > 15000 && !hasRealign) {
      Doggo.readyLeg();
      delay(1000);
      Doggo.turnRight();
      hasRealign = true;
    }
*/

    if (distance >= 5 && distance <= 70) {
      isWalk = false;
      isClimb = true;
      mode = "Climbing";
      hasReady = false;
    }
/*
    if (left_line_touched && right_line_touched) {
      
    } else if (left_line_touched) {
      Doggo.readyLeg();
      delay(1000);
      while(left_line_touched) {
        Doggo.turnRight();
      }
    } else if (right_line_touched) {
      Doggo.readyLeg();
      delay(1000);
      while(right_line_touched) {
        Doggo.turnLeft();
      }
    }

    if (int(differenceYaw) <= -15) {
      Doggo.readyLeg();
      delay(1000);
      while (int(differenceYaw <= -10)) {
        getCurrentGyro(&pitch, &yaw);
        differenceYaw = initialYaw - yaw;    

        Doggo.turnRight();    
      }
      getCurrentGyro(&initialPitch, &initialYaw);
      hasReady = false;
    } else if (int(differenceYaw) >= 15) {
      Doggo.readyLeg();
      delay(1000);
      while(int(differenceYaw) >= 10) {
        getCurrentGyro(&pitch, &yaw);
        differenceYaw = initialYaw - yaw;

        Doggo.turnLeft();
      }
      getCurrentGyro(&initialPitch, &initialYaw);
      hasReady = false;
    }
  */
  } else if (isClimb) {
    getCurrentGyro(&pitch, &yaw);

    differenceYaw = initialYaw - yaw;
    differencePitch = initialPitch - pitch;

    if (!hasReady) {
      //liftSUNX();
      Doggo.readyLeg1();
      delay(1000);
      hasReady = true;
    }

    Doggo.climbRamp();

    if (int(differencePitch) >= 5) {
      previousMillis = millis();
      while (int(differencePitch) >= 5) {
        getCurrentGyro(&pitch, &yaw);
        differencePitch = initialPitch - pitch;
        if (millis() - previousMillis > interval) {
          isClimb = false;
          isDescend = true;
          mode = "Descending";
          hasReady = false;
          break; 
        }
        Doggo.climbRamp();
      }
    }
  } else if (isDescend) {
    getCurrentGyro(&pitch, &yaw);

    differenceYaw = initialYaw - yaw;
    differencePitch = initialPitch - pitch;
    if (!hasReady) {
      Doggo.readyLeg2();
      delay(1000);
      hasReady = true;
    }

    Doggo.downRamp();

    if (int(differencePitch) > -15 && int(differencePitch) < 5) {
      previousMillis = millis();
      while (int(differencePitch) > -15 && int(differencePitch) < 5) {
        getCurrentGyro(&pitch, &yaw);
        differencePitch = initialPitch - pitch;

        if (millis() - previousMillis > interval) {
          distance = 0;
          isDescend = false;
          isWalk = true;
          mode = "Walking";
          hasReady = false;
          break;
        }

        Doggo.downRamp();
      }
    }
  }

  //displayLCD(int(differencePitch), int(differenceYaw), distance, mode);
}

