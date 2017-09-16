#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int analogPin = 0;
int raw = 0;
int Vin = 5;
float Vout = 0;
float R1 = 997;
float R2 = 0;
float buffer = 0;

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
}

void loop() {
  // put your main code here, to run repeatedly:
  raw = analogRead(analogPin);
  if (raw) {
    buffer = raw * Vin;
    Vout = (buffer)/1024.0;
    buffer = (Vin/Vout) - 1;
    R2 = R1 * buffer;

    lcd.setCursor(0, 0);
    lcd.print("Vout: ");
    lcd.print(Vout);

    lcd.setCursor(0, 1);
    lcd.print("R2: ");
    lcd.print(R2);
    delay(1000);
  }
}
