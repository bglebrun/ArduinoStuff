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
  // set left motor CCW
  digitalWrite(leftMotorControlA3Pin, LOW);
  digitalWrite(leftMotorControlA4Pin, HIGH);
  // set left motor speed
  analogWrite(leftMotorSpeedPin, leftMotorSpeed);

  delay(3000);

  // right motor CCW
  digitalWrite(rightMotorControlA1Pin, LOW); // Right motor CCW
  digitalWrite(rightMotorControlA2Pin, HIGH);
  // set right motor direction
  analogWrite(rightMotorSpeedPin, rightMotorSpeed);

  delay(3000);

  // Motor direction and speed commands (additional)
  
}
