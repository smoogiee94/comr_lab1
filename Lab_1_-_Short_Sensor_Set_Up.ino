
#include <Wire.h>
#include <Adafruit_RGBLCDShield.h>
#include <utility/Adafruit_MCP23017.h>
#define RED 0x1
#define YELLOW 0x3
#define GREEN 0x2
#define TEAL 0x6
#define BLUE 0x4
#define VIOLET 0x5
#define WHITE 0x7

Adafruit_RGBLCDShield lcd = Adafruit_RGBLCDShield();

const int SFSensor = A0;  // Analog input pin that the potentiometer is attached to
const int SLSensor = A1;  // Analog input pin that the potentiometer is attached to
const int SRSensor = A2;  // Analog input pin that the potentiometer is attached to
const int LFSensor = A3;  // Analog input pin that the potentiometer is attached to

float SFValue = 0;    
float SLValue = 0;    
float SRValue = 0;    
float LFValue = 0;    



void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
  lcd.begin(16, 2);
}

void loop() {
  //Clears the lcd and sets cursor to first row, first column
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.setBacklight(BLUE);

  //Prints the Left, Center, Right Identifers on the lcd
  //and sets cursor to second row, first column
  lcd.print("  L     C    R");
  lcd.setCursor(0, 1);

  //Calculates Sensor data
  //prints to the lcd
  SLValue = 12.509 * pow(analogRead(SLSensor)*0.0048875855327468, -1.059) / 2.54;
  if (SLValue > 11.80){
    SLValue = 11.8;
  }
  lcd.print(SLValue);
  lcd.setCursor(6, 1);
  SFValue = 12.509 * pow(analogRead(SFSensor)*0.0048875855327468, -1.059) / 2.54;
  if (SFValue > 11.80){
      SFValue = 59.635 * pow(analogRead(LFSensor)*0.0048875855327468, -1.034) / 2.54;

      if (SFValue > 59){
        SFValue = 59;
    }
  }
  lcd.print(SFValue);
  lcd.setCursor(11, 1);
  SRValue = 12.509 * pow(analogRead(SRSensor)*0.0048875855327468, -1.059) / 2.54;
  if (SRValue > 11.80){
    SRValue = 11.8;
  }
  lcd.print(SRValue);
 
  delay(300);
}
