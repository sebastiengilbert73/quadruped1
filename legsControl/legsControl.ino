#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

#define MG996RSERVOMIN 150
#define MG996RSERVOMAX 650

uint8_t frontLeftShoulderNdx = 0;
uint8_t frontLeftElbowNdx = 1;
uint8_t frontLeftWristNdx = 2;

uint8_t frontRightShoulderNdx = 4;
uint8_t frontRightElbowNdx = 5;
uint8_t frontRightWristNdx = 6;


Adafruit_PWMServoDriver servoDriver = Adafruit_PWMServoDriver();


void setup()
{
  servoDriver.begin();
  servoDriver.setPWMFreq(60);
  Serial.begin(9600);
  Serial.println("legsControl running!");

  servoDriver.setPWM(frontLeftShoulderNdx, 0, map(90, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  delay(100);
  servoDriver.setPWM(frontRightShoulderNdx, 0, map(100, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  delay(500);

  servoDriver.setPWM(frontLeftElbowNdx, 0, map(90, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  delay(100);
  servoDriver.setPWM(frontRightElbowNdx, 0, map(90, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  delay(500);

  servoDriver.setPWM(frontLeftWristNdx, 0, map(130, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  delay(100);
  servoDriver.setPWM(frontRightWristNdx, 0, map(90, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  delay(500);
}

void loop()
{
  servoDriver.setPWM(frontLeftElbowNdx, 0, map(180, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  delay(100);
  servoDriver.setPWM(frontRightElbowNdx, 0, map(180, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  delay(500);

  
}
