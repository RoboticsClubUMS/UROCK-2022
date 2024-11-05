#ifndef DOG_H
#define DOG_H

#include <ESP32Servo.h>

#define SERVO_PIN_1 15
#define SERVO_PIN_2 18

#define SERVO_PIN_3 13
#define SERVO_PIN_4 14

#define SERVO_PIN_5 23
#define SERVO_PIN_6 19

#define SERVO_PIN_7 32
#define SERVO_PIN_8 33

#define SERVO_MIN_PULSE 500
#define SERVO_MAX_PULSE 2500
#define SERVO_HERTZ 50

#define ANOTHER_SPEED 18
#define HALF_SPEED 10
#define FULL_SPEED 5

int err[8] = {7, 4, 9, 11, 6, 8, 13, 6};

/*
   H_ _ _ A _ _ _B
   /             \
G /               \ C
  \               /
   \_ _ _   _ _ _/
   F      E      D


  Error
  
  Servo 1: Indicator
  Servo 2: 10
  Servo 3: 0
  Servo 4: 4
  Servo 5: 8
  Servo 6: 8
  Servo 7: 8
  Servo 8: 4

*/ 

class Dog {
  public:
    Dog() {
      speed = 6;
      hertz = SERVO_HERTZ;
      min_pulse = SERVO_MIN_PULSE;
      max_pulse = SERVO_MAX_PULSE;
    }

    void tryTest1() {
      int pos_1 = 80;
      int rev_1 = 40;

      int pos_2 = 80;
      int rev_2 = 40;

      int pos_3 = 40;
      int rev_3 = 80;

      int pos_4 = 40;
      int rev_4 = 80;

      for (pos_1; pos_1 <= 90; pos_1 += 1) {
        M1.write(pos_1 + err[0]);
        M2.write(rev_1 - err[1]);
        M7.write(pos_2 + err[6]);
        M8.write(rev_2 - err[7]);

        M3.write(pos_3 + err[2]);
        M4.write(rev_3 - err[3]);
        M5.write(pos_4 + err[4]);
        M6.write(rev_4 - err[5]);
        
        rev_1--;

        pos_2--;
        rev_2++;
        pos_3--;
        rev_3++;
        pos_4--;
        rev_4++;
        delay(speed);
      }
    }

    void trylift() {
      int pos = 80;
      int rev = 40;

      int pos_2 = 80;
      int rev_2 = 40;

      for (pos; pos >= 40; pos -= 1) {
        M5.write(pos + err[4]); 
        M6.write(rev - err[5]); 
        M3.write(pos_2 + err[2]); 
        M4.write(rev_2 - err[3]); 
        pos_2--;
        rev_2++;
        rev++;
        delay(speed);
      }
    }

    void DM1() {
      int pos = 20;
      int rev = 100;

      int pos_2 = 20;
      int rev_2 = 100;

      for (pos; pos <= 40; pos += 1) {
        M1.write(pos + err[0]);
        M2.write(rev - err[1]);
        M7.write(pos_2 + err[6]);
        M8.write(rev_2 - err[7]);
        pos_2--;
        rev_2--;
        rev++;
        delay(speed);
      }
    }

    void DM2() {
      int pos = 40;

      int rev_2 = 80;

      for (pos; pos >= 0; pos -= 1) {
        M1.write(pos + err[0]);
        M8.write(rev_2 - err[7]);
        rev_2++;
        delay(speed);
      }
    }

    void DM3() {
      int rev = 120;

      int pos_2 = 0;

      for (rev; rev >= 80; rev -= 1) {
        M2.write(rev - err[1]);
        M7.write(pos_2 + err[6]);
        pos_2++;
        delay(speed);
      }
    }

    void DM4() {
      int pos = 0;
      int rev = 80;

      int pos_2 = 40;
      int rev_2 = 120;
      for (pos; pos <= 20; pos += 1) {
        M1.write(pos + err[0]);
        M2.write(rev - err[1]);
        M7.write(pos_2 + err[6]);
        M8.write(rev_2 - err[7]);
        pos_2--;
        rev_2--;
        rev++;
        delay(speed);
      }
    }

    void DM11() {
      int pos = 20;
      int rev = 100;

      int pos_2 = 20;
      int rev_2 = 100;

      for (pos; pos <= 40; pos += 1) {
        M5.write(pos + err[4]);
        M6.write(rev - err[5]);
        M3.write(pos_2 + err[2]);
        M4.write(rev_2 - err[3]);
        pos_2--;
        rev_2--;
        rev++;
        delay(speed);
      }
    }

    void DM22() {
      int pos = 40;

      int rev_2 = 80;

      for (pos; pos >= 0; pos -= 1) {
        M5.write(pos + err[4]);
        M4.write(rev_2 - err[3]);
        rev_2++;
        delay(speed);
      }
    }

    void DM33() {
      int rev = 120;
      int pos_2 = 0;

      for (rev; rev >= 80; rev -= 1) {
        M6.write(rev - err[5]);
        M3.write(pos_2 + err[2]);
        pos_2++;
        delay(speed);
      }
    }

    void DM44() {
      int pos = 0;
      int rev = 80;

      int pos_2 = 40;
      int rev_2 = 120;
      for (pos; pos <= 20; pos += 1) {
        M5.write(pos + err[4]);
        M6.write(rev - err[5]);
        M3.write(pos_2 + err[2]);
        M4.write(rev_2 - err[3]);
        pos_2--;
        rev_2--;
        rev++;
        delay(speed);
      }   
    }

