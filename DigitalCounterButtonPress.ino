const int PushButtonPin = 13;
int buttonstate = 0;
#include <SevSeg.h>
SevSeg sevseg;

void setup() {
  pinMode(PushButtonPin, INPUT);
  Serial.begin(9600);
  byte numDigits = 4;
  byte digitPins [] = {A0, A1, A2, A3};
  byte segmentPins[] = {3, 4, 5, 6, 2, 9, 7, 8};
  sevseg.begin(COMMON_CATHODE, numDigits, digitPins, segmentPins);
  int count = 1;
  static unsigned int HoldNumber = 0;
}

void loop() {
  buttonstate = digitalRead(PushButtonPin);
  Serial.println(buttonstate);
  sevseg.refreshDisplay();
  sevseg.setNumber(0);
  if (buttonstate == HIGH) {
    sevseg.setNumber(1);
  } else {
    
  }
}
