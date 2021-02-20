#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

#define MG996RSERVOMin 150
#define MG996RSERVOMAX 650

Adafruit_PWMServoDriver servoDriver = Adafruit_PWMServoDriver();


void setup()
{
  servoDriver.begin();
  servoDriver.setPWMFreq(60);
  Serial.begin(9600);
  Serial.println("legsControl running!");
}

void loop()
{
  
}
