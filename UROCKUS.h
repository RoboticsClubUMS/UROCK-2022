#ifndef UROCKUS_H
#define UROCKUS_H

#define TRIG 2
#define ECHO 4
#define SOUND_SPEED 0.034
#define CM_TO_INCH 0.393701

long duration;
float distanceCM;
float distanceInch;

void setupUS() {
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
}

float getUS() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  duration = pulseIn(ECHO, HIGH);
  distanceCM = duration * SOUND_SPEED/2;
  

  return distanceCM;
}

#endif