#include <avr/eeprom.h>

void setup() {
  Serial.begin(9600);
  float fl = 1.23;
  eeprom_write_block(&fl, 0, 4);
  float f2 = 0;
  eeprom_read_block(&f2, 0, 4);
  Serial.println(f2);
}

void loop() {
  
}

