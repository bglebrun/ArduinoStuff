const int button = 2;
const int led = 7;
const int pot = A0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(button, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(led, !digitalRead(button));
  Serial.println(analogRead(pot));
}
