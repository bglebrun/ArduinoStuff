int QRE1113_Pin = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int QRE_Value = analogRead(QRE1113_Pin);
  Serial.println(QRE_Value);
  delay(500);
}