    void setupLeg() {
      M1.setPeriodHertz(hertz);
      M2.setPeriodHertz(hertz);
      M3.setPeriodHertz(hertz);
      M4.setPeriodHertz(hertz);
      M5.setPeriodHertz(hertz);
      M6.setPeriodHertz(hertz);
      M7.setPeriodHertz(hertz);
      M8.setPeriodHertz(hertz);

      M1.attach(SERVO_PIN_1, SERVO_MIN_PULSE, SERVO_MAX_PULSE);
      M2.attach(SERVO_PIN_2, SERVO_MIN_PULSE, SERVO_MAX_PULSE);
      M3.attach(SERVO_PIN_3, SERVO_MIN_PULSE, SERVO_MAX_PULSE);
      M4.attach(SERVO_PIN_4, SERVO_MIN_PULSE, SERVO_MAX_PULSE);
      M5.attach(SERVO_PIN_5, SERVO_MIN_PULSE, SERVO_MAX_PULSE);
      M6.attach(SERVO_PIN_6, SERVO_MIN_PULSE, SERVO_MAX_PULSE);
      M7.attach(SERVO_PIN_7, SERVO_MIN_PULSE, SERVO_MAX_PULSE);
      M8.attach(SERVO_PIN_8, SERVO_MIN_PULSE, SERVO_MAX_PULSE);
    }
    void downRamp() {
      liftBigFourthLeg();
  
      liftFirstLeg1();
      pushFirstLeg1();
      dropFirstLeg1();

      dropBigFourthLeg();
      liftBigThirdLeg();

      liftSecondLeg1();
      pushSecondLeg1();
      dropSecondLeg1();

      dropBigThirdLeg();

      allForward3();

      liftFrontLeg1();

      liftThirdLeg1();
      delay(200);
      dropThirdLeg1();

      liftFourthLeg1();
      delay(200);
      dropFourthLeg1();

      dropFrontLeg1();      
      delay(200);
    }

    void turnLeft() {
      idk3();
      idk4();
    }

    void turnRight() {
      idk1();
      idk2();
    }

    void climbRamp() {
      liftSmallFourthLeg();
  
      liftFirstLeg();
      pushFirstLeg();
      dropFirstLeg();
      delay(500);
      dropSmallFourthLeg();
      liftSmallThirdLeg();
      
      liftSecondLeg();
      pushSecondLeg();
      dropSecondLeg();

      dropSmallThirdLeg();
      delay(500);
      allForward2();
      delay(200);

      //liftFrontLeg();

      liftThirdLeg();
      delay(200);
      //pushThirdLegA();
      dropThirdLeg();
      delay(200);

      liftFourthLeg();
      delay(200);
      //pushFourthLegA();
      dropFourthLeg();
      delay(200);

      //dropFrontLeg();

    }

    void idk1() {
      int pos_1 = 50;
      int rev_1 = 70;
      int pos = 30;
      int rev = 90;

      for (pos_1; pos_1 >= 30; pos_1 -= 1) {
        M3.write(pos_1 + err[2]);
        M4.write(rev_1 - err[3]);
        M5.write(pos_1 + err[4]);
        M6.write(rev_1 - err[5]);

        M1.write(pos + err[0]);
        M2.write(rev - err[1]);
        M7.write(pos + err[6]);
        M8.write(rev - err[7]);

        rev_1++;
        rev--;
        pos--;
        delay(speed);
      }
    }

    void idk2() {      
      int pos_1 = 50;
      int rev_1 = 70;
      int pos = 30;
      int rev = 90;

      for (pos_1; pos_1 >= 30; pos_1 -= 1) {
        M1.write(pos_1 + err[0]);
        M2.write(rev_1 - err[1]);
        M7.write(pos_1 + err[6]);
        M8.write(rev_1 - err[7]);

        M3.write(pos + err[2]);
        M4.write(rev - err[3]);
        M5.write(pos + err[4]);
        M6.write(rev - err[5]);

        rev_1++;
        rev--;
        pos--;
        delay(speed);
      }
    }

    void idk3() {
      int pos_1 = 50;
      int rev_1 = 70;
      int pos = 30;
      int rev = 90;

      for (pos_1; pos_1 >= 30; pos_1 -= 1) {
        M3.write(pos_1 + err[2]);
        M4.write(rev_1 - err[3]);
        M5.write(pos_1 + err[4]);
        M6.write(rev_1 - err[5]);

        M1.write(pos + err[0]);
        M2.write(rev - err[1]);
        M7.write(pos + err[6]);
        M8.write(rev - err[7]);

        rev_1++;
        rev++;
        pos++;
        delay(speed);
      }
    }

    void idk4() {      
      int pos_1 = 50;
      int rev_1 = 70;
      int pos = 30;
      int rev = 90;

      for (pos_1; pos_1 >= 30; pos_1 -= 1) {
        M1.write(pos_1 + err[0]);
        M2.write(rev_1 - err[1]);
        M7.write(pos_1 + err[6]);
        M8.write(rev_1 - err[7]);

        M3.write(pos + err[2]);
        M4.write(rev - err[3]);
        M5.write(pos + err[4]);
        M6.write(rev - err[5]);

        rev_1++;
        rev++;
        pos++;
        delay(speed);
      }
    }
    void walk() {

      EDM13();
      EDM24();
      EDM31();
      EDM42();
    }

