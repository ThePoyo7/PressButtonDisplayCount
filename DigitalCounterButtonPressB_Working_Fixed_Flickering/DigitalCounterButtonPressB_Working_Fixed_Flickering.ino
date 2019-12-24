const int PushButtonPin = 13;
int buttonstate = 0;
#include <SevSeg.h>
SevSeg sevseg;

void setup() {
  byte numDigits = 4;
  byte digitPins [] = {A0, A1, A2, A3};
  byte segmentPins[] = {3, 4, 5, 6, 2, 9, 7, 8};
  sevseg.begin(COMMON_CATHODE, numDigits, digitPins, segmentPins);
  pinMode(PushButtonPin, INPUT);
}

void loop() {
  static byte count = 0;
  sevseg.setNumber(count);
  sevseg.refreshDisplay();
  buttonstate = digitalRead(PushButtonPin);


  if (buttonstate == HIGH) {
    sevseg.refreshDisplay();
    delay(300);
    count = (count + 1);
  }
  else {
    count;
  }
}
