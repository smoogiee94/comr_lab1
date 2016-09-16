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
  LServo.write(100);
  RServo.write(85);
  delay(60000);
}
