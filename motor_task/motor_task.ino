#include <Wire.h>
#include <Adafruit_RGBLCDShield.h>
#include <utility/Adafruit_MCP23017.h>
#include <Servo.h>




Adafruit_RGBLCDShield lcd = Adafruit_RGBLCDShield();

#define RED 0x1
#define YELLOW 0x3
#define GREEN 0x2
#define TEAL 0x6
#define BLUE 0x4
#define VIOLET 0x5
#define WHITE 0x7

Servo LServo;
Servo RServo;


void setup() {
  
  LServo.attach(2);
  RServo.attach(3);

  LServo.write(90); 
  RServo.write(90); 
  
  Serial.begin(9600);
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);

  lcd.print("Welcome to Task 3!");
  lcd.setCursor(1, 6);
  lcd.print("    STOP");
  
  lcd.setBacklight(YELLOW);


}

int Select =0;
void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);

  uint8_t buttons = lcd.readButtons();

  if (buttons) {
    delay(200);
    lcd.clear();
    LServo.write(90); 
    RServo.write(90); 

    if (buttons & BUTTON_UP) { //Forward 70 inches, Backward 70 inches

      lcd.print("Forward/Back");
      LServo.write(98); 
      RServo.write(80);   
      delay(7600); // how long would it take to travel 70 inches
      LServo.write(82);
      RServo.write(100); 
     }
    if (buttons & BUTTON_DOWN) { //Square (30 inch sides)   
      lcd.print("Down");
    }
    if (buttons & BUTTON_LEFT) {
      
      lcd.print("Square");
      lcd.setCursor(0,1);
      lcd.print("Turning Left");
      for(int i = 0; i < 4; ++i){
        moveForward();
        turnLeft();
      }        
    }
    if (buttons & BUTTON_RIGHT) {

        lcd.print("Square");
        lcd.setCursor(0,1);
        lcd.print("Turning Right");
        for(int i = 0; i < 4; ++i){
          moveForward();
          turnRight();
        }
    }
  }
}

void turnLeft(){
  LServo.write(88);
  RServo.write(80);
  delay(880);
}

void turnRight(){
  LServo.write(100);
  RServo.write(92);
  delay(880);
}
void moveForward(){
  LServo.write(98); 
  RServo.write(80);
  delay(3257); //how long would it take to travel 30 inches      
}
