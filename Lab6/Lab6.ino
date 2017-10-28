//--------------------------------------------------------- 
// Simple Stepper Motor Driver 
// 4 phase bipolar motor 
// IN1, IN2, IN3, IN4 connect to A, B, C, D defined below 
// IN1, IN2, IN3, IN4 are inputs to driver board 
// A, B, C, D are the LEDs on the driver board 
//---------------------------------------------------------- 
// Define Arduino pins to connect to the driver board 
const int A = 2;    // IN1 
const int B = 3;    // IN2 
const int C = 4;    // IN3 
const int D = 11;    // IN4 
// Number of ms between steps 
const int dly = 2; 
 
void ccw() { 
  digitalWrite(A, HIGH);   digitalWrite(B, LOW);   digitalWrite(C, LOW);   digitalWrite(D, HIGH); 
  delay(dly); 
  digitalWrite(A, LOW);   digitalWrite(B, LOW);   digitalWrite(C, HIGH);  digitalWrite(D, HIGH); 
  delay(dly); 
  digitalWrite(A, LOW);   digitalWrite(B, HIGH);   digitalWrite(C, HIGH);   digitalWrite(D, LOW); 
  delay(dly); 
  digitalWrite(A, HIGH);   digitalWrite(B, HIGH);   digitalWrite(C, LOW);   digitalWrite(D, LOW); 
  delay(dly); 
} 
 
void cw() { 
  digitalWrite(A, HIGH);   digitalWrite(B, HIGH);   digitalWrite(C, LOW);   digitalWrite(D, LOW); 
  delay(dly); 
  digitalWrite(A, LOW);   digitalWrite(B, HIGH);   digitalWrite(C, HIGH);   digitalWrite(D, LOW); 
  delay(dly); 
  digitalWrite(A, LOW);   digitalWrite(B, LOW);   digitalWrite(C, HIGH);   digitalWrite(D, HIGH); 
  delay(dly); 
  digitalWrite(A, HIGH);   digitalWrite(B, LOW);   digitalWrite(C, LOW);   digitalWrite(D, HIGH); 
  delay(dly); 
}
 
 
// the setup function runs once when you press reset or power the board 
void setup() {   
  // initialize digital pins as an output.   
  pinMode(A, OUTPUT);   
  pinMode(B, OUTPUT);   
  pinMode(C, OUTPUT);   
  pinMode(D, OUTPUT); 
} 
 
// the loop function runs over and over again 
void loop() {   
  // Approximately one revolution of the output shaft, then switch directions   
  // motor has 32 steps per rev, gear train about 64:1, 4 steps in sequence 
 
  for (int i = 0; i < 32 * 64 / 4; i++)  
    cw();   
  for (int i = 0; i < 32 * 64 / 4; i++)  
    ccw(); 
} 