    void seqOne() {
      CL4DECINC(50, 40, 70, 80);
      CL4INC(40, 50, 80, 90);
      CL4INCDEC(50, 60, 90, 80);
      delay(500);      
      CL2DECINC(50, 40, 70, 80);
      CL2INC(40, 50, 80, 90);
      CL2INCDEC(50, 60, 90, 80);
      delay(500);
      CL3DECINC(50, 40, 70, 80);
      CL3DEC(40, 30, 80, 70);
      CL3INCDEC(30, 40, 70, 60);
      delay(500);
      CL1DECINC(50, 40, 70, 80);
      CL1DEC(40, 30, 80, 70);
      CL1INCDECSP(30, 40, 70, 60, 60, 80, 40, 60);
      delay(500);
    }

    void seqTwo() {
      CL4DECINC(50, 40, 70, 80);
      CL4INC(40, 50, 80, 90);
      CL4INCDEC(50, 60, 90, 80);
      delay(500);      
      CL2DECINC(50, 40, 70, 80);
      CL2INC(40, 50, 80, 90);
      CL2INCDEC(50, 60, 90, 80);
      delay(500);
      CL3DECINC(50, 40, 70, 80);
      CL3DEC(40, 30, 80, 70);
      CL3INCDECSP(30, 40, 70, 60, 60, 80, 40, 60);
      delay(500); 
    }

    void seqThree() {
      CL1DECINC(50, 40, 70, 80);
      CL1DEC(40, 30, 80, 70);
      CL1INCDEC(30, 40, 70, 60);
      delay(500);   
      CL4DECINC(50, 40, 70, 80);
      CL4INC(40, 50, 80, 90);
      CL4INCDEC(50, 60, 90, 80);
      delay(500);
      CL2DECINC(50, 40, 70, 80);
      CL2INC(40, 50, 80, 90);
      CL2INCDECSP(50, 60, 90, 80, 60, 80, 40, 60);
      delay(500);
    }

    void seqFour() {
      CL3DECINC(50, 40, 70, 80);
      CL3DEC(40, 30, 80, 70);
      CL3INCDEC(30, 40, 70, 60);
      delay(500);
      CL1DECINC(50, 40, 70, 80);
      CL1DEC(40, 30, 80, 70);
      CL1INCDEC(30, 40, 70, 60);
      delay(500);
      CL4INCDECSP(50, 60, 90, 80, 40, 60, 60, 80); 
    }
    void readyLeg3() {
      int pos = 0;
      int rev = 120;

      for (pos; pos <= 80; pos += 1) {
        M1.write(pos + err[0]);
        M2.write(rev - err[1]);
        M3.write(pos + err[2]);
        M4.write(rev - err[3]);
        M5.write(pos + err[4]);
        M6.write(rev - err[5]);
        M7.write(pos + err[6]);
        M8.write(rev - err[7]);
        delay(1);
        rev--;
      }
    }
    void readyLeg() {
      int pos = 0;
      int rev = 120;

      for (pos; pos <= 50; pos += 1) {
        M1.write(pos + err[0]);
        M2.write(rev - err[1]);
        M3.write(pos + err[2]);
        M4.write(rev - err[3]);
        M5.write(pos + err[4]);
        M6.write(rev - err[5]);
        M7.write(pos + err[6]);
        M8.write(rev - err[7]);
        delay(1);
        rev--;
      }
    }

    void readyLeg1() {
      int pos = 0;
      int rev = 120;

      int pos_1 = 0;
      int rev_1 = 120;

      int pos_2 = 0;
      int rev_2 = 120;

      for (pos_1; pos_1 <= 80; pos_1 += 1) {
        if (pos <= 50) {
          M1.write(pos + err[0]);
          M2.write(rev - err[1]);
          M3.write(pos + err[2]);
          M4.write(rev - err[3]);
        }

        M5.write(pos_1 + err[4]);

        M8.write(rev_2 - err[7]);          
        if (rev_1 >= 80) {
          M7.write(pos_2 + err[6]);
          M6.write(rev_1 - err[5]);
        }
        
        delay(1);
        pos++;
        rev--;

        rev_1--;

        pos_2++;
        rev_2--;
      }
    }

    void readyLeg2() {
      int pos = 0;
      int rev = 120;

      int pos_1 = 0;
      int rev_1 = 120;

      int pos_2 = 0;
      int rev_2 = 120;

      for (pos_1; pos_1 <= 60; pos_1 += 1) {

        if (pos_2 <= 40) {
          M1.write(pos_2 + err[0]);
          M4.write(rev_1 - err[3]);
          pos_2++;
          rev_1--;
        }

        M2.write(rev_2 - err[1]);
        M3.write(pos_1 + err[2]);

        if (pos <= 40) {
          M5.write(pos + err[4]);
          M6.write(rev - err[5]);
          M7.write(pos + err[6]);
          M8.write(rev - err[7]);   
          pos++;
          rev--;
        }
               
        rev_2--;
        delay(1);
      }
    }

