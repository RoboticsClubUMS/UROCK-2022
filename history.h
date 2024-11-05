/*

    void initLeg() {
      int pos = 120;
      int rev = 0;
      for (pos; pos >= 0; pos -= 1) {
        M1.write(pos + err[0]);
        M2.write(rev - err[1]);
        M3.write(pos + err[2]);
        M4.write(rev - err[3]);
        M5.write(pos + err[4]);
        M6.write(rev - err[5]);
        M7.write(pos + err[6]);
        M8.write(rev - err[7]);
        delay(speed);
        rev++;
      }
    }
    void liftLeg() {
      int pos = 50;
      int rev = 70;

      for (pos; pos >= 30; pos -= 1) {
        M1.write(pos);
        M2.write(rev);
        rev++;
        delay(speed);
      }
    }

    void liftLeg2() {
      int pos = 50;
      int rev = 70;

      for (pos; pos >= 30; pos -= 1) {
        M3.write(pos);
        M4.write(rev);
        rev++;
        delay(speed);
      }
    }

    void ABEFLeg() {
      int pos_1 = 30;
      int rev_1 = 90;

      int pos_2 = 50;
      int rev_2 = 70;

      for (pos_1; pos_1 <= 40; pos_1 += 1) {
        M1.write(pos_1);
        M2.write(rev_1);
        //M3.write(pos_2);
        //M4.write(rev_2);
        rev_1++;
        pos_2--;
        rev_2--;
        delay(speed);
      }
    }

    void BCFGLeg() {
      int pos_1 = 40;
      int pos_2 = 40;
      for (pos_1; pos_1 <= 60; pos_1 += 1) {
        M1.write(pos_1);
        M3.write(pos_2);
        pos_2--;
        delay(speed);
      }
    }

    void CDGHLeg() {
      int rev_1 = 100;
      int rev_2 = 60;
      for (rev_1; rev_1 >= 80; rev_1 -= 1) {
        M2.write(rev_1);
        M4.write(rev_2);
        rev_2++;
        delay(speed);
      }
    }

    void DFHBLeg() {
      int pos_1 = 60;
      int rev_1 = 80;

      int pos_2 = 20;
      int rev_2 = 80;
      for (pos_1; pos_1 >= 40; pos_1 -= 1) {
        M1.write(pos_1);
        M2.write(rev_1);
        rev_1--;

        M3.write(pos_2);
        M4.write(rev_2);
        pos_2++;
        rev_2++;
        delay(speed);
      }
    }

    void FGBCLeg() {
      int pos_1 = 40;
      int pos_2 = 40;
      for (pos_1; pos_1 <= 60; pos_1 += 1) {
        M3.write(pos_1);
        M1.write(pos_2);
        pos_2--;
        delay(speed);
      }  
    }

    void GHCDLeg() {
      int rev_1 = 100;
      int rev_2 = 60;
      for (rev_1; rev_1 >= 80; rev_1 -= 1) {
        M4.write(rev_1);
        M2.write(rev_2);
        rev_2++;
        delay(speed);
      }
    }

    void HBDFLeg() {
      int pos_1 = 60;
      int rev_1 = 80;

      int pos_2 = 20;
      int rev_2 = 80;
      for (pos_1; pos_1 >= 40; pos_1 -= 1) {
        M3.write(pos_1);
        M4.write(rev_1);
        rev_1--;

        M1.write(pos_2);
        M2.write(rev_2);
        pos_2++;
        rev_2++;
        delay(speed);
      }
    }

    void BCleg() {
      int pos = 40;
      for (pos; pos <= 60; pos += 1) {
        M1.write(pos);
        //M2.write(rev--);
        delay(speed);
      }
    }

    void CDleg() {
      int rev = 100;
      for (rev; rev >= 80; rev -= 1) {
        M2.write(rev);
        delay(speed);
      }
    }

    void DFleg() {
      int pos = 60;
      int rev = 80;
      for (pos; pos >= 40; pos--) {
        M1.write(pos);
        M2.write(rev--);
        delay(speed);
      }
    }

    void FGleg() {

      int pos = 40;

      for (pos; pos >= 20; pos -= 1) {
        M1.write(pos);
        delay(speed);

      }
    }

    void GHleg() {

      int rev = 60;
      for (rev; rev <= 80; rev += 1) {
        M2.write(rev);
        delay(speed);

      }
    }

    void HBleg() {
      int pos = 20;
      int rev = 80;
      for (pos; pos <= 40; pos+=1) {
        M1.write(pos);
        M2.write(rev++);
        delay(speed);
      } 
    }

    void ABLeg() {
      int pos = 30;
      int rev = 90;

      for (pos; pos <= 40; pos += 1) {
        M1.write(pos);
        M2.write(rev);
        rev++;
        delay(speed);
      }
    }
    
    void DELeg() {
      int pos = 50;
      int rev = 70;
      for (pos; pos >= 40; pos -= 1) {
        M1.write(pos);
        M2.write(rev--);
        delay(speed);
      }
    }


































   void ABLegTest(int leg) {  

      int pos = 30;
      int rev = 90;
      for (pos; pos <= 40; pos += 1) {
        switch (leg) {
          case 0:
            M1.write(pos);
            M2.write(rev);
            break;
          case 1:
            M3.write(pos);
            M4.write(rev);
            break;
          case 2:
            M5.write(pos);
            M6.write(rev);
            break;
          case 3:
            M7.write(pos);
            M8.write(rev);
            break;
        }
        rev++;
        delay(speed);
      }
    }

    void BCLegTest(int leg) {
      int pos = 40;
      for (pos; pos <= 60; pos += 1) {
        switch (leg) {
          case 0:
            M1.write(pos);
            break;
          case 1:
            M3.write(pos);
            break;
          case 2:
            M5.write(pos);
            break;
          case 3:
            M7.write(pos);
            break;
        }
        delay(speed);
      }
    }

    void CDLegTest(int leg) {
      int rev = 100;
      for (rev; rev >= 80; rev -= 1) {
        switch (leg) {
          case 0:
            M2.write(rev);
            break;
          case 1:
            M4.write(rev);
            break;
          case 2:
            M6.write(rev);
            break;
          case 3:
            M8.write(rev);
            break;
        }
        delay(speed);
      }
    }

    void DELegTest(int leg) {
      int pos = 60;
      int rev = 80;
      for (pos; pos >= 50; pos -= 1) {
        switch (leg) {
          case 0:
            M1.write(pos);
            M2.write(rev);
            break;
          case 1:
            M3.write(pos);
            M4.write(rev);
            break;
          case 2:
            M5.write(pos);
            M6.write(rev);
            break;
          case 3:
            M7.write(pos);
            M8.write(rev);
            break;
        }
        rev--;
        delay(speed);
      }
    }

    void EFLegTest(int leg) {
      int pos = 50;
      int rev = 70;
      for (pos; pos >= 40; pos -= 1) {
        switch (leg) {
          case 0:
            M1.write(pos);
            M2.write(rev);
            break;
          case 1:
            M3.write(pos);
            M4.write(rev);
            break;
          case 2:
            M5.write(pos);
            M6.write(rev);
            break;
          case 3:
            M7.write(pos);
            M8.write(rev);
            break;
        }
        rev--;
        delay(speed);
      }
    }

    void FGlegTest(int leg) {
      int pos = 40;
      for (pos; pos >= 20; pos -= 1) {
        switch (leg) {
          case 0:
            M1.write(pos);
            break;
          case 1:
            M3.write(pos);
            break;
          case 2:
            M5.write(pos);
            break;
          case 3:
            M7.write(pos);
            break;
        }
        delay(speed);
      }
    }

    void GHLegTest(int leg) {
      int rev = 60;
      for (rev; rev <= 80; rev += 1) {
        switch (leg) {
          case 0:
            M2.write(rev);
            break;
          case 1:
            M4.write(rev);
            break;
          case 2:
            M6.write(rev);
            break;
          case 3:
            M8.write(rev);
            break;
        }
        delay(speed);
      }
    }

    void HALegTest(int leg) {
      int pos = 20;
      int rev = 80;

      for (pos; pos <= 30; pos += 1) {
        switch (leg) {
          case 0:
            M1.write(pos);
            M2.write(rev);
            break;
          case 1:
            M3.write(pos);
            M4.write(rev);
            break;
          case 2:
            M5.write(pos);
            M6.write(rev);
            break;
          case 3:
            M7.write(pos);
            M8.write(rev);
            break;
        }
        rev++;
        delay(speed);
      }

    }

    void AHLegTest(int leg) {
      int pos = 30;
      int rev = 90;

      for (pos; pos >= 20; pos -= 1) {
        switch (leg) {
          case 0:
            M1.write(pos);
            M2.write(rev);
            break;
          case 1:
            M3.write(pos);
            M4.write(rev);
            break;
          case 2:
            M5.write(pos);
            M6.write(rev);
            break;
          case 3:
            M7.write(pos);
            M8.write(rev);
            break;
        }
        rev--;
        delay(speed);
      }

    }


    void HGLegTest(int leg) {
      int rev = 80;
      for (rev; rev >= 60; rev -= 1) {
        switch (leg) {
          case 0:
            M2.write(rev);
            break;
          case 1:
            M4.write(rev);
            break;
          case 2:
            M6.write(rev);
            break;
          case 3:
            M8.write(rev);
            break;
        }
        delay(speed);
      }
    }

    void GFLegTest(int leg) {
      int pos = 20;
      for (pos; pos <= 40; pos += 1) {
        switch (leg) {
          case 0:
            M1.write(pos);
            break;
          case 1:
            M3.write(pos);
            break;
          case 2:
            M5.write(pos);
            break;
          case 3:
            M7.write(pos);
            break;
        }
        delay(speed);
      }
    }

    void FELegTest(int leg) {
      int pos = 40;
      int rev = 60;
      for (pos; pos <= 50; pos += 1) {
        switch (leg) {
          case 0:
            M1.write(pos);
            M2.write(rev);
            break;
          case 1:
            M3.write(pos);
            M4.write(rev);
            break;
          case 2:
            M5.write(pos);
            M6.write(rev);
            break;
          case 3:
            M7.write(pos);
            M8.write(rev);
            break;
        }
        rev++;
        delay(speed);
      }
    }

    void EDLegTest(int leg) {
      int pos = 50;
      int rev = 70;
      for (pos; pos <= 60; pos += 1) {
        switch (leg) {
          case 0:
            M1.write(pos);
            M2.write(rev);
            break;
          case 1:
            M3.write(pos);
            M4.write(rev);
            break;
          case 2:
            M5.write(pos);
            M6.write(rev);
            break;
          case 3:
            M7.write(pos);
            M8.write(rev);
            break;
        }
        rev++;
        delay(speed);
      }
    }

    void DCLegTest(int leg) {
      int rev = 80;
      for (rev; rev <= 100; rev += 1) {
        switch (leg) {
          case 0:
            M2.write(rev);
            break;
          case 1:
            M4.write(rev);
            break;
          case 2:
            M6.write(rev);
            break;
          case 3:
            M8.write(rev);
            break;
        }
        delay(speed);
      }
    }
    void CBLegTest(int leg) {
      int pos = 60;
      for (pos; pos >= 40; pos -= 1) {
        switch (leg) {
          case 0:
            M1.write(pos);
            break;
          case 1:
            M3.write(pos);
            break;
          case 2:
            M5.write(pos);
            break;
          case 3:
            M7.write(pos);
            break;
        }
        delay(speed);
      }
    }

    void BALegTest(int leg) {
      int pos = 40;
      int rev = 100;
      for (pos; pos >= 30; pos -= 1) {
        switch (leg) {
          case 0:
            M1.write(pos);
            M2.write(rev);
            break;
          case 1:
            M3.write(pos);
            M4.write(rev);
            break;
          case 2:
            M5.write(pos);
            M6.write(rev);
            break;
          case 3:
            M7.write(pos);
            M8.write(rev);
            break;
        }
        rev--;
        delay(speed);
      }
    }

        void forward() {
      moveFLLeg(50, 70, 'B', true, 60);
      moveRRLeg(50, 70, 'B', false, 40);
      moveFRLeg(50, 70, 'B', false, 40);
      moveRLLeg(50, 70, 'B', true, 60);


      moveFLLeg(60, 80, 'R', true, 100);
      moveRRLeg(40, 60, 'L', false, 20);
      moveFRLeg(40, 60, 'L', false, 20);
      moveRLLeg(60, 80, 'R', true, 100);


      moveFLLeg(60, 100, 'L', false, 40);
      moveRRLeg(20, 60, 'R', true, 80);
      moveFRLeg(20, 60, 'R', true, 80);
      moveRLLeg(60, 100, 'L', false, 40);


      moveFLLeg(40, 100, 'B', false, 30);
      moveRRLeg(20, 80, 'B', true, 30);
      moveFRLeg(20, 80, 'B', true, 30);
      moveRLLeg(40, 100, 'B', false, 30);


      moveFLLeg(30, 90, 'B', false, 20);
      moveRRLeg(30, 90, 'B', true, 40);
      moveFRLeg(30, 90, 'B', true, 40);
      moveRLLeg(30, 90, 'B', false, 20);
     
    
      moveFLLeg(20, 80, 'R', false, 60);
      moveRRLeg(40, 100, 'L', true, 60);
      moveFRLeg(40, 100, 'L', true, 60);
      moveRLLeg(20, 80, 'R', false, 60);


      moveFLLeg(20, 60, 'L', true, 40);
      moveRRLeg(60, 100, 'R', false, 80);
      moveFRLeg(60, 100, 'R', false, 80);
      moveRLLeg(20, 60, 'L', true, 40);


      moveFLLeg(40, 60, 'B', true, 50);
      moveRRLeg(60, 80, 'B', false, 50);
      moveFRLeg(60, 80, 'B', false, 50);
      moveRLLeg(40, 60, 'B', true, 50);

    }

        void firstStartLeg(int leg) {
      switch (leg) {
        case 0:
          liftLegTest(0);
          moveFLLeg(30, 90, 'B', false, 20);
          moveFLLeg(20, 80, 'R', false, 60);
          moveFLLeg(20, 60, 'L', true, 40);
          moveFLLeg(40, 60, 'B', true, 50);
          break;

        case 1:
          liftLegTest(1);
          moveFRLeg(30, 90, 'B', true, 40);
          moveFRLeg(40, 100, 'L', true, 60);
          moveFRLeg(60, 100, 'R', false, 80);
          moveFRLeg(60, 80, 'B', false, 50);

        case 2:
          moveRLLeg(30, 90, 'B', false, 20);
          moveRLLeg(20, 80, 'R', false, 60);
          moveRLLeg(20, 60, 'L', true, 40);
          moveRLLeg(40, 60, 'B', true, 50);
          break;

        case 3:
          moveRRLeg(30, 90, 'B', true, 40);
          moveRRLeg(40, 100, 'L', true, 60);
          moveRRLeg(60, 100, 'R', false, 80);
          moveRRLeg(60, 80, 'B', false, 50);
          break;
      }

    }

    void liftLegTest(int leg) {
      int pos = 50;
      int rev = 70;
      for (pos; pos >= 30; pos -= 1) {
        switch (leg) {
          case 0:
            M1.write(pos);
            M2.write(rev);
            break;
          case 1:
            M3.write(pos);
            M4.write(rev);
            break;
          case 2:
            M5.write(pos);
            M6.write(rev);
            break;
          case 3:
            M7.write(pos);
            M8.write(rev);
            break;
          case 4:
            M1.write(pos);
            M2.write(rev);
            M7.write(pos);
            M8.write(rev);
            break;
          case 5:
            M3.write(pos);
            M4.write(rev);
            M5.write(pos);
            M6.write(rev);  
            break;          
        }
        rev++;
        delay(speed);
      }
    }

    void moveFLLeg(int pos, int rev, char typeMove, bool inc, int target) {
      switch (typeMove) {
        case 'L':
          if (inc) {
            for (pos; pos <= target; pos += 1) {
              M1.write(pos);
              delay(speed);
            }
          } else {
            for (pos; pos >= target; pos -= 1) {
              M1.write(pos);
              delay(speed);
            }
          }
          break;
        case 'R':
          if (inc) {
            for (rev; rev <= target; rev += 1) {
              M2.write(rev);
              delay(speed);
            }
          } else {
            for (rev; rev >= target; rev -= 1) {
              M2.write(rev);
              delay(speed);
            }
          }
          break;

        case 'B':
          if (inc) {
            for (pos; pos <= target; pos += 1) {
              M1.write(pos);
              M2.write(rev);
              rev++;
              delay(speed);
            }
          } else {
            for (pos; pos >= target; pos -= 1) {
              M1.write(pos);
              M2.write(rev);
              rev--;
              delay(speed);
            }
          }
          break;
      }
    }

    void moveFRLeg(int pos, int rev, char typeMove, bool inc, int target) {
      switch (typeMove) {
        case 'L':
          if (inc) {
            for (pos; pos <= target; pos += 1) {
              M3.write(pos);
              delay(speed);
            }
          } else {
            for (pos; pos >= target; pos -= 1) {
              M3.write(pos);
              delay(speed);
            }
          }
          break;
        case 'R':
          if (inc) {
            for (rev; rev <= target; rev += 1) {
              M4.write(rev);
              delay(speed);
            }
          } else {
            for (rev; rev >= target; rev -= 1) {
              M4.write(rev);
              delay(speed);
            }
          }
          break;

        case 'B':
          if (inc) {
            for (pos; pos <= target; pos += 1) {
              M3.write(pos);
              M4.write(rev);
              rev++;
              delay(speed);
            }
          } else {
            for (pos; pos >= target; pos -= 1) {
              M3.write(pos);
              M4.write(rev);
              rev--;
              delay(speed);
            }
          }
          break;
      }
    }

    void moveRLLeg(int pos, int rev, char typeMove, bool inc, int target) {
      switch (typeMove) {
        case 'L':
          if (inc) {
            for (pos; pos <= target; pos += 1) {
              M5.write(pos);
              delay(speed);
            }
          } else {
            for (pos; pos >= target; pos -= 1) {
              M5.write(pos);
              delay(speed);
            }
          }
          break;
        case 'R':
          if (inc) {
            for (rev; rev <= target; rev += 1) {
              M6.write(rev);
              delay(speed);
            }
          } else {
            for (rev; rev >= target; rev -= 1) {
              M6.write(rev);
              delay(speed);
            }
          }
          break;

        case 'B':
          if (inc) {
            for (pos; pos <= target; pos += 1) {
              M5.write(pos);
              M6.write(rev);
              rev++;
              delay(speed);
            }
          } else {
            for (pos; pos >= target; pos -= 1) {
              M5.write(pos);
              M6.write(rev);
              rev--;
              delay(speed);
            }
          }
          break;
      }
    }

    void moveRRLeg(int pos, int rev, char typeMove, bool inc, int target) {
      switch (typeMove) {
        case 'L':
          if (inc) {
            for (pos; pos <= target; pos += 1) {
              M7.write(pos);
              delay(speed);
            }
          } else {
            for (pos; pos >= target; pos -= 1) {
              M7.write(pos);
              delay(speed);
            }
          }
          break;
        case 'R':
          if (inc) {
            for (rev; rev <= target; rev += 1) {
              M8.write(rev);
              delay(speed);
            }
          } else {
            for (rev; rev >= target; rev -= 1) {
              M8.write(rev);
              delay(speed);
            }
          }
          break;

        case 'B':
          if (inc) {
            for (pos; pos <= target; pos += 1) {
              M7.write(pos);
              M8.write(rev);
              rev++;
              delay(speed);
            }
          } else {
            for (pos; pos >= target; pos -= 1) {
              M7.write(pos);
              M8.write(rev);
              rev--;
              delay(speed);
            }
          }
          break;
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

      /*
  Doggo.DM1();
  Doggo.DM33();
  Doggo.DM2();
  Doggo.DM44();
  Doggo.DM3();
  Doggo.DM11();
  Doggo.DM4();
  Doggo.DM22();
  /*
  Doggo.AMF3();
  Doggo.AMF11();
  Doggo.AMR22();
  Doggo.AMF4();
  Doggo.AMF22();
  Doggo.AMR1();
  Doggo.AMR33();
  Doggo.AMF1();
  Doggo.AMF33();
  Doggo.AMR2();
  Doggo.AMR44();
  Doggo.AMF2();
  Doggo.AMF44();
  Doggo.AMR3();
  Doggo.AMR11();*/
