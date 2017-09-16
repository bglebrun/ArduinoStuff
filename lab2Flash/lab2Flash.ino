const int SWa = 2;
const int SWb = 3;
const int LEDx = 11;
const int LEDy = 12;

const int PUSHED = HIGH;
const int LED_on = LOW;
const int LED_off = HIGH;

int buttonStateX = 0;
int buttonStateY = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(LEDx, OUTPUT);
  pinMode(LEDy, OUTPUT);
  pinMode(SWa, INPUT);
  pinMode(SWb, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonStateX = digitalRead(SWa);
  buttonStateY = digitalRead(SWb);

  if ((buttonStateX != PUSHED) && (buttonStateY != PUSHED)) {
    digitalWrite(LEDx, LED_on);
    digitalWrite(LEDy, LED_off);
    delay(500);

    digitalWrite(LEDx, LED_off);
    digitalWrite(LEDy, LED_on);
    delay(500);
  } else {
    digitalWrite(LEDx, buttonStateX);
    digitalWrite(LEDy, buttonStateY);
  }
}
