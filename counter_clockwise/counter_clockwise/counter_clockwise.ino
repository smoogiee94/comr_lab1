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
  LServo.write(98);
  RServo.write(80);
  delay(7500);
  LServo.write(82);
  RServo.write(100);
  delay(7500);
}
