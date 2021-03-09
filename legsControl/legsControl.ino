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

uint8_t backRightShoulderNdx = 8;
uint8_t backRightElbowNdx = 9;
uint8_t backRightWristNdx = 10;

uint8_t backLeftShoulderNdx = 12;
uint8_t backLeftElbowNdx = 13;
uint8_t backLeftWristNdx = 14;

int frontLeftShoulderCrouch = 85;
int frontRightShoulderCrouch = 110;
int frontLeftElbowCrouch = 0;
int frontRightElbowCrouch = 140;
int frontLeftWristCrouch = 80;
int frontRightWristCrouch = 130;
int backLeftShoulderCrouch = 110;
int backRightShoulderCrouch = 105;
int backLeftElbowCrouch = 90;
int backRightElbowCrouch = 120;
int backLeftWristCrouch = 80;
int backRightWristCrouch = 130;


Adafruit_PWMServoDriver servoDriver = Adafruit_PWMServoDriver();


void setup()
{
  servoDriver.begin();
  servoDriver.setPWMFreq(60);
  Serial.begin(9600);
  Serial.println("legsControl running!");

  

  Crouch();
  delay(2000);
  Stand();
  delay(2000);
  //StretchWrists();
  //delay(2000);
  Step(10);
}

void loop()
{
  
  
}