    void initialLift() {

      int pos = 50;
      int rev = 70;

      int pos_2 = 50;
      int rev_2 = 70;

      for (pos_2; pos_2 >= 30; pos_2 -= 1) {
        M3.write(pos_2 + err[2]); // 50
        M4.write(rev_2 - err[3]); // 110
        M5.write(pos + err[4]); // 10
        M6.write(rev - err[5]); // 70
        rev_2++;
        pos--;
        rev++;
        delay(speed);
      }
    }

    void EDM13A() {
      int pos = 50;
      int rev = 70;

      int pos_2 = 50;
      int rev_2 = 70;
      
      int rev_3 = 80;
      int pos_4 = 40;

      for (rev_3; rev_3 >= 60; rev_3 -= 1) {
        if (pos <= 60) {
          M1.write(pos + err[0]);
          M2.write(rev - err[1]);
          M7.write(pos_2 + err[6]);
          M8.write(rev_2 - err[7]);
        }
        M6.write(rev_3 - err[5]);
        M3.write(pos_4 + err[2]);

        pos++;
        rev++;
        pos_2--;
        rev_2--;
        pos_4++;
        delay(speed);
      }  
    }

    void CL1INC(int pos, int posTarget, int rev, int revTarget) {
      for (pos; pos <= posTarget; pos++) {
        M1.write(pos + err[0]);
        M2.write(rev - err[1]);
        rev++;
        delay(speed);
      }
    }

    void CL1DEC(int pos, int posTarget, int rev, int revTarget) {
      for (pos; pos >= posTarget; pos--) {
        M1.write(pos + err[0]);
        M2.write(rev - err[1]);
        rev--;
        delay(speed);
      }
    }

    void CL1INCDEC(int pos, int posTarget, int rev, int revTarget) {
      for (pos; pos <= posTarget; pos++) {
        M1.write(pos + err[0]);
        M2.write(rev - err[1]);
        rev--;
        delay(speed);
      }
    }

    void CL1INCDECSP(int pos, int posTarget, int rev, int revTarget, int pos_1, int rev_1, int pos_2, int rev_2) {
      for (pos; pos <= posTarget; pos++) {
        M1.write(pos + err[0]);
        M2.write(rev - err[1]);
        M3.write(pos_1 + err[2]);
        M4.write(rev_1 - err[3]);
        M5.write(pos_2 + err[4]);
        M6.write(rev_2 - err[5]);
        M7.write(pos_1 + err[6]);
        M8.write(rev_1 - err[7]);
        pos_1--;
        rev_1--;
        pos_2++;
        rev_2++;
        rev--;
        delay(speed);
      }
    }

    void CL3INCDECSP(int pos, int posTarget, int rev, int revTarget, int pos_1, int rev_1, int pos_2, int rev_2) {
      for (pos; pos <= posTarget; pos++) {
        M1.write(pos_2 + err[0]);
        M2.write(rev_2 - err[1]);
        M3.write(pos_1 + err[2]);
        M4.write(rev_1 - err[3]);
        M5.write(pos + err[4]);
        M6.write(rev - err[5]);
        M7.write(pos_1 + err[6]);
        M8.write(rev_1 - err[7]);
        pos_1--;
        rev_1--;
        pos_2++;
        rev_2++;
        rev--;
        delay(speed);
      }
    }

    void CL2INCDECSP(int pos, int posTarget, int rev, int revTarget, int pos_1, int rev_1, int pos_2, int rev_2) {
      for (pos; pos <= posTarget; pos++) {
        M1.write(pos_2 + err[0]);
        M2.write(rev_2 - err[1]);
        M3.write(pos + err[2]);
        M4.write(rev - err[3]);
        M5.write(pos_1 + err[4]);
        M6.write(rev_1 - err[5]);
        M7.write(pos_1 + err[6]);
        M8.write(rev_1 - err[7]);
        pos_1--;
        rev_1--;
        pos_2++;
        rev_2++;
        rev--;
        delay(speed);
      }
    }

    void CL4INCDECSP(int pos, int posTarget, int rev, int revTarget, int pos_1, int rev_1, int pos_2, int rev_2) {
      for (pos; pos <= posTarget; pos++) {
        M1.write(pos_1 + err[0]);
        M2.write(rev_1 - err[1]);
        M3.write(pos_2 + err[2]);
        M4.write(rev_2 - err[3]);
        M5.write(pos_1 + err[4]);
        M6.write(rev_1 - err[5]);
        //M7.write(pos + err[6]);
        //M8.write(rev - err[7]);
        pos_1++;
        rev_1++;
        pos_2--;
        rev_2--;
        rev--;
        delay(speed);
      }
    }

    void CL1DECINC(int pos, int posTarget, int rev, int revTarget) {
      for (pos; pos >= posTarget; pos--) {
        M1.write(pos + err[0]);
        M2.write(rev - err[1]);
        rev++;
        delay(speed);
      }
    }        

    void CL2INC(int pos, int posTarget, int rev, int revTarget) {
      for (pos; pos <= posTarget; pos++) {
        M3.write(pos + err[2]);
        M4.write(rev - err[3]);
        rev++;
        delay(speed);
      }
    }

    void CL2DEC(int pos, int posTarget, int rev, int revTarget) {
      for (pos; pos >= posTarget; pos--) {
        M3.write(pos + err[2]);
        M4.write(rev - err[3]);
        rev--;
        delay(speed);
      }
    }

