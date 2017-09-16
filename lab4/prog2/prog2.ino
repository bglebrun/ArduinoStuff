int rightWheel = 5;
int leftWheel = 6;
int leftBias = 255;
int rightBias = 255;
int delayTime = 500;

void setup() {
  // put your setup code here, to run once:
  pinMode(leftWheel, OUTPUT);
  pinMode(rightWheel, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  spinWheels();
  delay(delayTime);
  stopWheels();
  delay(delayTime);
}

void spinWheels() {
  analogWrite(leftWheel, leftBias);
  analogWrite(rightWheel, rightBias);
}

void stopWheels() {
  analogWrite(leftWheel, 0);
  analogWrite(rightWheel, 0);
}
