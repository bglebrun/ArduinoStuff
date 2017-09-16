#include <avr/eeprom.h>

const int maxPasswordSize = 20;
char password[maxPasswordSize];

void setup() {
  // put your setup code here, to run once:
  eeprom_read_block(&password, 0, maxPasswordSize);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Your password is:");
  Serial.println(password);
  Serial.println("Enter a NEW password");
 while (! Serial.available()) {}; 
 int n = Serial.readBytesUntil('\ n', password, maxPasswordSize); 
 password[ n] = '\ 0'; 
 eeprom_write_block( password, 0, maxPasswordSize); 
 Serial.print(" Saved Password: "); 
 Serial.println( password);

}
