#include <Servo.h>

Servo LServo; 
Servo RServo;

void setup() {
  // put your setup code here, to run once:
  LServo.attach(2);
  RServo.attach(3);
}

void loop() {
  // put your main code here, to run repeatedly:
  LServo.write(90);
  RServo.write(90);
  delay(3000);
  LServo.write(96);
  RServo.write(80);
  delay(12250);
  LServo.write(90);
  RServo.write(90);
  delay(500);
//  LServo.write(80);
//  RServo.write(80);
//  delay(225);
//  LServo.write(90);
//  RServo.write(90);
//  delay(500);
  LServo.write(99);
  RServo.write(80);
  delay(7850);
  LServo.write(90);
  RServo.write(90);
  delay(500);
  LServo.write(100);
  RServo.write(100);
  delay(375);
  LServo.write(90);
  RServo.write(90);
  delay(500);
  LServo.write(99);
  RServo.write(85);
  delay(15000);
  LServo.write(90);
  RServo.write(90);
  delay(500);
  LServo.write(99);
  RServo.write(80);
  delay(7850);
  
}