    void CL2INCDEC(int pos, int posTarget, int rev, int revTarget) {
      for (pos; pos <= posTarget; pos++) {
        M3.write(pos + err[2]);
        M4.write(rev - err[3]);
        rev--;
        delay(speed);
      }
    }

    void CL2DECINC(int pos, int posTarget, int rev, int revTarget) {
      for (pos; pos >= posTarget; pos--) {
        M3.write(pos + err[2]);
        M4.write(rev - err[3]);
        rev++;
        delay(speed);
      }
    }

    void CL3INC(int pos, int posTarget, int rev, int revTarget) {
      for (pos; pos <= posTarget; pos++) {
        M5.write(pos + err[4]);
        M6.write(rev - err[5]);
        rev++;
        delay(speed);
      }
    }

    void CL3DEC(int pos, int posTarget, int rev, int revTarget) {
      for (pos; pos >= posTarget; pos--) {
        M5.write(pos + err[4]);
        M6.write(rev - err[5]);
        rev--;
        delay(speed);
      }
    }

    void CL3INCDEC(int pos, int posTarget, int rev, int revTarget) {
      for (pos; pos <= posTarget; pos++) {
        M5.write(pos + err[4]);
        M6.write(rev - err[5]);
        rev--;
        delay(speed);
      }
    }

    void CL3DECINC(int pos, int posTarget, int rev, int revTarget) {
      for (pos; pos >= posTarget; pos--) {
        M5.write(pos + err[4]);
        M6.write(rev - err[5]);
        rev++;
        delay(speed);
      }
    }

    void CL4INC(int pos, int posTarget, int rev, int revTarget) {
      for (pos; pos <= posTarget; pos++) {
        M7.write(pos + err[6]);
        M8.write(rev - err[7]);
        rev++;
        delay(speed);
      }
    }

    void CL4DEC(int pos, int posTarget, int rev, int revTarget) {
      for (pos; pos >= posTarget; pos--) {
        M7.write(pos + err[6]);
        M8.write(rev - err[7]);
        rev--;
        delay(speed);
      }
    }

    void CL4INCDEC(int pos, int posTarget, int rev, int revTarget) {
      for (pos; pos <= posTarget; pos++) {
        M7.write(pos + err[6]);
        M8.write(rev - err[7]);
        rev--;
        delay(speed);
      }
    }

    void CL4DECINC(int pos, int posTarget, int rev, int revTarget) {
      for (pos; pos >= posTarget; pos--) {
        M7.write(pos + err[6]);
        M8.write(rev - err[7]);
        rev++;
        delay(speed);
      }
    }

    void EDM24A() {

      int pos = 30;
      int rev = 50;

      int pos_2 = 70;
      int rev_2 = 90;

      int pos_3 = 70;
      int rev_4 = 50;

      for (pos_3; pos_3 >= 30; pos_3 -= 1) {
        if (pos <= 50) {
          M5.write(pos + err[4]);
          M6.write(rev - err[5]);
          M3.write(pos_2 + err[2]);
          M4.write(rev_2 - err[3]);
        }
        M1.write(pos_3 + err[0]);
        M8.write(rev_4 - err[7]);
        pos++;
        rev++;
        pos_2--;
        rev_2--;
        rev_4++;
        delay(speed);
      }    
    }

    void EDM31A() {
      int pos = 50;
      int rev = 70;

      int pos_2 = 50;
      int rev_2 = 70;

      int rev_3 = 90;
      int pos_4 = 30;

      for (rev_3; rev_3 >= 50; rev_3 -= 1) {
        if (pos <= 70) {
          M5.write(pos + err[4]);
          M6.write(rev - err[5]);
          M3.write(pos_2 + err[2]);
          M4.write(rev_2 - err[3]);
        }
        M2.write(rev_3 - err[1]);
        M7.write(pos_4 + err[6]);
        pos++;
        rev++;
        pos_2--;
        rev_2--;
        pos_4++;
        delay(speed);
      }    
    }

    void EDM42A() {
      int pos = 30;
      int rev = 50;

      int pos_2 = 70;
      int rev_2 = 90;

      int pos_3 = 70;
      int rev_4 = 50;

      for (pos_3; pos_3 >= 30; pos_3 -= 1) {
        if (pos <= 50) {
          M1.write(pos + err[0]);
          M2.write(rev - err[1]);
          M7.write(pos_2 + err[6]);
          M8.write(rev_2 - err[7]);
        }
        M5.write(pos_3 + err[4]);
        M4.write(rev_4 - err[3]);
        pos++;
        rev++;
        pos_2--;
        rev_2--;
        rev_4++;
        delay(speed);
      }   
    }

    void EDM13B() {
      int pos = 50;
      int rev = 70;

      int pos_2 = 50;
      int rev_2 = 70;
      
      int rev_3 = 90;
      int pos_4 = 30;

      for (pos_4; pos_4 <= 70; pos_4 += 1) {
        if (pos <= 70) {
          M1.write(pos + err[0]);
          M2.write(rev - err[1]);
          M7.write(pos_2 + err[6]);
          M8.write(rev_2 - err[7]);
        }
        M3.write(pos_4 + err[2]);        
        //M6.write(rev_3 - err[5]);


        pos++;
        rev++;
        pos_2--;
        rev_2--;
  
        delay(speed);
      }  
    }

