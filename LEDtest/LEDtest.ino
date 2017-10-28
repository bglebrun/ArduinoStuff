void setup() {
  // put your setup code here, to run once:

}

/*
 * A3 - Blue - pushbak
 * A4 - Red - outbound
 * A5 - Green - inbound
 */
void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(A5, 1023);
  delay(1000);
  analogWrite(A5, 0);
  delay(1000);
}
