#ifndef UROCKSUNX_H
#define UROCKSUNX_H

#include <ESP32Servo.h>

#define lifterPin 10

bool left_line_touched = false;
bool right_line_touched = false;

Servo lifter;

void setupSUNX() {
  lifter.attach(lifterPin);
}

void liftSUNX() {
  lifter.write(90);
}

void downSUNX() {
  lifter.write(0);
}

void leftTouched() {
  left_line_touched = !left_line_touched;
}

void rightTouched() {
  right_line_touched = !right_line_touched;
}

#endif