    void EDM24B() {

      int pos = 30;
      int rev = 50;

      int pos_2 = 70;
      int rev_2 = 90;

      int pos_3 = 70;
      int rev_4 = 50;

      for (pos_3; pos_3 >= 30; pos_3 -= 1) {
        if (pos_2 >= 50) {
          M3.write(pos_2 + err[2]);
          M4.write(rev_2 - err[3]);
          //M5.write(pos + err[4]);
          //M6.write(rev - err[5]);
        }
        M1.write(pos_3 + err[0]);
        M8.write(rev_4 - err[7]);
        pos++;
        rev++;
        pos_2--;
        rev_2--;
        rev_4++;
        delay(speed);
      }    
    }

    void EDM13() {
      int pos = 50;
      int rev = 70;

      int pos_2 = 50;
      int rev_2 = 70;
      
      int rev_3 = 90;
      int pos_4 = 30;

      for (rev_3; rev_3 >= 50; rev_3 -= 1) {
        if (pos <= 70) {
          M1.write(pos + err[0]);
          M2.write(rev - err[1]);
          M7.write(pos_2 + err[6]);
          M8.write(rev_2 - err[7]);
        }
        M3.write(pos_4 + err[2]);        
        M6.write(rev_3 - err[5]);
        pos++;
        rev++;
        pos_2--;
        rev_2--;
        pos_4++;
        delay(speed);
      }  
    }

    void EDM24() {

      int pos = 30;
      int rev = 50;

      int pos_2 = 70;
      int rev_2 = 90;

      int pos_3 = 70;
      int rev_4 = 50;

      for (pos_3; pos_3 >= 30; pos_3 -= 1) {
        if (pos <= 50) {
          M3.write(pos_2 + err[2]);
          M4.write(rev_2 - err[3]);
          M5.write(pos + err[4]);
          M6.write(rev - err[5]);
        }
        M1.write(pos_3 + err[0]);
        M8.write(rev_4 - err[7]);
        pos++;
        rev++;
        pos_2--;
        rev_2--;
        rev_4++;
        delay(speed);
      }    
    }

    void EDM31() {
      int pos = 50;
      int rev = 70;

      int pos_2 = 50;
      int rev_2 = 70;

      int rev_3 = 90;
      int pos_4 = 30;

      for (rev_3; rev_3 >= 50; rev_3 -= 1) {
        if (pos <= 70) {
          M3.write(pos_2 + err[2]);
          M4.write(rev_2 - err[3]);          
          M5.write(pos + err[4]);
          M6.write(rev - err[5]);
        }
        M2.write(rev_3 - err[1]);
        M7.write(pos_4 + err[6]);
        pos++;
        rev++;
        pos_2--;
        rev_2--;
        pos_4++;
        delay(speed);
      }    
    }

    void EDM42() {
      int pos = 30;
      int rev = 50;

      int pos_2 = 70;
      int rev_2 = 90;

      int pos_3 = 70;
      int rev_4 = 50;

      for (pos_3; pos_3 >= 30; pos_3 -= 1) {
        if (pos <= 50) {
          M1.write(pos + err[0]);
          M2.write(rev - err[1]);
          M7.write(pos_2 + err[6]);
          M8.write(rev_2 - err[7]);
        }
        M4.write(rev_4 - err[3]);
        M5.write(pos_3 + err[4]);
        pos++;
        rev++;
        pos_2--;
        rev_2--;
        rev_4++;
        delay(speed);
      }   
    }

    void liftBigFourthLeg() {
      int pos = 40;
      int rev = 80;

      for (pos; pos >= 30; pos -= 1) {
        M7.write(pos + err[6]);
        M8.write(rev - err[7]);
        rev++;
        delay(speed);
      }
    }

    void liftFirstLeg1() {
      int pos = 40;
      int rev = 60;

      for (pos; pos >= 20; pos -= 1) {
        M1.write(pos + err[0]);
        M2.write(rev - err[1]);
        rev++;
        delay(speed);
      }
    }

    void pushFirstLeg1() {
      int pos = 20;
      int rev = 80;

      for (pos; pos >= 0; pos -= 1) {
        M1.write(pos + err[0]);
        M2.write(rev - err[1]);
        rev--;
        delay(speed);
      }
    }

    void dropFirstLeg1() {
      int pos = 0;
      int rev = 60;

      for (pos; pos <= 20; pos += 1) {
        M1.write(pos + err[0]);
        M2.write(rev - err[1]);
        rev--;
        delay(speed);
      }
    }

    void dropBigFourthLeg() {
      int pos = 30;
      int rev = 90;

      for (pos; pos <= 40; pos += 1) {
        M7.write(pos + err[6]);
        M8.write(rev - err[7]);
        rev--;
        delay(speed);
      }
    }

    void liftBigThirdLeg() {
      int pos = 40;
      int rev = 80;

      for (pos; pos >= 30; pos -= 1) {
        M5.write(pos + err[4]);
        M6.write(rev - err[5]);
        rev++;
        delay(speed);
      }
    }

    void liftSecondLeg1() {
      int pos = 60;
      int rev = 80;

      for (pos; pos >= 40; pos -= 1) {
        M3.write(pos + err[2]);
        M4.write(rev - err[3]);
        rev++;
        delay(speed);
      }
    }

