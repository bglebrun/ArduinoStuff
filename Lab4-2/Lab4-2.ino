// Name the pins used with the H bridge
const int LeftMotorSpeedPin = 5;
const int LeftMotorControlA3Pin =  10;
const int LeftMotorControlA4Pin =  9;
const int RightMotorSpeedPin = 6;
const int RightMotorControlA1Pin =  8;
const int RightMotorControlA2Pin =  7;

int LeftMotorSpeed; // PWM values from 0 to 255
int RightMotorSpeed;

enum motorType {LEFT_MOTOR, RIGHT_MOTOR};
enum controlType {CW, CCW, STOP, COAST};

//Function initializes the H-bridge:  sets the digital pins as output
void hBridgeInit (void) {
  pinMode(LeftMotorSpeedPin, OUTPUT);      
  pinMode(LeftMotorControlA3Pin, OUTPUT);   
  pinMode(LeftMotorControlA4Pin, OUTPUT);  
  pinMode(RightMotorSpeedPin, OUTPUT);      
  pinMode(RightMotorControlA1Pin, OUTPUT);      
  pinMode(RightMotorControlA2Pin, OUTPUT);      
}

// Function to control the specified left or right motor
void hBridge (motorType motor, controlType control) {
  switch (motor) {
    case LEFT_MOTOR:
      switch (control) {
        case CW:
          // set the Left Motor CW
          digitalWrite(LeftMotorControlA3Pin, HIGH);   // sets the Left Motor CW
          digitalWrite(LeftMotorControlA4Pin, LOW);
          break;
        case CCW:
          // set the Left Motor CCW
          digitalWrite(LeftMotorControlA3Pin, LOW);   // sets the Left Motor CCW
          digitalWrite(LeftMotorControlA4Pin, HIGH);
          break;
        case STOP:
          // set the Left Motor stop
          analogWrite(LeftMotorSpeedPin, 255);        // set Left Motor enable high for braking
          digitalWrite(LeftMotorControlA3Pin, LOW);
          digitalWrite(LeftMotorControlA4Pin, LOW);
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
     break;
    default:
     break;
  }
}

void setup() {
  // put your setup code here, to run once:
  hBridgeInit();
  
  LeftMotorSpeed = 128;    // Initial speed
  RightMotorSpeed = 128;  // Initial speed
  
  hBridge(LEFT_MOTOR, CW);
  hBridge(RIGHT_MOTOR, CW);
  
  // set initial Left Motor Speed
  analogWrite(LeftMotorSpeedPin, LeftMotorSpeed);
  // set initial Right Motor Speed
  analogWrite(RightMotorSpeedPin, RightMotorSpeed);
}

void loop() {
  /* Your code here to control the robot in a timed path including forward and reverse */

}
