// Must install the timer interrupt library from 
// https://code.google.com/archive/p/arduino-timerone/downloads 
#include <TimerOne.h> 
// 2/27/2017 M. Batchelder EE/ME/CENG 351 Mechatronics 
//  When line on rotating disk appears stationary there are N counts i.e. N counts/rev 
//  rev/min = 1 / (N counts/rev * T sec/count * 1 min/60 sec) 
//          = 1 / ((N * T / 60) min/rev) 
//          = 60 / (N * T)  rev/min 
//          = (60 * Fs / N) rev/min 
//          = (60 * Fs / ADC) rpm 
//  
 
#define T   (0.0001)       // Sample interval in seconds 
#define Fs  (1/T)          // Sample frequency 
#define PERIOD (T*1000000) // Period in microseconds 
 
// For blinking LED 
#define HALF_SECOND (0.5/T)  // 0.5 seconds / T = counts to reach 1/2 second 
#define ledPin 13 
#define ONE_MS (0.001/T)     //  
#define LED_ON_TIME (ONE_MS*1)   //  
 
const int strobePin = 9; 
const int analogPin = 0; 
const int pushButtonPin = 8; 
 
unsigned int blinkCount, count; 
int ledOnCount; 
int ledOnTime; 
 
 
void timerIsr() {   
  blinkCount++; // used by background code in main to blink an LED   
  count++; // used for strobe LED blink   
  if (count > ledOnCount) {     
    // Strobe LED on     
    digitalWrite(strobePin, HIGH); //PORTDSET = 0X01;     
    if (count > (ledOnCount + LED_ON_TIME)) {       
      // Strobe LED off       
      digitalWrite(strobePin, LOW); //PORTDCLR = 0X01;       
      count = 0;
    }
  }
}
 
void setup() {   
  // put your setup code here, to run once:   
  pinMode(ledPin, OUTPUT);   
  pinMode(strobePin, OUTPUT);   
  pinMode(pushButtonPin, INPUT_PULLUP);   
  Serial.begin(115200);      //  setup serial   
  Timer1.initialize(PERIOD); // set a timer of length in microseconds   
  Timer1.attachInterrupt( timerIsr ); // attach the service routine here
}
 
void loop() {   
  // put your main code here, to run repeatedly:   
  int i, rpm, N;   
  i = analogRead(analogPin) * 4;; // ADC value sets rpm which determines time between flashes   
  rpm = i;   
  if (digitalRead(pushButtonPin) == LOW) rpm = 2 * i;   
  if (i == 0) rpm = 1;   
  N = (60.0 / rpm) * 10000; // Number of 100 us counts   
  ledOnCount = N;   
  Serial.print("N = "); 
  Serial.print(N); 
  Serial.print(" rpm = "); 
  Serial.println(rpm);   
  if (blinkCount > HALF_SECOND) {     
    blinkCount = 0;     
    digitalWrite(ledPin, !digitalRead(ledPin));  // toggle state
  }
}

