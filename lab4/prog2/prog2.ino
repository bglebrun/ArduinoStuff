int rightWheel = 5;
int leftWheel = 6;
int leftBias = 255;
int rightBias = 255;
int delayTime = 1000;

#include "SR04.h"
#define TRIG_PIN 12
#define ECHO_PIN 11
SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
long dist;

void setup() {
  // put your setup code here, to run once:
  pinMode(leftWheel, OUTPUT);
  pinMode(rightWheel, OUTPUT);
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  dist = sr04.Distance();
  if (dist < 30) {
    leftTurn();
  } else if (dist < 15) {
    stopWheels();
  } else {
    forwardWheels();
  }
  //delay(delayTime);
  //stopWheels();
  //delay(delayTime);
}

void forwardWheels() {
  analogWrite(leftWheel, leftBias);
  analogWrite(rightWheel, rightBias);
}

void stopWheels() {
  analogWrite(leftWheel, 0);
  analogWrite(rightWheel, 0);
}

void leftTurn() {
  analogWrite(leftWheel, leftBias);
  analogWrite(rightWheel, 0);
}

void rightTurn() {
  analogWrite(rightWheel, rightBias);
  analogWrite(leftWheel, 0);
}

