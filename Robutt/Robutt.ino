#include "TimerOne.h"

// Digital I/O
const int Trig = 0;
const int Echo = 1;
const int FrontSwitch = 2;
const int LeftWheel = 3;
const int RightWheel = 4;
const int ControlOneA = 5;
const int ControlTwoA = 6;
const int ControlThreeA = 7;
const int ControlFourA = 8;
const int StepD = 9;
const int StepC = 10;
const int StepB = 11;
const int StepA = 12;

// Analog I/O
const int LeftSwitch = A0;
const int RightSwitch = A1;
const int Blue = A3;
const int Red = A4;
const int Green = A5;

enum steps {pushbak, inbound, outbound};

enum followSide {left, right};

followSide FollowingSide = followSide(left);

steps CurrentStep = steps(pushbak);

bool Flipped;

void setup() {
  
  // Outputs
  pinMode(Trig, OUTPUT);
  pinMode(LeftWheel, OUTPUT);
  pinMode(RightWheel, OUTPUT);
  pinMode(ControlOneA, OUTPUT);
  pinMode(ControlTwoA, OUTPUT);
  pinMode(ControlThreeA, OUTPUT);
  pinMode(ControlFourA, OUTPUT);
  pinMode(StepD, OUTPUT);
  pinMode(StepC, OUTPUT);
  pinMode(StepB, OUTPUT);
  pinMode(StepA, OUTPUT);

  // Inputs
  pinMode(Echo, INPUT);

  // Reversal interrupt
  Timer1.initialize(1500000);
  Timer1.attachInterrupt(turnAround);

  delay(2500);
}

void loop() {
  // put your main code here, to run repeatedly:
  // Forward();
  // delay(5000);
  StepThrough();
  // Inbound();
}

void StepThrough() {
  switch(CurrentStep) {
    
    case pushbak:
      Pushbak();
    break;
    
    case inbound:
      Inbound();
    break;
    
    case outbound:
      Outbound();
    break;
    
    default:
      // We dun fucked up
    break;
  }
}

void Pushbak() {
  analogWrite(Blue, 1023);
  if(getDistance(Trig, Echo) < 3) {
    Turn90();
    CurrentStep = steps(inbound);
  } else {
    Backward();
  }
  analogWrite(Blue, 0);
}

void Inbound() {
  analogWrite(Green, 1023);
  if(digitalRead(FrontSwitch) == HIGH) {
    FollowingSide = followSide(right);
    Timer1.start();
    Flipped = true;
  } else {
    FollowingSide = followSide(left);
  }

  if ( analogRead(LeftSwitch) > (1023/2) && analogRead(RightSwitch) > (1023/2)) {
    if (FollowingSide == followSide(left)) {
      LeftWheelHalfFwd();
    }
    if (FollowingSide == followSide(right)) {
      RightWheelHalfFwd();
    }
  }

  if (getDistance(Trig, Echo) < 15) {
    retrieveCube();
    CurrentStep = steps(outbound);
    if (FollowingSide == followSide(left)) {
      FollowingSide = followSide(right);
    } else {
      FollowingSide = followSide(left);
    }
  }

  Flipped ? Backward() : Forward();
  analogWrite(Green, 0);
}

void Outbound() {
  analogWrite(Red, 1023);
  if(analogRead(FrontSwitch) > (1023/2)) {
    FollowingSide = followSide(right);
    Timer1.start();
    Flipped = true;
  } else {
    FollowingSide = followSide(left);
  }
    
  if ( analogRead(LeftSwitch) > (1023/2) && analogRead(RightSwitch) > (1023/2)) {
    if (FollowingSide == followSide(left)) {
      LeftWheelHalfFwd();
    }
    if (FollowingSide == followSide(right)) {
      RightWheelHalfFwd();
    }
  }

  Flipped ? Backward() : Forward();
  analogWrite(Red, 0);
}

void turnAround() {
  Backward();
  delay(2000);
  Turn180();
  Flipped = false;
}

void retrieveCube() {
  Turn90;
  
  while(getDistance(Trig, Echo) < 90) {
    Forward();
  }
  
  // Loader code goes here
  
  while(getDistance(Trig, Echo) > 5) {
    Backward();
  }
}

long getDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  return (pulseIn(echoPin, HIGH) / 2) / 29.1;
}

