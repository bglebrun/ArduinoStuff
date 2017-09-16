#include <Bounce2.h>

const int inputPin = 5;
const int ledPin = 13;
int ledValue = LOW;
Bounce bouncer = Bounce();


void setup() {
  // put your setup code here, to run once:
  pinMode(inputPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  bouncer.attach(inputPin);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (bouncer.update() && bouncer.read() == LOW) {
    ledValue = ! ledValue;
    digitalWrite(ledPin, ledValue);
  }
}