/*
  Doggo.DM2();
  Doggo.DM11();
  Doggo.DM3();
  Doggo.DM22();
  Doggo.DM4();
  Doggo.DM33();
  Doggo.DM1();
  Doggo.DM44();
/*
  Doggo.DM11();
  Doggo.DM4();
  Doggo.DM22();
  Doggo.DM1();
  Doggo.DM33();
  Doggo.DM2();
  Doggo.DM44();
  Doggo.DM3();
  /*
    if (!hasStartFirst) {
      Doggo.liftLegTest(4);
      Doggo.FLRR5();
      Doggo.FRRL1();
      Doggo.FLRR6();
      Doggo.FRRL2();
      Doggo.FLRR7();
      Doggo.FRRL3();
      Doggo.FLRR8();
      Doggo.FRRL4();
      
      //Doggo.FRRL2();
      //Doggo.FLRR6();
      //Doggo.FRRL3();
      //Doggo.FLRR7();
      //Doggo.FRRL4();
      //Doggo.FLRR8();
      hasStartFirst = true;
    }

    Doggo.FLRR1();
    Doggo.FRRL5();
    Doggo.FLRR2();
    Doggo.FRRL6();
    Doggo.FLRR3();
    Doggo.FRRL7();
    Doggo.FLRR4();
    Doggo.FRRL8();
    Doggo.FLRR5();
    Doggo.FRRL1();
    Doggo.FLRR6();
    Doggo.FRRL2();
    Doggo.FLRR7();
    Doggo.FRRL3();
    Doggo.FLRR8();
    Doggo.FRRL4();
 
  //Serial.println(hasStart);
  //Serial.println(hasReady);
  
  /*
  if (!startFLLeg) {
    Doggo.firstStartLeg(0);
    startFLLeg = true;
  }

  if (!startRRLeg) {
    Doggo.firstStartLeg(3);
    startRRLeg = true;
  }

  if (!startFRLeg) {
    Doggo.firstStartLeg(1);
    startFRLeg = true;
  }

  if (!startRLLeg) {
    Doggo.firstStartLeg(2);
    startRLLeg = true;
  }



  /*if (digitalRead(SUNX_PIN_1) || digitalRead(SUNX_PIN_1)) {
    Doggo.stop();
  }

  //Doggo.forward();
  
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
        M4.writ
        e(rev_2 - err[3]);
        pos_2--;
        rev_2--;
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

  /*
  if (int(differencePitch) <= (int(initialPitch)-10) && isWalk) { // FIRST LAYER
    previousMillis = millis();
    while(int(differencePitch) <= (int(initialPitch)-10)) {
      getCurrentGyro(&pitch, &yaw);
      differenceYaw = initialYaw - yaw;
      differencePitch = initialPitch - pitch;

      if (millis() - previousMillis > interval) {
        hasReady = false;
        isClimb = true;
        break;
      }

      Doggo.walk();
    }
    while (isClimb) {
      getCurrentGyro(&pitch, &yaw);
      differenceYaw = initialYaw - yaw;
      differencePitch = initialPitch - pitch;
      if (!hasReady) {
        Doggo.readyLeg();
        delay(1000);
        hasReady = true;
      }

      Doggo.climbRamp();

      if (int(differencePitch) >= int(initialPitch) + 5) { // SECOND LAYER
        previousMillis = millis();
        while(int(differencePitch) >= int(initialPitch) + 5) {
          getCurrentGyro(&pitch, &yaw);
          differenceYaw = initialYaw - yaw;
          differencePitch = initialPitch - pitch;
          if (millis() - previousMillis > interval) {
            hasReady = false;
            isClimb = false;
            isDescend = true;
            break;
          }

          Doggo.climbRamp();
        }

        while (isDescend) {
          getCurrentGyro(&pitch, &yaw);
          differenceYaw = initialYaw - yaw;
          differencePitch = initialPitch - pitch;
          if (!hasReady) {
            Doggo.readyLeg2();
            delay(1000);
            hasReady = true;
          }

          Doggo.downRamp();

          if (int(differencePitch) <= int(initialPitch) + 2) { // THIRD LAYER
            previousMillis = millis();
            while (int(differencePitch) <= int(initialPitch) + 2) {
              getCurrentGyro(&pitch, &yaw);
              differenceYaw = initialYaw - yaw;
              differencePitch = initialPitch - pitch;
              if (millis() - previousMillis > interval) {
                //getCurrentGyro(&initialPitch, &initialYaw);
                hasReady = false;
                isDescend = false;
                isWalk = true;
                break;
              }

              Doggo.downRamp();
            }
          } 
        }
      }      
    }
  } else {
    if (!hasReady) {
      Doggo.readyLeg();
      delay(1000);
      Doggo.initialLift();
      hasReady = true;
    }

    Doggo.walk();

    if (int(differenceYaw) <= -10) {
      Doggo.readyLeg();
      delay(1000);
      while(int(differenceYaw) <= -2) {
        Doggo.turnRight();

        getCurrentGyro(&pitch, &yaw);
        differenceYaw = initialYaw - yaw;
        differencePitch = initialPitch - pitch;
      }

      hasReady = false;
    } else if (int(differenceYaw) >= 10) {
      Doggo.readyLeg();
      delay(1000);
      while(int(differenceYaw) >= 2) {
        Doggo.turnLeft();

        getCurrentGyro(&pitch, &yaw);
        differenceYaw = initialYaw - yaw;
        differencePitch = initialPitch - pitch;
      }

      hasReady = false;
    }
  }

*/
/*
  if (distance <= 15) {
    if (!hasReady) {
      Doggo.readyLeg();
      delay(1000);
      hasReady = true;
    }
    digitalWrite(LED, HIGH);
    Doggo.climbRamp();
  } else if (distance >= 25) {
    if (!hasReady) {
      Doggo.readyLeg2();
      delay(1000);
      hasReady = true;
    }
    digitalWrite(LED, LOW);
    Doggo.downRamp();
  } else {
    if (!hasReady) {
      Doggo.readyLeg();
      delay(1000);
      Doggo.initialLift();
      hasReady = true;
    }
    digitalWrite(LED, LOW);
    Doggo.walk();
  }

  Serial.println(distance);
  
  /*

  if (int(differenceYaw) <= -10 && isWalk) {
    if (!hasReady) {
      Doggo.readyLeg();
      delay(1000);
      hasReady = true;
    }

    while(int(differenceYaw) <= -5) {
      Doggo.turnRight();
      Serial.println("Turning right");

      getCurrentGyro(&pitch, &yaw);
      differenceYaw = initialYaw - yaw;
    }

    hasReady = false;

  } else if (int(differenceYaw) >= 10 && isWalk) {
    if (!hasReady) {
      Doggo.readyLeg();
      delay(1000);
      hasReady = true;
    }

    while(int(differenceYaw) >= 5) {
      Doggo.turnLeft();
      Serial.println("Turning Left");

      getCurrentGyro(&pitch, &yaw);
      differenceYaw = initialYaw - yaw;
    }
    
    hasReady = false;
  } else {
  */