    void pushSecondLeg1() {
      int pos = 40;
      int rev = 100;
      for (pos; pos <= 60; pos += 1) {
        M3.write(pos + err[2]);
        M4.write(rev - err[3]);
        rev++;
        delay(speed);
      }
    } 

    void dropSecondLeg1() {
      int pos = 60;
      int rev = 120;
      for (pos; pos <= 80; pos += 1) {
        M3.write(pos + err[2]);
        M4.write(rev - err[3]);
        rev--;
        delay(speed);
      }
    }

    void dropBigThirdLeg() {
      int pos = 30;
      int rev = 90;

      for (pos; pos <= 40; pos += 1) {
        M5.write(pos + err[4]);
        M6.write(rev - err[5]);
        rev--;
        delay(speed);
      }
    }

    void allForward() {
      int pos = 20;
      int rev = 40;

      int pos_1 = 80;
      int rev_1 = 100;

      for (pos; pos <= 50; pos += 1) {
        M1.write(pos + err[0]);
        M2.write(rev - err[1]);
        M3.write(pos_1 + err[2]);
        M4.write(rev_1 - err[3]);
        M5.write(pos + err[4]);
        M6.write(rev - err[5]);
        M7.write(pos_1 + err[6]);
        M8.write(rev_1 - err[7]);
        rev++;
        pos_1--;
        rev_1--;

        delay(speed);
      }
    }

    void allForward3() {
      int pos = 20;
      int rev = 40;
      
      int pos_2 = 80;
      int rev_2 = 100;

      int pos_3 = 40;
      int rev_3 = 80;

      int pos_4 = 40;
      int rev_4 = 80;

      for (pos_3; pos_3 <= 50; pos_3 += 1) {
        M1.write(pos + err[0]);
        M2.write(rev - err[1]);

        pos++;
        rev++;

        M3.write(pos_2 + err[2]);
        M4.write(rev_2 - err[3]);

        pos_2--;
        rev_2--;

        M5.write(pos_3 + err[4]);
        M6.write(rev_3 - err[5]);
      
        rev_3++;

        M7.write(pos_4 + err[6]);
        M8.write(rev_4 - err[7]);

        pos_4--;
        rev_4--;

        delay(speed);
      }
    }

    void liftFrontLeg1() {
      int pos = 40;
      int rev = 60;

      int pos_1 = 60;
      int rev_1 = 80;

      for (pos; pos >= 30; pos -= 1) {
        M1.write(pos + err[0]);
        M2.write(rev - err[1]);
        M3.write(pos_1 + err[2]);
        M4.write(rev_1 - err[3]);
        pos_1--;
        rev_1++;
        rev++;
        delay(speed);
      }
    }

    void liftThirdLeg1() {
      int pos = 60;

      for (pos; pos >= 20; pos -= 1) {
        M5.write(pos + err[4]);
        delay(speed);
      }
    } 

    void dropThirdLeg1() {
      int pos = 20;
      int rev = 100;

      for (pos; pos <= 40; pos += 1) {
        M5.write(pos + err[4]);
        M6.write(rev - err[5]);
        rev--;
        delay(speed);
      }
    }

    void liftFourthLeg1() {
      int rev = 60;

      for (rev; rev <= 100; rev += 1) {
        M8.write(rev - err[7]);
        delay(speed);
      }
    }
    
    void dropFourthLeg1() {
      int pos = 20;
      int rev = 100;

      for (pos; pos <= 40; pos += 1) {
        M7.write(pos + err[6]);
        M8.write(rev - err[7]);
        rev--;
        delay(speed);
      }
    }

    void dropFrontLeg1() {
      int pos = 30;
      int rev = 70;

      int pos_1 = 50;
      int rev_1 = 90;

      for (pos; pos <= 40; pos += 1) {
        M1.write(pos + err[0]);
        M2.write(rev - err[1]);
        M3.write(pos_1 + err[2]);
        M4.write(rev_1 - err[3]);
        pos_1++;
        rev_1--;
        rev--;
        delay(speed);
      }
    }

    // CLIMBING RAMP // 

    void liftSmallFourthLeg() {
      int pos = 40;
      int rev = 40;

      for (pos; pos >= 20; pos -= 1) {
        M7.write(pos + err[6]);
        M8.write(rev - err[7]);
        rev++;
        delay(speed);
      }
    }

    void liftThirdLegA() {
      int pos = 100;
      int rev = 100;

      for (pos; pos >= 80; pos -= 1) {
        M5.write(pos + err[4]);
        M6.write(rev - err[5]);
        rev++;
        delay(speed);
      }
    }

    void pushThirdLegA() {
      int pos = 60;
      int rev = 100;

      for (pos; pos >= 30; pos -= 1) {
        M5.write(pos + err[4]);
        M6.write(rev - err[5]);
        rev--;
        delay(speed);
      }
    }

    void dropThirdLegA() {
      int rev = 120;

      for (rev; rev >= 80; rev -= 1) {
        M6.write(rev - err[5]);
        delay(speed);
      }
    }

    void liftFourthLegA() {
      int pos = 20;
      int rev = 20;

      for (pos; pos >= 0; pos -= 1) {
        M7.write(pos + err[6]);
        M8.write(rev - err[7]);
        rev++;
        delay(speed);
      }
    }

