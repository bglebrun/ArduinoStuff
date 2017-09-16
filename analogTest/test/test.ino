const int outPin = 3;

void setup() {
  pinMode(outPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("Enter volts 0  to 5");
}

void loop() {
  if (Serial.available() > 0) {
    float volts = Serial.parseFloat();
    int pwmValue = volts * 255.0 / 5.0;
    analogWrite(outPin, pwmValue);
  }
}
