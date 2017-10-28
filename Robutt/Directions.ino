void Stop() {
  StopLeftWheel();
  StopRightWheel();
}

void Forward() {
  LeftWheelForward();
  RightWheelForward();
}

void Backward() {
  LeftWheelBackward();
  RightWheelBackward();
}

void StopLeftWheel() {
  DisableLeft();
  digitalWrite(ControlTwoA, LOW);
  digitalWrite(ControlOneA, LOW);
}

void StopRightWheel() {
  DisableRight();
  digitalWrite(ControlThreeA, LOW);
  digitalWrite(ControlFourA, LOW);
}

void EnableLeft() {
  digitalWrite(LeftWheel, HIGH);
}

void DisableLeft() {
  digitalWrite(LeftWheel, LOW);
}

void EnableRight() {
  digitalWrite(RightWheel, HIGH);
}

void DisableRight() {
  digitalWrite(RightWheel, LOW);
}


void LeftWheelHalfFwd() {
  analogWrite(LeftWheel, 127);
  digitalWrite(ControlTwoA, LOW);
  digitalWrite(ControlOneA, HIGH);
}

void RightWheelHalfFwd() {
  analogWrite(RightWheel, 127);
  digitalWrite(ControlThreeA, LOW);
  digitalWrite(ControlFourA, HIGH);
}

void LeftWheelHalfBwd() {
  analogWrite(LeftWheel, 127);
  digitalWrite(ControlTwoA, LOW);
  digitalWrite(ControlOneA, HIGH);
}

void RightWheelHalfBwd() {
  analogWrite(RightWheel, 127);
  digitalWrite(ControlThreeA, HIGH);
  digitalWrite(ControlFourA, LOW);
}

void LeftWheelForward() {
  EnableLeft();
  digitalWrite(ControlTwoA, HIGH);
  digitalWrite(ControlOneA, LOW);
}

void LeftWheelBackward() {
  EnableLeft();
  digitalWrite(ControlTwoA, LOW);
  digitalWrite(ControlOneA, HIGH);
}

void RightWheelForward() {
  EnableRight();
  digitalWrite(ControlThreeA, LOW);
  digitalWrite(ControlFourA, HIGH);
}

void RightWheelBackward() {
  EnableRight();
  digitalWrite(ControlThreeA, HIGH);
  digitalWrite(ControlFourA, LOW);
}

