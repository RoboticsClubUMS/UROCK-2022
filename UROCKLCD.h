#ifndef UROCKLCD_H
#define UROCKLCD_H

#include <LiquidCrystal_I2C.h>

#define SDA 21
#define SCL 22
#define COLUMN 16
#define ROW 4


LiquidCrystal_I2C lcd(0x27, COLUMN, ROW);

void setupLCD() {
  lcd.init();
  lcd.backlight();
}

void displayLCD(int pitch, int yaw, int distance, String mode) {
  lcd.setCursor(0, 0);
  lcd.printf("Pitch:%d", pitch);
  lcd.setCursor(10, 0);
  lcd.printf("Yaw:%d", yaw);
  lcd.setCursor(0,1);
  lcd.printf("SunXL:%d", 0);
  lcd.setCursor(10, 1);
  lcd.printf("SunXR:%d", 0);
  lcd.setCursor(0, 2);
  lcd.printf("Distance: %dcm", distance);
  lcd.setCursor(0, 3);
  lcd.printf("Mode:%s", mode);
}

void calculatingLCD() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("CALCULATING");
}



#endif