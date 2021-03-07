#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

#define MG996RSERVOMIN 150
#define MG996RSERVOMAX 650

uint8_t pinNdx = 2;
int gotoAngle = 90;

Adafruit_PWMServoDriver servoDriver = Adafruit_PWMServoDriver();

void setup() 
{
  servoDriver.begin();
  servoDriver.setPWMFreq(60);
  Serial.begin(9600);
  Serial.println("goto running!");

  servoDriver.setPWM(pinNdx, 0, map(gotoAngle, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  delay(100);
}

void loop() 
{

}