    void pushFourthLegA() {
      int pos = 10;
      int rev = 70;

      for (pos; pos <= 30; pos += 1) {
        M7.write(pos + err[6]);
        M8.write(rev - err[7]);
        rev--;
        delay(speed);
      }
    }

    void dropFourthLegA() {
      int pos = 0;

      for (pos; pos <= 40; pos += 1) {
        M7.write(pos + err[6]);
        delay(speed);
      }
    }

    void liftFirstLeg() {
      int pos = 50;
      int rev = 70;

      for (pos; pos >= 30; pos -= 1) {
        M1.write(pos + err[0]);
        M2.write(rev - err[1]);
        rev++;
        delay(speed);
      }
    }

    void pushFirstLeg() {
      int pos = 30;
      int rev = 90;

      for (pos; pos >= 0; pos -= 1) {
        M1.write(pos + err[0]);
        M2.write(rev - err[1]);
        rev--;
        delay(speed);
      }
    }

    void dropFirstLeg() {
      int pos = 0;
      int rev = 60;

      for (pos; pos <= 20; pos += 1) {
        M1.write(pos + err[0]);
        M2.write(rev - err[1]);
        rev--;
        delay(speed);
      }
    }

    void dropSmallFourthLeg() {
      int pos = 20;
      int rev = 60;

      for (pos; pos <= 40; pos += 1) {
        M7.write(pos + err[6]);
        M8.write(rev - err[7]);
        rev--;
        delay(speed);
      }
    }

    void liftSmallThirdLeg() {
      int pos = 80;
      int rev = 80;

      for (pos; pos >= 60; pos -= 1) {
        M5.write(pos + err[4]);
        M6.write(rev - err[5]);
        rev++;
        delay(speed);
      }
    }

    void liftSecondLeg() {
      int pos = 50;
      int rev = 70;

      for (pos; pos >= 30; pos -= 1) {
        M3.write(pos + err[2]);
        M4.write(rev - err[3]);
        rev++;
        delay(speed);
      }
    }

    void pushSecondLeg() {
      int pos = 30;
      int rev = 90;
      for (pos; pos <= 60; pos += 1) {
        M3.write(pos + err[2]);
        M4.write(rev - err[3]);
        rev++;
        delay(speed);
      }
    } 

    void dropSecondLeg() {
      int pos = 60;
      int rev = 120;
      for (pos; pos <= 80; pos += 1) {
        M3.write(pos + err[2]);
        M4.write(rev - err[3]);
        rev--;
        delay(speed);
      }
    }

    void dropSmallThirdLeg() {
      int pos = 60;
      int rev = 100;

      for (pos; pos <= 80; pos += 1) {
        M5.write(pos + err[4]);
        M6.write(rev - err[5]);
        rev--;
        delay(speed);
      }
    }

    void allForward2() {
      int pos = 20;
      int rev = 40;
      
      int pos_2 = 80;
      int rev_2 = 100;

      int pos_3 = 50;
      int rev_3 = 70;

      int pos_4 = 50;
      int rev_4 = 70;

      for (pos; pos <= 50; pos += 1) {
        M1.write(pos + err[0]);
        M2.write(rev - err[1]);

        rev++;

        M3.write(pos_2 + err[2]);
        M4.write(rev_2 - err[3]);

        pos_2--;
        rev_2--;

        if (pos_3 <= 100) { 
          M5.write(pos_3 + err[4]);
          M6.write(rev_3 - err[5]);
          pos_3++;
          rev_3++;

          M7.write(pos_4 + err[6]);
          M8.write(rev_4 - err[7]);

          pos_4--;
          rev_4--;
        }

        delay(speed);
      }
    } 

    void liftFrontLeg() {
      int pos = 50;
      int rev = 70;

      for (pos; pos >= 30; pos -= 1) {
        M1.write(pos + err[0]);
        M2.write(rev - err[1]);
        M3.write(pos + err[2]);
        M4.write(rev - err[3]);
        rev++;
        delay(speed);
      }
    }

    void liftThirdLeg() {
      int pos = 80;

      for (pos; pos >= 50; pos -= 1) {
        M5.write(pos + err[4]);
        delay(speed);
      }
    } 

    void dropThirdLeg() {
      int pos = 50;
      int rev = 110;

      for (pos; pos <= 70; pos += 1) {
        M5.write(pos + err[4]);
        M6.write(rev - err[5]);
        rev--;
        delay(speed);
      }
    }

    void liftFourthLeg() {
      int rev = 30;

      for (rev; rev <= 70; rev += 1) {
        M8.write(rev - err[7]);
        delay(speed);
      }
    }
    
    void dropFourthLeg() {
      int pos = 10;
      int rev = 70;

      for (pos; pos <= 30; pos += 1) {
        M7.write(pos + err[6]);
        M8.write(rev - err[7]);
        rev--;
        delay(speed);
      }
    }

    void dropFrontLeg() {
      int pos = 30;
      int rev = 90;

      for (pos; pos <= 50; pos += 1) {
        M1.write(pos + err[0]);
        M2.write(rev - err[1]);
        M3.write(pos + err[2]);
        M4.write(rev - err[3]);
        rev--;
        delay(speed);
      }
    }

  private:
    Servo M1, M2, M3, M4, M5, M6, M7, M8;
    int hertz, min_pulse, max_pulse;
    int speed;
};

#endif