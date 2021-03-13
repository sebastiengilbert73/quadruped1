#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <ArxContainer.h>

using namespace std;

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
int frontRightElbowSphinx = 120;
int frontLeftWristSphinx = 90;
int frontRightWristSphinx = 130;
int backLeftShoulderSphinx = 110;
int backRightShoulderSphinx = 105;
int backLeftElbowSphinx = 95;
int backRightElbowSphinx = 120;
int backLeftWristSphinx = 80;
int backRightWristSphinx = 130;

int frontLeftWristStand = frontLeftWristSphinx - 60;
int frontRightWristStand = frontRightWristSphinx + 60;
int backLeftWristStand = backLeftWristSphinx - 60;
int backRightWristStand = backRightWristSphinx + 60;
int frontLeftElbowStand = frontLeftElbowSphinx + 60;
int frontRightElbowStand = frontRightElbowSphinx - 60;
int backLeftElbowStand = backLeftElbowSphinx + 60;
int backRightElbowStand = backRightElbowSphinx - 60;

int frontLeftElbowLift = frontLeftElbowStand - 90;
int frontRightElbowLift = frontRightElbowStand + 90;
int backLeftElbowLift = backLeftElbowStand - 90;
int backRightElbowLift = backRightElbowStand + 90;

int frontLeftElbowLanding = frontLeftElbowLift + 30;
int frontRightElbowLanding = frontRightElbowLift -30;
int backLeftElbowLanding = backLeftElbowLift + 30;
int backRightElbowLanding = backRightElbowLift - 30;
int frontLeftWristLanding = frontLeftWristSphinx + 110;
int frontRightWristLanding = frontRightWristSphinx + 0;
int backLeftWristLanding = backLeftWristSphinx + 0;
int backRightWristLanding = backRightWristSphinx + 0;


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

  Step(10);
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

  servoDriver.setPWM(frontLeftWristNdx, 0, map(frontLeftWristStand, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  servoDriver.setPWM(frontRightWristNdx, 0, map(frontRightWristStand, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  servoDriver.setPWM(backLeftWristNdx, 0, map(backLeftWristStand, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  servoDriver.setPWM(backRightWristNdx, 0, map(backRightWristStand, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  delay(deltaT);

  arx::vector<arx::vector<int> > jointNdxStarStopVct;
  jointNdxStarStopVct.push_back(arx::vector<int> {frontLeftElbowNdx, frontLeftElbowSphinx, frontLeftElbowStand});
  jointNdxStarStopVct.push_back(arx::vector<int> {frontRightElbowNdx, frontRightElbowSphinx, frontRightElbowStand});
  jointNdxStarStopVct.push_back(arx::vector<int> {backLeftElbowNdx, backLeftElbowSphinx, backLeftElbowStand});
  jointNdxStarStopVct.push_back(arx::vector<int> {backRightElbowNdx, backRightElbowSphinx, backRightElbowStand});
  SimultaneousMoves(jointNdxStarStopVct, 6, 100);
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
  // Balance to the right and lift back left leg
  arx::vector<arx::vector<int> > jointNdxStarStopVct;
  jointNdxStarStopVct.push_back(arx::vector<int> {frontLeftShoulderNdx, frontLeftShoulderSphinx, frontLeftShoulderSphinx - balanceDeltaTheta});
  jointNdxStarStopVct.push_back(arx::vector<int> {frontRightShoulderNdx, frontRightShoulderSphinx, frontRightShoulderSphinx - balanceDeltaTheta});
  jointNdxStarStopVct.push_back(arx::vector<int> {backLeftShoulderNdx, backLeftShoulderSphinx, backLeftShoulderSphinx + balanceDeltaTheta});
  jointNdxStarStopVct.push_back(arx::vector<int> {backRightShoulderNdx, backRightShoulderSphinx, backRightShoulderSphinx + balanceDeltaTheta});
  jointNdxStarStopVct.push_back(arx::vector<int> {backLeftElbowNdx, backLeftElbowStand, backLeftElbowLift});
  SimultaneousMoves(jointNdxStarStopVct, 6, 100);
  servoDriver.setPWM(backLeftWristNdx, 0, map(backLeftWristSphinx + 110, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
  jointNdxStarStopVct.clear();
  
}

void ElbowAndWrist(uint8_t elbowNdx, uint8_t wristNdx, int elbowTheta1, int elbowTheta2, int wristTheta1, int wristTheta2, int numberOfSteps, int deltaT)
{
  for (int stepNdx = 1; stepNdx <= numberOfSteps; stepNdx++)
  {
    int elbowTheta = elbowTheta1 + stepNdx * (elbowTheta2 - elbowTheta1)/numberOfSteps;
    int wristTheta = wristTheta1 + stepNdx * (wristTheta2 - wristTheta1)/numberOfSteps;
    servoDriver.setPWM(elbowNdx, 0, map(elbowTheta, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
    servoDriver.setPWM(wristNdx, 0, map(wristTheta, 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
    delay(deltaT);
  }
}

void SimultaneousMoves(arx::vector<arx::vector<int> > jointNdxStartStopVct, int numberOfSteps, int deltaT)
{
  for (int stepNdx = 1; stepNdx <= numberOfSteps; stepNdx++)
  {
    double alpha = (double) stepNdx / numberOfSteps;
    for (size_t jointNdxNdx = 0; jointNdxNdx < jointNdxStartStopVct.size(); jointNdxNdx++)
    {
      arx::vector<int> jointNdxStartStop = jointNdxStartStopVct[jointNdxNdx];
      int jointNdx = jointNdxStartStop[0];
      int startTheta = jointNdxStartStop[1];
      int stopTheta = jointNdxStartStop[2];
      servoDriver.setPWM(jointNdx, 0, map(startTheta + alpha * (stopTheta - startTheta), 0, 180, MG996RSERVOMIN, MG996RSERVOMAX));
    }
    delay(deltaT);
  }
}

void Prayer()
{
  int numberOfSteps = 8;
  int deltaT = 100;
  ElbowAndWrist(frontLeftElbowNdx, frontLeftWristNdx, frontLeftElbowSphinx, frontLeftElbowSphinx - 50, frontLeftWristSphinx, frontLeftWristSphinx + 80,
  numberOfSteps, deltaT);
  ElbowAndWrist(frontRightElbowNdx, frontRightWristNdx, frontRightElbowSphinx, frontRightElbowSphinx + 50, frontRightWristSphinx, frontRightWristSphinx - 80,
  numberOfSteps, deltaT);
}

void HoovesOnGround()
{
  arx::vector<arx::vector<int> > jointNdxStarStopVct;
  jointNdxStarStopVct.push_back(arx::vector<int> {frontLeftWristNdx, frontLeftWristSphinx, frontLeftWristSphinx + 100});
  jointNdxStarStopVct.push_back(arx::vector<int> {frontLeftElbowNdx, frontLeftElbowSphinx, frontLeftElbowSphinx - 50});
  jointNdxStarStopVct.push_back(arx::vector<int> {frontRightWristNdx, frontRightWristSphinx, frontRightWristSphinx - 100});
  jointNdxStarStopVct.push_back(arx::vector<int> {frontRightElbowNdx, frontRightElbowSphinx, frontRightElbowSphinx + 50});
  /*jointNdxStarStopVct.push_back(arx::vector<int> {backLeftWristNdx, backLeftWristSphinx, backLeftWristSphinx + 120});
  jointNdxStarStopVct.push_back(arx::vector<int> {backLeftElbowNdx, backLeftElbowSphinx, backLeftElbowSphinx - 30});
  jointNdxStarStopVct.push_back(arx::vector<int> {backRightWristNdx, backRightWristSphinx, backRightWristSphinx - 100});
  jointNdxStarStopVct.push_back(arx::vector<int> {backRightElbowNdx, backRightElbowSphinx, backRightElbowSphinx + 50});*/
  SimultaneousMoves(jointNdxStarStopVct, 8, 200);
}
