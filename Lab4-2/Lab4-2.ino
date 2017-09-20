// Name the pins used with the H bridge
const int LeftMotorSpeedPin = 5;
const int LeftMotorControlA1Pin = 10;
const int LeftMotorControlA2Pin = 9;

const int RightMotorSpeedPin = 6;
const int RightMotorControlA3Pin = 8;
const int RightMotorControlA4Pin = 7;

int leftMotorBias = 230;
int rightMotorBias = 255;

int LeftMotorSpeed; // PWM values from 0 to 255
int RightMotorSpeed;

enum motorType {LEFT_MOTOR, RIGHT_MOTOR};
enum controlType {CW, CCW, STOP, COAST};

//Function initializes the H-bridge:  sets the digital pins as output
void hBridgeInit (void) {
  pinMode(LeftMotorSpeedPin, OUTPUT);
  pinMode(LeftMotorControlA1Pin, OUTPUT);
  pinMode(LeftMotorControlA2Pin, OUTPUT);
  pinMode(RightMotorSpeedPin, OUTPUT);
  pinMode(RightMotorControlA3Pin, OUTPUT);
  pinMode(RightMotorControlA4Pin, OUTPUT);
}

// Function to control the specified left or right motor
void hBridge (motorType motor, controlType control) {
  switch (motor) {
    case LEFT_MOTOR:
      switch (control) {
        case CW:
          // set the Left Motor CW
          digitalWrite(LeftMotorControlA1Pin, LOW);   // sets the Left Motor CW
          digitalWrite(LeftMotorControlA2Pin, HIGH);
          break;
        case CCW:
          // set the Left Motor CCW
          digitalWrite(LeftMotorControlA1Pin, HIGH);   // sets the Left Motor CCW
          digitalWrite(LeftMotorControlA2Pin, LOW);
          break;
        case STOP:
          // set the Left Motor stop
          analogWrite(LeftMotorSpeedPin, leftMotorBias);        // set Left Motor enable high for braking
          digitalWrite(LeftMotorControlA1Pin, LOW);
          digitalWrite(LeftMotorControlA2Pin, LOW);
          break;
        case COAST:
          // set Left Motor Speed to 0 for coast.  Control pins are don't care
          analogWrite(LeftMotorSpeedPin, 0);
          break;
        default:
          // Should never get here
          break;
      }
    case RIGHT_MOTOR:
     /* Your code here for right motor */
     switch(control) {
      case CW:
        digitalWrite(RightMotorControlA3Pin, LOW);
        digitalWrite(RightMotorControlA4Pin, HIGH);
        break;
      case CCW:
        digitalWrite(RightMotorControlA3Pin, HIGH);
        digitalWrite(RightMotorControlA4Pin, LOW);
        break;
      case STOP:
        analogWrite(RightMotorSpeedPin, rightMotorBias);
        digitalWrite(RightMotorControlA3Pin, LOW);
        digitalWrite(RightMotorControlA4Pin, LOW);
        break;
      case COAST:
        analogWrite(RightMotorSpeedPin, 0);
        break;
      default:
        // Dun goofed my dude
        break;
     }
     break;
    default:
     break;
  }
}

void setup() {
  // put your setup code here, to run once:
  hBridgeInit();
  
  LeftMotorSpeed = 230;    // Initial speed
  RightMotorSpeed = 255;  // Initial speed
  
  hBridge(LEFT_MOTOR, CW);
  hBridge(RIGHT_MOTOR, CW);
  
  // set initial Left Motor Speed
  analogWrite(LeftMotorSpeedPin, LeftMotorSpeed);
  // set initial Right Motor Speed
  analogWrite(RightMotorSpeedPin, RightMotorSpeed);
}

void loop() {
  /* Your code here to control the robot in a timed path including forward and reverse */
 spinLeft();
 delay(3000);
 spinRight();
 delay(3000);
 forward();
 delay(3000);
}

void spinLeft() {
  hBridge(LEFT_MOTOR, CCW);
  hBridge(RIGHT_MOTOR, CW);
}

void spinRight() {
  hBridge(RIGHT_MOTOR, CCW);
  hBridge(LEFT_MOTOR, CW);
}

void forward() {
  hBridge(RIGHT_MOTOR, CW);
  hBridge(LEFT_MOTOR, CW);
}

