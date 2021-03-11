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

int frontLeftShoulderSphinx = 85;
int frontRightShoulderSphinx = 110;
int frontLeftElbowSphinx = 0;
int frontRightElbowSphinx = 140;
int frontLeftWristSphinx = 80;
int frontRightWristSphinx = 130;
int backLeftShoulderSphinx = 110;
int backRightShoulderSphinx = 105;
int backLeftElbowSphinx = 90;
int backRightElbowSphinx = 120;
int backLeftWristSphinx = 80;
int backRightWristSphinx = 130;


Adafruit_PWMServoDriver servoDriver = Adafruit_PWMServoDriver();


void setup()
{
  servoDriver.begin();
  servoDriver.setPWMFreq(60);
  Serial.begin(9600);
  Serial.println("legsControl running!");

  

  Sphinx();
  delay(2000);
  Stand();
  delay(2000);
  //StretchWrists();
  //delay(2000);
  //Step(10);
}

void loop()
{
  
  
}

void Sphinx()
{
  Serial.println("Crouch()");
  int delta = 300;

  servoDriver.setPWM(frontLeftShoulderNdx, 0, map(frontLeftShoulderSphinx, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  servoDriver.setPWM(frontRightShoulderNdx, 0, map(frontRightShoulderSphinx, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  servoDriver.setPWM(backLeftShoulderNdx, 0, map(backLeftShoulderSphinx, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  servoDriver.setPWM(backRightShoulderNdx, 0, map(backRightShoulderSphinx, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  delay(delta);
  
  servoDriver.setPWM(frontLeftElbowNdx, 0, map(frontLeftElbowSphinx, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  servoDriver.setPWM(frontRightElbowNdx, 0, map(frontRightElbowSphinx, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  servoDriver.setPWM(backLeftElbowNdx, 0, map(backLeftElbowSphinx, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  servoDriver.setPWM(backRightElbowNdx, 0, map(backRightElbowSphinx, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  delay(delta);

  servoDriver.setPWM(frontLeftWristNdx, 0, map(frontLeftWristSphinx, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  servoDriver.setPWM(frontRightWristNdx, 0, map(frontRightWristSphinx, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  servoDriver.setPWM(backLeftWristNdx, 0, map(backLeftWristSphinx, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  servoDriver.setPWM(backRightWristNdx, 0, map(backRightWristSphinx, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  delay(delta);
}

void Stand()
{
  Serial.println("Stand()");
  int deltaT = 200;

  servoDriver.setPWM(frontLeftWristNdx, 0, map(frontLeftWristSphinx - 60, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  servoDriver.setPWM(frontRightWristNdx, 0, map(frontRightWristSphinx + 60, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  servoDriver.setPWM(backLeftWristNdx, 0, map(backLeftWristSphinx - 60, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  servoDriver.setPWM(backRightWristNdx, 0, map(backRightWristSphinx + 60, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  delay(deltaT);

  for (int deltaTheta = 0; deltaTheta <= 60; deltaTheta += 3)
  {
    
    servoDriver.setPWM(frontLeftElbowNdx, 0, map(frontLeftElbowSphinx + deltaTheta, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
    servoDriver.setPWM(frontRightElbowNdx, 0, map(frontRightElbowSphinx - deltaTheta, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  
    servoDriver.setPWM(backLeftElbowNdx, 0, map(backLeftElbowSphinx + deltaTheta, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
    servoDriver.setPWM(backRightElbowNdx, 0, map(backRightElbowSphinx - deltaTheta, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
    delay(deltaT);
  }
}

void StretchWrists()
{
  Serial.println("StretchWrists()");
  int deltaT = 100;
  for (int deltaTheta = -60; deltaTheta <= 0; deltaTheta += 3)
  {
    servoDriver.setPWM(backLeftWristNdx, 0, map(backLeftWristSphinx + deltaTheta, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
    servoDriver.setPWM(backRightWristNdx, 0, map(backRightWristSphinx - deltaTheta, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
    delay(deltaT);
  }
  for (int deltaTheta = -60; deltaTheta <= 0; deltaTheta += 3)
  {
    servoDriver.setPWM(frontLeftWristNdx, 0, map(frontLeftWristSphinx + deltaTheta, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
    servoDriver.setPWM(frontRightWristNdx, 0, map(frontRightWristSphinx - deltaTheta, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
    delay(deltaT);
  }
}

void Step(int balanceDeltaTheta)
{
  Serial.println("Step()");
  int deltaT = 200;
  // Balance to the right
  servoDriver.setPWM(frontLeftShoulderNdx, 0, map(frontLeftShoulderSphinx - balanceDeltaTheta, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  servoDriver.setPWM(frontRightShoulderNdx, 0, map(frontRightShoulderSphinx - balanceDeltaTheta, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  servoDriver.setPWM(backLeftShoulderNdx, 0, map(backLeftShoulderSphinx + balanceDeltaTheta, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  servoDriver.setPWM(backRightShoulderNdx, 0, map(backRightShoulderSphinx + balanceDeltaTheta, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  delay(deltaT);
  // Extend left wrists
  servoDriver.setPWM(frontLeftWristNdx, 0, map(frontLeftWristSphinx - 15, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  servoDriver.setPWM(backLeftWristNdx, 0, map(backLeftWristSphinx - 15, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  delay(deltaT);
  // Retract back left wrist and lift back left leg
  servoDriver.setPWM(backLeftWristNdx, 0, map(backLeftWristSphinx - 30, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  servoDriver.setPWM(backLeftElbowNdx, 0, map(backLeftElbowSphinx - 30, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  delay(deltaT);
  // Put back left tip on the ground
  servoDriver.setPWM(backLeftWristNdx, 0, map(backLeftWristSphinx + 90, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  servoDriver.setPWM(backLeftElbowNdx, 0, map(backLeftElbowSphinx - 10, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  delay(2 * deltaT);

  // Retract front left wrist and lift back left leg
  servoDriver.setPWM(frontLeftWristNdx, 0, map(frontLeftWristSphinx - 30, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  servoDriver.setPWM(frontLeftElbowNdx, 0, map(frontLeftElbowSphinx - 30, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  delay(deltaT);
  // Put front left tip on the ground
  servoDriver.setPWM(frontLeftWristNdx, 0, map(frontLeftWristSphinx + 90, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  servoDriver.setPWM(frontLeftElbowNdx, 0, map(frontLeftElbowSphinx - 10, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  delay(deltaT);

  // Raise left legs
  servoDriver.setPWM(backLeftElbowNdx, 0, map(backLeftElbowSphinx, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  servoDriver.setPWM(frontLeftElbowNdx, 0, map(frontLeftElbowSphinx, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  delay(deltaT);

  // Balance to the center
  /*servoDriver.setPWM(frontLeftShoulderNdx, 0, map(frontLeftShoulderSphinx + balanceDeltaTheta, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  servoDriver.setPWM(frontRightShoulderNdx, 0, map(frontRightShoulderSphinx + balanceDeltaTheta, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  servoDriver.setPWM(backLeftShoulderNdx, 0, map(backLeftShoulderSphinx - balanceDeltaTheta, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  servoDriver.setPWM(backRightShoulderNdx, 0, map(backRightShoulderSphinx - balanceDeltaTheta, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  delay(deltaT);*/

  // Extend back right wrist
  servoDriver.setPWM(backRightElbowNdx, 0, map(backRightElbowSphinx - 30, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  servoDriver.setPWM(backRightWristNdx, 0, map(backRightWristSphinx - 30, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  servoDriver.setPWM(frontRightElbowNdx, 0, map(frontRightElbowSphinx - 30, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  servoDriver.setPWM(frontRightWristNdx, 0, map(frontRightWristSphinx - 30, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  delay(deltaT);
  // Retract front right wrist and lift front right leg
  /*servoDriver.setPWM(frontRightWristNdx, 0, map(frontRightWristSphinx + 120, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  servoDriver.setPWM(frontRightElbowNdx, 0, map(frontRightElbowSphinx + 30, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  servoDriver.setPWM(frontRightWristNdx, 0, map(frontRightWristSphinx - 10, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  delay(deltaT);*/
  
  
  /*// Put back left tip on the ground
  servoDriver.setPWM(backRightWristNdx, 0, map(backRightWristSphinx + 90, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  servoDriver.setPWM(backRightElbowNdx, 0, map(backRightElbowSphinx - 10, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  delay(deltaT);*/
  /*servoDriver.setPWM(frontLeftWristNdx, 0, map(frontLeftWristSphinx - 30, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  delay(deltaT);
  servoDriver.setPWM(frontLeftElbowNdx, 0, map(frontLeftElbowSphinx, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  delay(deltaT);*/
  /*servoDriver.setPWM(backLeftShoulderNdx, 0, map(backLeftShoulderSphinx, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  delay(delta);
  servoDriver.setPWM(backRightShoulderNdx, 0, map(backRightShoulderSphinx, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  delay(delta);*/

  // Restore center balance
}
