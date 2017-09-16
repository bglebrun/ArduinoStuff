int rightWheel = 5;
int leftWheel = 6;

void setup() {
  pinMode(leftWheel, OUTPUT);
  pinMode(rightWheel, OUTPUT);
}

void loop() {
  digitalWrite(leftWheel, HIGH);
  digitalWrite(rightWheel, HIGH);
  delay(1000);
  digitalWrite(leftWheel, LOW);
  digitalWrite(rightWheel, LOW);
  delay(1000);
}