void Crouch()
{
  Serial.println("Crouch()");
  int delta = 300;

  servoDriver.setPWM(frontLeftShoulderNdx, 0, map(frontLeftShoulderCrouch, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  servoDriver.setPWM(frontRightShoulderNdx, 0, map(frontRightShoulderCrouch, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  servoDriver.setPWM(backLeftShoulderNdx, 0, map(backLeftShoulderCrouch, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  servoDriver.setPWM(backRightShoulderNdx, 0, map(backRightShoulderCrouch, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  delay(delta);
  
  servoDriver.setPWM(frontLeftElbowNdx, 0, map(frontLeftElbowCrouch, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  servoDriver.setPWM(frontRightElbowNdx, 0, map(frontRightElbowCrouch, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  servoDriver.setPWM(backLeftElbowNdx, 0, map(backLeftElbowCrouch, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  servoDriver.setPWM(backRightElbowNdx, 0, map(backRightElbowCrouch, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  delay(delta);

  servoDriver.setPWM(frontLeftWristNdx, 0, map(frontLeftWristCrouch, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  servoDriver.setPWM(frontRightWristNdx, 0, map(frontRightWristCrouch, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  servoDriver.setPWM(backLeftWristNdx, 0, map(backLeftWristCrouch, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  servoDriver.setPWM(backRightWristNdx, 0, map(backRightWristCrouch, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  delay(delta);
}

void Stand()
{
  Serial.println("Stand()");
  int deltaT = 200;

  servoDriver.setPWM(frontLeftWristNdx, 0, map(frontLeftWristCrouch - 60, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  servoDriver.setPWM(frontRightWristNdx, 0, map(frontRightWristCrouch + 60, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  servoDriver.setPWM(backLeftWristNdx, 0, map(backLeftWristCrouch - 60, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  servoDriver.setPWM(backRightWristNdx, 0, map(backRightWristCrouch + 60, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  delay(deltaT);

  /*servoDriver.setPWM(backLeftShoulderNdx, 0, map(backLeftShoulderCrouch - 10, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  servoDriver.setPWM(backRightShoulderNdx, 0, map(backRightShoulderCrouch + 10, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  delay(deltaT);*/

  for (int deltaTheta = 0; deltaTheta <= 60; deltaTheta += 3)
  {
    
    servoDriver.setPWM(frontLeftElbowNdx, 0, map(frontLeftElbowCrouch + deltaTheta, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
    servoDriver.setPWM(frontRightElbowNdx, 0, map(frontRightElbowCrouch - deltaTheta, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  
    servoDriver.setPWM(backLeftElbowNdx, 0, map(backLeftElbowCrouch + deltaTheta, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
    servoDriver.setPWM(backRightElbowNdx, 0, map(backRightElbowCrouch - deltaTheta, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
    delay(deltaT);
  }
  /*for (int deltaTheta = 45; deltaTheta <= 75; deltaTheta += 3)
  {
    
    servoDriver.setPWM(frontLeftElbowNdx, 0, map(frontLeftElbowCrouch + deltaTheta, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
    servoDriver.setPWM(frontRightElbowNdx, 0, map(frontRightElbowCrouch - deltaTheta, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
    delay(deltaT);
  }*/
}

void StretchWrists()
{
  Serial.println("StretchWrists()");
  int deltaT = 100;
  for (int deltaTheta = -60; deltaTheta <= 0; deltaTheta += 3)
  {
    servoDriver.setPWM(backLeftWristNdx, 0, map(backLeftWristCrouch + deltaTheta, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
    servoDriver.setPWM(backRightWristNdx, 0, map(backRightWristCrouch - deltaTheta, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
    delay(deltaT);
  }
  for (int deltaTheta = -60; deltaTheta <= 0; deltaTheta += 3)
  {
    servoDriver.setPWM(frontLeftWristNdx, 0, map(frontLeftWristCrouch + deltaTheta, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
    servoDriver.setPWM(frontRightWristNdx, 0, map(frontRightWristCrouch - deltaTheta, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
    delay(deltaT);
  }
}

void Step(int balanceDeltaTheta)
{
  Serial.println("Step()");
  int deltaT = 200;
  // Balance to the right
  servoDriver.setPWM(frontLeftShoulderNdx, 0, map(frontLeftShoulderCrouch - balanceDeltaTheta, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  servoDriver.setPWM(frontRightShoulderNdx, 0, map(frontRightShoulderCrouch - balanceDeltaTheta, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  servoDriver.setPWM(backLeftShoulderNdx, 0, map(backLeftShoulderCrouch + balanceDeltaTheta, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  servoDriver.setPWM(backRightShoulderNdx, 0, map(backRightShoulderCrouch + balanceDeltaTheta, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  delay(deltaT);
  // Extend left wrists
  servoDriver.setPWM(frontLeftWristNdx, 0, map(frontLeftWristCrouch - 15, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  servoDriver.setPWM(backLeftWristNdx, 0, map(backLeftWristCrouch - 15, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  delay(deltaT);
  // Retract back left wrist and lift back left leg
  servoDriver.setPWM(backLeftWristNdx, 0, map(backLeftWristCrouch - 30, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  servoDriver.setPWM(backLeftElbowNdx, 0, map(backLeftElbowCrouch - 30, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  delay(deltaT);
  // Put back left tip on the ground
  servoDriver.setPWM(backLeftWristNdx, 0, map(backLeftWristCrouch + 90, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  servoDriver.setPWM(backLeftElbowNdx, 0, map(backLeftElbowCrouch - 10, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  delay(2 * deltaT);

  // Retract front left wrist and lift back left leg
  servoDriver.setPWM(frontLeftWristNdx, 0, map(frontLeftWristCrouch - 30, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  servoDriver.setPWM(frontLeftElbowNdx, 0, map(frontLeftElbowCrouch - 30, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  delay(deltaT);
  // Put front left tip on the ground
  servoDriver.setPWM(frontLeftWristNdx, 0, map(frontLeftWristCrouch + 90, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  servoDriver.setPWM(frontLeftElbowNdx, 0, map(frontLeftElbowCrouch - 10, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  delay(deltaT);

  // Raise left legs
  servoDriver.setPWM(backLeftElbowNdx, 0, map(backLeftElbowCrouch, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  servoDriver.setPWM(frontLeftElbowNdx, 0, map(frontLeftElbowCrouch, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  delay(deltaT);

  // Balance to the center
  /*servoDriver.setPWM(frontLeftShoulderNdx, 0, map(frontLeftShoulderCrouch + balanceDeltaTheta, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  servoDriver.setPWM(frontRightShoulderNdx, 0, map(frontRightShoulderCrouch + balanceDeltaTheta, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  servoDriver.setPWM(backLeftShoulderNdx, 0, map(backLeftShoulderCrouch - balanceDeltaTheta, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  servoDriver.setPWM(backRightShoulderNdx, 0, map(backRightShoulderCrouch - balanceDeltaTheta, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  delay(deltaT);*/

  // Extend back right wrist
  servoDriver.setPWM(backRightElbowNdx, 0, map(backRightElbowCrouch - 30, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  servoDriver.setPWM(backRightWristNdx, 0, map(backRightWristCrouch - 30, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  servoDriver.setPWM(frontRightElbowNdx, 0, map(frontRightElbowCrouch - 30, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  servoDriver.setPWM(frontRightWristNdx, 0, map(frontRightWristCrouch - 30, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  delay(deltaT);
  // Retract front right wrist and lift front right leg
  /*servoDriver.setPWM(frontRightWristNdx, 0, map(frontRightWristCrouch + 120, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  servoDriver.setPWM(frontRightElbowNdx, 0, map(frontRightElbowCrouch + 30, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  servoDriver.setPWM(frontRightWristNdx, 0, map(frontRightWristCrouch - 10, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  delay(deltaT);*/
  
  
  /*// Put back left tip on the ground
  servoDriver.setPWM(backRightWristNdx, 0, map(backRightWristCrouch + 90, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  servoDriver.setPWM(backRightElbowNdx, 0, map(backRightElbowCrouch - 10, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  delay(deltaT);*/
  /*servoDriver.setPWM(frontLeftWristNdx, 0, map(frontLeftWristCrouch - 30, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  delay(deltaT);
  servoDriver.setPWM(frontLeftElbowNdx, 0, map(frontLeftElbowCrouch, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  delay(deltaT);*/
  /*servoDriver.setPWM(backLeftShoulderNdx, 0, map(backLeftShoulderCrouch, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  delay(delta);
  servoDriver.setPWM(backRightShoulderNdx, 0, map(backRightShoulderCrouch, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  delay(delta);*/

  // Restore center balance
}