/*
    if (int(differencePitch) <= -15 && isWalk) { // FIRST OUTER IF 
      previousMillis = millis();
      while (int(differencePitch) <= -15) {
        if (millis() - previousMillis > interval) {
          hasReady = false;
          isWalk = false;
          isClimb = true;
          break;
        }

        Doggo.walk();

        getCurrentGyro(&pitch, &yaw);
        differencePitch = initialPitch - pitch;
      }
    } else if (int(differencePitch) <= -15 && isClimb){ // SECOND OUTER IF 
      if (!hasReady) {
        Doggo.readyLeg();
        delay(1000);
        hasReady = true;
      }

      Doggo.climbRamp();
    } else if (int(differencePitch) > 5 && isClimb) { // THIRD OUTER IF
      previousMillis = millis();
      while(int(differencePitch) > 5) {
        if (millis() - previousMillis > interval) {
          hasReady = false;
          isDescend = true;
          isClimb = false;
          break;
        }

        Doggo.climbRamp();

        getCurrentGyro(&pitch, &yaw);
        differencePitch = initialPitch - pitch;
      }
    } else if (int(differencePitch) > -15 && isClimb) { // FOURTH OUTER IF
      Doggo.climbRamp();
    } else if (int(differencePitch) > 5 && isDescend) { // FIFRTH OUTER IF
      if (!hasReady) {
        Doggo.readyLeg2();
        delay(1000);
        hasReady = true;
      }

      Doggo.downRamp();
    } else if (int(differencePitch) > -15 && int(differencePitch) < 5 && isDescend) { // SIXTH OUTER IF
      previousMillis = millis();
      while(int(differencePitch) > -15 && int(differencePitch) < 5) {
        if (millis() - previousMillis > interval) {
          hasReady = false;
          isDescend = false;
          isWalk = true;
          break;
        }

        Doggo.downRamp();

        getCurrentGyro(&pitch, &yaw);
        differencePitch = initialPitch - pitch;
      }
    } else { // EIGTH OUTER IF
      if (!hasReady) {
        Doggo.readyLeg();
        delay(500);
        Doggo.initialLift();
        hasReady = true;
      }
      Doggo.walk();
    }

      Serial.print("Pos Pitch: ");
      Serial.println(int(differencePitch));
      Serial.print("Pos Yaw: ");
      Serial.println(differenceYaw);

      Serial.print("Now: ");
      if (isWalk) Serial.println("Walking");
      else if (isClimb) Serial.println("Climbing");
      else if (isDescend) Serial.println("Descending");
  //}

 
  //Doggo.test();*/

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

    void FLRR1() {
      int pos = 50;
      int rev = 70;

      int pos_2 = 50;
      int rev_2 = 70;

      for (pos; pos <= 60; pos += 1) {
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

    void FLRR2() {
      int rev = 80;

      int pos_2 = 40;

      for (rev; rev <= 110; rev += 1) {
        M2.write(rev - err[1]);
        M7.write(pos_2 + err[6]);
        pos_2--;
        delay(speed);
      }
    }

    void FLRR3() {
      int pos = 60;

      int rev_2 = 60;

      for (pos; pos >= 30; pos -= 1) {
        M1.write(pos + err[0]);

        M8.write(rev_2 - err[7]);
        rev_2++;
        delay(speed);
      }
    }

    void FLRR4() {
      int pos = 30;
      int rev = 110;

      int pos_2 = 10;
      int rev_2 = 90;

      for (pos; pos >= 20; pos -= 1) {
        M1.write(pos + err[0]);
        M2.write(rev - err[1]);

        M7.write(pos_2 + err[6]);
        M8.write(rev_2 - err[7]);
        rev--;
        pos_2++;
        rev_2++;
        delay(speed);
      }
    }

    void FLRR5() {
      int pos = 20;
      int rev = 100;

      int pos_2 = 20;
      int rev_2 = 100;

      for (pos; pos >= 10; pos -= 1) {
        M1.write(pos + err[0]);
        M2.write(rev - err[1]);

        M7.write(pos_2 + err[6]);
        M8.write(rev_2 - err[7]);
        rev--;
        pos_2++;
        rev_2++;
        delay(speed);
      }
    }

    void FLRR6() {

      int rev = 90;

      int pos_2 = 30;
 

      for (rev; rev >= 60; rev -= 1) {
        M2.write(rev - err[1]);
        M7.write(pos_2 + err[6]);
        pos_2++;
        delay(speed);
      }
    }

    void FLRR7() {
      int pos = 10;
      int rev_2 = 110;

      for (pos; pos <= 40; pos += 1) {
        M1.write(pos + err[0]);
        M8.write(rev_2 - err[7]);
        rev_2--;
        delay(speed);
      }
    }

    void FLRR8() {
      int pos = 40;
      int rev = 60;

      int pos_2 = 60;
      int rev_2 = 80;

      for (pos; pos <= 50; pos += 1) {
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

    void FRRL1() {
      int pos = 50;
      int rev = 70;

      int pos_2 = 50;
      int rev_2 = 70;

      for (pos; pos <= 60; pos += 1) {
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

    void FRRL2() {
      int rev = 80;
      int pos_2 = 40;

      for (rev; rev <= 110; rev += 1) {
        M6.write(rev - err[5]);

        M3.write(pos_2 + err[2]);
        pos_2--;
        delay(speed);
      }
    }

    void FRRL3() {
      int pos = 60;

      int rev_2 = 60;

      for (pos; pos >= 30; pos -= 1) {
        M5.write(pos + err[4]);

        M4.write(rev_2 - err[3]);
        rev_2++;
        delay(speed);
      }
    }

    void FRRL4() {
      int pos = 30;
      int rev = 110;

      int pos_2 = 10;
      int rev_2 = 90;

      for (pos; pos >= 20; pos -= 1) {
        M5.write(pos + err[4]);
        M6.write(rev - err[5]);

        M3.write(pos_2 + err[2]);
        M4.write(rev_2 - err[3]);
        rev--;
        pos_2++;
        rev_2++;
        delay(speed);
      }
    }

    void FRRL5() {
      int pos = 20;
      int rev = 100;

      int pos_2 = 20;
      int rev_2 = 100;

      for (pos; pos >= 10; pos -= 1) {
        M5.write(pos + err[4]);
        M6.write(rev - err[5]);

        M3.write(pos_2 + err[2]);
        M4.write(rev_2 - err[3]);
        rev--;
        pos_2++;
        rev_2++;
        delay(speed);
      }
    }

    void FRRL6() {

      int rev = 90;

      int pos_2 = 30;
 

      for (rev; rev >= 60; rev -= 1) {
        M6.write(rev - err[5]);
        M3.write(pos_2 + err[2]);
        pos_2++;
        delay(speed);
      }
    }

    void FRRL7() {

      int pos = 10;

      int rev_2 = 110;
 

      for (pos; pos <= 40; pos += 1) {
        M5.write(pos + err[4]);
        M4.write(rev_2 - err[3]);
        rev_2--;
        delay(speed);
      }
    }

    void FRRL8() {
      int pos = 40;
      int rev = 60;

      int pos_2 = 60;
      int rev_2 = 80;

      for (pos; pos <= 50; pos += 1) {
        M5.write(pos + err[4]);
        M6.write(rev - err[5]);

        M3.write(pos_2);
        M4.write(rev_2);
        pos_2--;
        rev_2--;
        rev++;
        delay(speed);
      }
    }


    void liftLegTest(int leg) {
      int pos = 50;
      int rev = 70;
      for (pos; pos >= 20; pos -= 1) {
        switch (leg) {
          case 0:
            M1.write(pos);
            M2.write(rev);
            break;
          case 1:
            M3.write(pos);
            M4.write(rev);
            break;
          case 2:
            M5.write(pos);
            M6.write(rev);
            break;
          case 3:
            M7.write(pos);
            M8.write(rev);
            break;
          case 4:
            M1.write(pos);
            M2.write(rev);
            M7.write(pos);
            M8.write(rev);
            break;
          case 5:
            M3.write(pos);
            M4.write(rev);
            M5.write(pos);
            M6.write(rev);  
            break;          
        }
        rev++;
        delay(speed);
      }
    }





















    #ifndef DOG_H
#define DOG_H

#include <ESP32Servo.h>

#define SERVO_PIN_1 15
#define SERVO_PIN_2 18

#define SERVO_PIN_3 13
#define SERVO_PIN_4 14

#define SERVO_PIN_5 19
#define SERVO_PIN_6 23

#define SERVO_PIN_7 32
#define SERVO_PIN_8 33

#define SERVO_MIN_PULSE 500
#define SERVO_MAX_PULSE 2500
#define SERVO_HERTZ 50

#define ANOTHER_SPEED 18
#define HALF_SPEED 10
#define FULL_SPEED 5

int err[8] = {2, 0, 0, 4, 4, 3, 8, 1};

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

    void initLeg() {
      int pos = 120;
      int rev = 0;
      for (pos; pos >= 0; pos -= 1) {
        M1.write(pos + err[0]);
        M2.write(rev - err[1]);
        M3.write(pos + err[2]);
        M4.write(rev - err[3]);
        M5.write(pos + err[4]);
        M6.write(rev - err[5]);
        M7.write(pos + err[6]);
        M8.write(rev - err[7]);
        delay(speed);
        rev++;
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

    void anotherReady() {
      int pos = 30;
      int rev = 90;

      M1.write(pos + err[0]);
      M2.write(rev - err[1]);
      M3.write(pos + err[2]);
      M4.write(rev - err[3]);
      M5.write(pos + err[4]);
      M6.write(rev - err[5]);
      M7.write(pos + err[6]);
      M8.write(rev - err[7]);
    }

    void newTest() {
      int pos = 30;
      int rev = 90;

      for (pos; pos >= 10; pos -= 1) {
        M3.write(pos + err[2]);
        M4.write(rev - err[3]);
        M5.write(pos + err[4]);
        M6.write(rev - err[5]);
        rev++;
        delay(speed);
      }
    }

    void newTest1() {
      int pos = 30;
      int rev = 90;

      int pos_2 = 30;
      int rev_2 = 90;
      
      int rev_3 = 110;
      int pos_4 = 10;

      for (rev_3; rev_3 >= 70; rev_3 -= 1) {
        if (pos <= 50) {
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

    void newTest2() {

      int pos = 10;
      int rev = 70;

      int pos_2 = 50;
      int rev_2 = 110;

      int pos_3 = 50;
      int rev_4 = 70;

      for (pos_3; pos_3 >= 10; pos_3 -= 1) {
        if (pos <= 30) {
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

    void newTest3() {
      int pos = 30;
      int rev = 90;

      int pos_2 = 30;
      int rev_2 = 90;

      int rev_3 = 110;
      int pos_4 = 10;

      for (rev_3; rev_3 >= 70; rev_3 -= 1) {
        if (pos <= 50) {
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

    void newTest4() {
      int pos = 10;
      int rev = 70;

      int pos_2 = 50;
      int rev_2 = 110;

      int pos_3 = 50;
      int rev_4 = 70;

      for (pos_3; pos_3 >= 10; pos_3 -= 1) {
        if (pos <= 30) {
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

    void EDM24() {

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

    void EDM31() {
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

    void specialTilt() {
      int pos = 50;
      int rev = 70;

      int pos_2 = 50;
      int rev_2 = 70;

      for (pos; pos >= 30; pos -= 1) {
        M1.write(pos + err[0]); // 30
        M2.write(rev - err[1]); // 50
        M5.write(pos + err[4]); // 30
        M6.write(rev - err[5]); // 50

        M3.write(pos_2 + err[2]); // 70
        M4.write(rev_2 - err[3]); // 90
        M7.write(pos_2 + err[6]); // 70
        M8.write(rev_2 - err[7]); // 90
        pos_2++;
        rev_2++;
        rev--;
        delay(speed);
      }
    }

    void specialLift2() {

      int pos = 50;
      int rev = 70;

      int pos_2 = 50;
      int rev_2 = 70;

      for (pos; pos >= 30; pos -= 1) {
        M5.write(pos + err[4]); // 10
        M6.write(rev - err[5]); // 70
        M3.write(pos_2 + err[2]); // 50
        M4.write(rev_2 - err[3]); // 110
        pos_2--;
        rev_2++;
        rev++;
        delay(speed);
      }
    }
    
    void specialEDM13() {
      int pos = 30;
      int rev = 50;

      int pos_2 = 70;
      int rev_2 = 90;
      
      int rev_3 = 70;
      int pos_4 = 50;

      for (rev_3; rev_3 >= 30; rev_3 -= 1) {
        if (pos <= 50) {
          M1.write(pos + err[0]); // 50
          M2.write(rev - err[1]); // 70
          M7.write(pos_2 + err[6]); // 50
          M8.write(rev_2 - err[7]); // 70
        }
        M6.write(rev_3 - err[5]); // 30
        M3.write(pos_4 + err[2]); // 90

        pos++;
        rev++;
        pos_2--;
        rev_2--;
        pos_4++;
        delay(speed);
      }  
    }

    void specialEDM24() {

      int pos = 10;
      int rev = 30;

      int pos_2 = 90;
      int rev_2 = 110;

      int pos_3 = 50;
      int rev_4 = 70;

      for (pos_3; pos_3 >= 10; pos_3 -= 1) {
        if (pos <= 30) {
          M5.write(pos + err[4]); // 30
          M6.write(rev - err[5]); // 50
          M3.write(pos_2 + err[2]); // 70
          M4.write(rev_2 - err[3]); // 90
        }
        M1.write(pos_3 + err[0]); // 10
        M8.write(rev_4 - err[7]); // 110
        pos++;
        rev++;
        pos_2--;
        rev_2--;
        rev_4++;
        delay(speed);
      }    
    }

    void newTest() {
      int pos = 30;
      int rev = 90;

      for (pos; pos >= 10; pos -= 1) {
        M3.write(pos + err[2]);
        M4.write(rev - err[3]);
        M5.write(pos + err[4]);
        M6.write(rev - err[5]);
        rev++;
        delay(speed);
      }
    }

    void newTest1() {
      int pos = 30;
      int rev = 90;

      int pos_2 = 30;
      int rev_2 = 90;
      
      int rev_3 = 110;
      int pos_4 = 10;

      for (rev_3; rev_3 >= 70; rev_3 -= 1) {
        if (pos <= 50) {
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

    void newTest2() {

      int pos = 10;
      int rev = 70;

      int pos_2 = 50;
      int rev_2 = 110;

      int pos_3 = 50;
      int rev_4 = 70;

      for (pos_3; pos_3 >= 10; pos_3 -= 1) {
        if (pos <= 30) {
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

    void newTest3() {
      int pos = 30;
      int rev = 90;

      int pos_2 = 30;
      int rev_2 = 90;

      int rev_3 = 110;
      int pos_4 = 10;

      for (rev_3; rev_3 >= 70; rev_3 -= 1) {
        if (pos <= 50) {
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

    void newTest4() {
      int pos = 10;
      int rev = 70;

      int pos_2 = 50;
      int rev_2 = 110;

      int pos_3 = 50;
      int rev_4 = 70;

      for (pos_3; pos_3 >= 10; pos_3 -= 1) {
        if (pos <= 30) {
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

    void specialTilt() {
      int pos = 50;
      int rev = 70;

      int pos_2 = 50;
      int rev_2 = 70;

      for (pos; pos >= 30; pos -= 1) {
        M1.write(pos + err[0]); // 30
        M2.write(rev - err[1]); // 50
        M5.write(pos + err[4]); // 30
        M6.write(rev - err[5]); // 50

        M3.write(pos_2 + err[2]); // 70
        M4.write(rev_2 - err[3]); // 90
        M7.write(pos_2 + err[6]); // 70
        M8.write(rev_2 - err[7]); // 90
        pos_2++;
        rev_2++;
        rev--;
        delay(speed);
      }
    }

    void anotherReady() {
    
      int pos = 30;
      int rev = 90;

      M1.write(pos + err[0]);
      M2.write(rev - err[1]);
      M3.write(pos + err[2]);
      M4.write(rev - err[3]);
      M5.write(pos + err[4]);
      M6.write(rev - err[5]);
      M7.write(pos + err[6]);
      M8.write(rev - err[7]);
    }

    void specialEDM13() {
      int pos = 30;
      int rev = 50;

      int pos_2 = 70;
      int rev_2 = 90;
      
      int rev_3 = 70;
      int pos_4 = 50;

      for (rev_3; rev_3 >= 30; rev_3 -= 1) {
        if (pos <= 50) {
          M1.write(pos + err[0]); // 50
          M2.write(rev - err[1]); // 70
          M7.write(pos_2 + err[6]); // 50
          M8.write(rev_2 - err[7]); // 70
        }
        M6.write(rev_3 - err[5]); // 30
        M3.write(pos_4 + err[2]); // 90

        pos++;
        rev++;
        pos_2--;
        rev_2--;
        pos_4++;
        delay(speed);
      }  
    }

    void specialEDM24() {

      int pos = 10;
      int rev = 30;

      int pos_2 = 90;
      int rev_2 = 110;

      int pos_3 = 50;
      int rev_4 = 70;

      for (pos_3; pos_3 >= 10; pos_3 -= 1) {
        if (pos <= 30) {
          M5.write(pos + err[4]); // 30
          M6.write(rev - err[5]); // 50
          M3.write(pos_2 + err[2]); // 70
          M4.write(rev_2 - err[3]); // 90
        }
        M1.write(pos_3 + err[0]); // 10
        M8.write(rev_4 - err[7]); // 110
        pos++;
        rev++;
        pos_2--;
        rev_2--;
        rev_4++;
        delay(speed);
      }    
    }

    void specialEDM31() {
      int pos = 30;
      int rev = 50;

      int pos_2 = 70;
      int rev_2 = 90;

      int rev_3 = 70;
      int pos_4 = 50;

      for (rev_3; rev_3 >= 30; rev_3 -= 1) {
        if (pos <= 50) {
          M5.write(pos + err[4]); // 50
          M6.write(rev - err[5]); // 70
          M3.write(pos_2 + err[2]); // 50
          M4.write(rev_2 - err[3]); // 70
        }
        M2.write(rev_3 - err[1]); // 30
        M7.write(pos_4 + err[6]); // 90
        pos++;
        rev++;
        pos_2--;
        rev_2--;
        pos_4++;
        delay(speed);
      }    
    }

    void specialEDM42() {
      int pos = 10;
      int rev = 30;

      int pos_2 = 90;
      int rev_2 = 110;

      int pos_3 = 50;
      int rev_4 = 70;

      for (pos_3; pos_3 >= 10; pos_3 -= 1) {
        if (pos <= 30) {
          M1.write(pos + err[0]); // 30
          M2.write(rev - err[1]); // 50
          M7.write(pos_2 + err[6]); // 110
          M8.write(rev_2 - err[7]); // 110
        }
        M5.write(pos_3 + err[4]); // 
        M4.write(rev_4 - err[3]);
        pos++;
        rev++;
        pos_2--;
        rev_2--;
        rev_4++;
        delay(speed);
      }   
    }

        void firstLift1() {
      int pos = 50;
      int rev = 70;
      
      for (pos; pos >= 40; pos -=1) {
        M1.write(pos + err[0]);
        M2.write(rev - err[1]);
        rev++;
        delay(speed);
      }
    }

    void repositionThird() {
      int pos = 70;
      int rev = 90;

      for (pos; pos >= 30; pos -= 1) {
        M5.write(pos + err[4]);
        delay(speed);
      }
    }

    void repositionThird1() {
      int pos = 30;
      int rev = 90;

      for (pos; pos <= 50; pos += 1) {
        M5.write(pos + err[4]);
        M6.write(rev - err[5]);
        rev--;
        delay(speed);
      }
    }

    void repositionFourth() {
      int pos = 30;
      int rev = 50;

      for (rev; rev <= 90; rev += 1) {
        M8.write(rev - err[7]);
        delay(speed);
      }
    }

    void repositionFourth1() {
      int pos = 30;
      int rev = 90;

      for (pos; pos <= 50; pos += 1) {
        M7.write(pos + err[6]);
        M8.write(rev - err[7]);
        rev--;
        delay(speed);
      }
    }

    void allForward() {
      int pos = 10;
      int rev = 70;
      
      int pos_2 = 50;
      int rev_2 = 110;

      int pos_3 = 30;
      int rev_3 = 90;

      int pos_4 = 30;
      int rev_4 = 90;

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

    void initLeg() {
      int pos = 120;
      int rev = 0;
      for (pos; pos >= 0; pos -= 1) {
        M1.write(pos + err[0]);
        M2.write(rev - err[1]);
        M3.write(pos + err[2]);
        M4.write(rev - err[3]);
        M5.write(pos + err[4]);
        M6.write(rev - err[5]);
        M7.write(pos + err[6]);
        M8.write(rev - err[7]);
        delay(speed);
        rev++;
      }
    }

    if (int(differencePitch) > -10 && isWalk && hasReady) {
    Doggo.walk();
  }
  if (int(differencePitch) <= -10 && isWalk && hasReady) {
    previousMillis = millis();
    while (int(differencePitch <= -10)) {
      if (millis() - previousMillis > interval) {
        hasReady = false;
        isClimb = true;
        isWalk = false;
        break;
      }

      Doggo.walk();

      getCurrentGyro(&pitch, &yaw);
      differencePitch = initialPitch - pitch;
    }

  } else if (int(differencePitch) <= -10 && isClimb) {
    if (!hasReady) {
      Doggo.readyLeg();
      delay(1000);
      hasReady = true;
    }
    Doggo.climbRamp();
  } else if (int(differencePitch) > -10 && int(differencePitch) <= 10 && isClimb) {
    Doggo.climbRamp();
  } else if (int(differencePitch) > 10 && isClimb) {
    previousMillis = millis();
    while(int(differencePitch) > 10) {
      if (millis() - previousMillis > interval) {
        isDescend = true;
        isClimb = false;
        hasReady = false;
        break;
      }

      Doggo.climbRamp();

      getCurrentGyro(&pitch, &yaw);
      differencePitch = initialPitch - pitch;
    }
  } else if (int(differencePitch) > 10 && isDescend) {
    if (!hasReady) {
      Doggo.readyLeg2();
      delay(1000);
      hasReady = true;
    }

    Doggo.downRamp();
  } else if (int(differencePitch) >= 0 && int(differencePitch) <= 10 && isDescend) {
    previousMillis = millis();
    while(int(differencePitch) >= 0 && int(differencePitch) <= 10) {
      if (millis() - previousMillis > interval) {
        isDescend = false;
        hasReady = false;
        break;
      }

      Doggo.downRamp();

      getCurrentGyro(&pitch, &yaw);
      differencePitch = initialPitch - pitch;
    }
  } else {
    if (!hasReady) {
      Doggo.readyLeg();
      delay(1000);
      hasReady = true;
      isWalk = true;
    }

    Doggo.walk();
  }


  /*
  if (int(differencePitch) <= -10) {
    if (isClimb) {
      if (!hasClimb) {
        Doggo.readyLeg();
        delay(1000);
        hasClimb = true;
        hasStart = false;
      }

      Doggo.climbRamp();
    } else {
      previousMillis = millis();
      while (int(differencePitch <= -10) && !isClimb) {
        if (millis() - previousMillis > interval) {
          isClimb = true;
          break;
        }

        Doggo.walk();

        getCurrentGyro(&pitch, &yaw);
        differencePitch = initialPitch - pitch;
      }
    }
  } else if (int(differencePitch) > -10 && int(differencePitch) < 15 && isClimb) {
    Doggo.climbRamp();
  } else if (int(differencePitch) >= 15 && isClimb) {
    if (isDescend) {
      if (!hasDescend) {
        Doggo.readyLeg2();
        delay(1000);
        hasDescend = true;
        hasClimb = false;
      }
    
      Doggo.downRamp();
    } else {
      previousMillis = millis();
      while(int(differencePitch) >= 10 && !isDescend) {
        if (millis() - previousMillis > interval) {
          isDescend = true;
          isClimb = false;
          break;
        }

        Doggo.climbRamp();

        getCurrentGyro(&pitch, &yaw);
        differencePitch = initialPitch - pitch;
      }
    }
  } else if (int(differencePitch) > -10 && int(differencePitch) < 15 && hasDescend){
    if (isWalk) {
      if(!hasStart) {
        Doggo.readyLeg();
        delay(1000);
        Doggo.initialLift();
        hasStart = true;
      }

      Doggo.walk();
    } else {
      previousMillis = millis();
      while(int(differencePitch) > -10 && int(differencePitch) < 15 && hasDescend) {
        if (millis() - previousMillis > interval) {
          isWalk = true;
          isDescend =false;
          break;
        }

        Doggo.walk();

        getCurrentGyro(&pitch, &yaw);
        differencePitch = initialPitch - pitch;
      }
    }
  } 
  */
    void firstLeg3() {
      int pos = 30;
      int rev = 50;

      for (pos; pos <= 50; pos += 1) {
        M1.write(pos + err[0]);
        M2.write(rev - err[1]);
        rev++;
        delay(speed);
      }
    }
    void specialEDM31() {
      int pos = 30;
      int rev = 50;

      int pos_2 = 70;
      int rev_2 = 90;

      int rev_3 = 70;
      int pos_4 = 50;

      for (rev_3; rev_3 >= 30; rev_3 -= 1) {
        if (pos <= 50) {
          M5.write(pos + err[4]); // 50
          M6.write(rev - err[5]); // 70
          M3.write(pos_2 + err[2]); // 50
          M4.write(rev_2 - err[3]); // 70
        }
        M2.write(rev_3 - err[1]); // 30
        M7.write(pos_4 + err[6]); // 90
        pos++;
        rev++;
        pos_2--;
        rev_2--;
        pos_4++;
        delay(speed);
      }    
    }

    void specialEDM42() {
      int pos = 10;
      int rev = 30;

      int pos_2 = 90;
      int rev_2 = 110;

      int pos_3 = 50;
      int rev_4 = 70;

      for (pos_3; pos_3 >= 10; pos_3 -= 1) {
        if (pos <= 30) {
          M1.write(pos + err[0]); // 30
          M2.write(rev - err[1]); // 50
          M7.write(pos_2 + err[6]); // 110
          M8.write(rev_2 - err[7]); // 110
        }
        M5.write(pos_3 + err[4]); // 
        M4.write(rev_4 - err[3]);
        pos++;
        rev++;
        pos_2--;
        rev_2--;
        rev_4++;
        delay(speed);
      }   
    }

    void firstLift() {
      int pos = 50;
      int rev = 70;

      for (pos; pos >= 30; pos -= 1) {
        M1.write(pos + err[0]);
        M2.write(rev - err[1]);
        rev++;
        delay(speed);
      }
    }

    void firstLift1() {
      int pos = 50;
      int rev = 70;
      
      for (pos; pos >= 40; pos -=1) {
        M1.write(pos + err[0]);
        M2.write(rev - err[1]);
        rev++;
        delay(speed);
      }
    }



    void firstLeg1() {
      int pos = 30;
      int rev = 90;

      for (pos; pos >= 10; pos -= 1) {
        M1.write(pos + err[0]);
        M2.write(rev - err[1]);
        rev--;
        delay(speed);
      }
    }

    void firstLeg2() {
      int pos = 10;
      int rev = 70;

      for (pos; pos <= 30; pos += 1) {
        M1.write(pos + err[0]);
        M2.write(rev - err[1]);
        rev--;
        delay(speed);
      }
    } 

    void firstLeg3() {
      int pos = 30;
      int rev = 50;

      for (pos; pos <= 50; pos += 1) {
        M1.write(pos + err[0]);
        M2.write(rev - err[1]);
        rev++;
        delay(speed);
      }
    }

    void thirdLift() {
      int pos = 30;
      int rev = 90;

      for (pos; pos <= 50; pos += 1) {
        M5.write(pos + err[4]);
        M6.write(rev - err[5]);
        rev--;
        delay(speed);
      }
    }

    void thirdLeg() {
      int pos = 70;

      for (pos; pos >= 30; pos -= 1) {
        M5.write(pos + err[4]);
        delay(speed);
      }
    } 

    void thirdLeg2() {
      int rev = 90;
      
      for (rev; rev >= 50; rev -= 1) {
        M6.write(rev - err[5]);
        delay(speed);
      }
    }


    void secondLift() {
      int pos = 50;
      int rev = 70;

      for (pos; pos >= 30; pos -= 1) {
        M3.write(pos + err[2]);
        M4.write(rev - err[3]);
        rev++;
        delay(speed);
      }
    }

    void secondLift1() {
      int pos = 50;
      int rev = 70;

      for (pos; pos >= 40; pos -= 1) {
        M3.write(pos + err[2]);
        M4.write(rev - err[3]);
        rev++;
        delay(speed);
      }
    }

    void secondBack() {
      int pos = 40;
      int rev = 80;

      for (pos; pos <= 50; pos += 1) {
        M3.write(pos + err[2]);
        M4.write(rev - err[3]);
        rev--;
        delay(speed);
      }
    }

    void firstBack() {
      int pos = 40;
      int rev = 80;

      for (pos; pos <= 50; pos += 1) {
        M1.write(pos + err[0]);
        M2.write(rev - err[1]);
        rev--;
        delay(speed);
      }
    }
    void secondLeg1() {
      int pos = 30;
      int rev = 90;
      for (pos; pos <= 50; pos += 1) {
        M3.write(pos + err[2]);
        M4.write(rev - err[3]);
        rev++;
        delay(speed);
      }
    } 

    void secondLeg2() {
      int pos = 50;
      int rev = 110;
      for (pos; pos <= 70; pos += 1) {
        M3.write(pos + err[2]);
        M4.write(rev - err[3]);
        rev--;
        delay(speed);
      }
    }

    void secondLeg3() {
      int pos = 70;
      int rev = 90;

      for (pos; pos >= 50; pos -= 1) {
        M3.write(pos + err[2]);
        M4.write(rev - err[3]);
        rev--;
        delay(speed);
      }
    }

    void fourthLift2() {
      int pos = 50;
      int rev = 70;

      for (pos; pos >= 40; pos -= 1) {
        M7.write(pos + err[6]);
        M8.write(rev - err[7]);
        rev++;
        delay(speed);
      }
    }

    void fourthBack() {
      int pos = 40;
      int rev = 80;

      for (pos; pos <= 50; pos += 1) {
        M7.write(pos + err[6]);
        M8.write(rev - err[7]);
        rev--;
        delay(speed);
      }
    }

    void thirdLift2() {
      int pos = 50;
      int rev = 70;

      for (pos; pos >= 40; pos -= 1) {
        M5.write(pos + err[4]);
        M6.write(rev - err[5]);
        rev++;
        delay(speed);
      }
    }

    void thirdBack() {
      int pos = 40;
      int rev = 80;

      for (pos; pos <= 50; pos += 1) {
        M5.write(pos + err[4]);
        M6.write(rev - err[5]);
        rev--;
        delay(speed);
      }
    }
    void fourthLift() {
      int pos = 30;
      int rev = 90;

      for (pos; pos <= 50; pos += 1) {
        M7.write(pos + err[6]);
        M8.write(rev - err[7]);
        rev--;
        delay(speed);
      }
    }

    void fourthLeg() {
      int rev = 50;

      for (rev; rev <= 90; rev += 1) {
        M8.write(rev - err[7]);
        delay(speed);
      }
    }

    void fourthLeg2() {
      int pos = 30;

      for (pos; pos <= 70; pos += 1) {
        M7.write(pos + err[6]);
        delay(speed);
      }
    }

    void repositionThird() {
      int pos = 70;
      int rev = 90;

      for (pos; pos >= 30; pos -= 1) {
        M5.write(pos + err[4]);
        delay(speed);
      }
    }

    void repositionThird1() {
      int pos = 30;
      int rev = 90;

      for (pos; pos <= 50; pos += 1) {
        M5.write(pos + err[4]);
        M6.write(rev - err[5]);
        rev--;
        delay(speed);
      }
    }

    void repositionFourth() {
      int pos = 30;
      int rev = 50;

      for (rev; rev <= 90; rev += 1) {
        M8.write(rev - err[7]);
        delay(speed);
      }
    }

    void repositionFourth1() {
      int pos = 30;
      int rev = 90;

      for (pos; pos <= 50; pos += 1) {
        M7.write(pos + err[6]);
        M8.write(rev - err[7]);
        rev--;
        delay(speed);
      }
    }

    void allForward() {
      int pos = 10;
      int rev = 70;
      
      int pos_2 = 50;
      int rev_2 = 110;

      int pos_3 = 30;
      int rev_3 = 90;

      int pos_4 = 30;
      int rev_4 = 90;

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

    void allForward2() {
      int pos = 30;
      int rev = 50;
      
      int pos_2 = 70;
      int rev_2 = 90;

      int pos_3 = 50;
      int rev_3 = 70;

      int pos_4 = 50;
      int rev_4 = 70;

      for (pos_3; pos_3 <= 70; pos_3 += 1) {
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

  private:
    Servo M1, M2, M3, M4, M5, M6, M7, M8;
    int hertz, min_pulse, max_pulse;
    int speed;
};

#endif
    
    */