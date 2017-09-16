#include <avr/pgmspace.h>

const int dotDelay = 80;
const int ledPin = 12;
const int maxLen = 4;

PROGMEM const char letters[26][maxLen] = {
  ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",
  ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", // J-R
  "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." // S-Z 
};

char* numbers[] = { "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----."};

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("Enter code: ");
}


void loop() {
  char ch;
  char sequence[maxLen];
  if (Serial.available() > 0) {
    ch = Serial.read();
    if (ch >= 'a' && ch <= 'z') {
      memcpy_P(&sequence, letters[ch - 'a'], maxLen);
      flashSequence(sequence);
    } else if (ch >= 'A' && ch <= 'Z') {
      memcpy_P(&sequence, letters[ch - 'A'], maxLen);
      flashSequence(sequence);
    } else if (ch >= '0' && ch <= '9') {
      memcpy_P(&sequence, numbers[ch - '0'], maxLen);
      flashSequence(sequence);
    } else if(ch == ' ') {
      delay(dotDelay * 4);
    }
  }
}


void flashSequence(char* sequence) {
  int i = 0;
  while (sequence[i] != '\0'){
    flashDotOrDash(sequence[i]);
    i++;
  }
  delay(dotDelay * 3);
}

void flashDotOrDash(char dotOrDash) {
  digitalWrite(ledPin, HIGH);
  if (dotOrDash == '.') {
    delay(dotDelay);
  } else {
    delay(dotDelay * 3);
  }
  digitalWrite(ledPin, LOW);
  delay(dotDelay);
}

