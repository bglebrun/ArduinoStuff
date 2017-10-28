// sketch 09_02 
#include <SPI.h> 
#include <Wire.h> 
#include <Adafruit_GFX.h> 
#include <Adafruit_SSD1306.h>
Adafruit_SSD1306 display(4); // pick an unused pin
void setup() { 
  display.begin( SSD1306_SWITCHCAPVCC, 0x3c); // may need to change this
  display.setTextSize(1);
}

void loop() { 
  static int count = 0; 
  display.clearDisplay();
  display.setCursor(0,0);
  display.print("Resistance is futile!");
  display.setCursor(0,10); 
  display.print(count); 
  display.display(); 
  count++;
  if (count > 9999) {
    count = 0; 
  }
  
  delay( 1000);
}


