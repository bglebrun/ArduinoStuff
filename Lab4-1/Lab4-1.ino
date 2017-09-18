const int leftMotorSpeedPin = 5;
const int leftMotorControlA3Pin = 13;
const int leftMotorControlA4Pin = 9;

const int rightMotorSpeedPin = 6;
const int rightMotorControlA1Pin = 8;
const int rightMotorControlA2Pin = 7;

int leftMotorSpeed = 128;
int rightMotorSpeed = 128;

void setup() {
  // put your setup code here, to run once:
  pinMode(leftMotorSpeedPin, OUTPUT);
  pinMode(leftMotorControlA3Pin, OUTPUT);
  pinMode(leftMotorControlA4Pin, OUTPUT);
  pinMode(rightMotorSpeedPin, OUTPUT);
  pinMode(rightMotorControlA1Pin, OUTPUT);
  pinMode(rightMotorControlA2Pin, OUTPUT);
}

void loop() {
  // set left motor CW
  digitalWrite(leftMotorControlA3Pin, HIGH);
  digitalWrite(leftMotorControlA4Pin, LOW);
  // set left motor speed
  analogWrite(leftMotorSpeedPin, leftMotorSpeed);

  // set right motor direction

  // set right motor speed

  delay(1000);

  // Motor direction and speed commands (additional)
  
}
