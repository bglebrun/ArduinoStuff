void Turn180() {
  LeftWheelForward();
  RightWheelBackward();
  delay(800);
  StopLeftWheel();
  StopRightWheel();
}

void Turn90() {
  LeftWheelForward();
  RightWheelBackward();
  delay(600);
  StopLeftWheel();
  StopRightWheel();
}

void WideLeft() {
  StopRightWheel();
  LeftWheelForward();
}

void WideRight() {
  StopLeftWheel();
  RightWheelForward();
}

