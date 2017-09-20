const int leftMotorSpeedPin = 5;
const int leftMotorControlA1Pin = 10;
const int leftMotorControlA2Pin = 9;

const int rightMotorSpeedPin = 6;
const int rightMotorControlA3Pin = 8;
const int rightMotorControlA4Pin = 7;

int leftMotorSpeed = 230;
int rightMotorSpeed = 255;

// const int biasSwitch = A0;

void setup() {
  // put your setup code here, to run once:
  pinMode(leftMotorSpeedPin, OUTPUT);
  pinMode(leftMotorControlA1Pin, OUTPUT);
  pinMode(leftMotorControlA2Pin, OUTPUT);
  pinMode(rightMotorSpeedPin, OUTPUT);
  pinMode(rightMotorControlA3Pin, OUTPUT);
  pinMode(rightMotorControlA4Pin, OUTPUT);
  //pinMode(biasSwitch, INPUT);

  //Serial.begin(9600);
  
}

void loop() {
  //leftMotorSpeed = analogRead(biasSwitch) / 1023.0 * 255.0;
  // set left motor CCW
  digitalWrite(leftMotorControlA1Pin, HIGH);
  digitalWrite(leftMotorControlA2Pin, LOW);
  // set left motor speed
  analogWrite(leftMotorSpeedPin, leftMotorSpeed);

  //delay(3000);

  // right motor CCW
  digitalWrite(rightMotorControlA3Pin, LOW); // Right motor CCW
  digitalWrite(rightMotorControlA4Pin, HIGH);
  // set right motor direction
  analogWrite(rightMotorSpeedPin, rightMotorSpeed);
  /*
  delay(3000);

  // Motor direction and speed commands (additional)

  digitalWrite(leftMotorControlA1Pin, HIGH);
  digitalWrite(leftMotorControlA2Pin, LOW);
  // set left motor speed
  analogWrite(leftMotorSpeedPin, leftMotorSpeed);

  delay(3000);

  // right motor CCW
  digitalWrite(rightMotorControlA3Pin, HIGH); // Right motor CCW
  digitalWrite(rightMotorControlA4Pin, LOW);
  // set right motor direction
  analogWrite(rightMotorSpeedPin, rightMotorSpeed);

  delay(3000);

  analogWrite(rightMotorSpeedPin, 0);
  analogWrite(leftMotorSpeedPin, 0);

  delay(3000);
  */
  //Serial.println(leftMotorSpeed);
}
