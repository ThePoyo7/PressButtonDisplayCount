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
}

void loop() {
  buttonstate = digitalRead(PushButtonPin);
  Serial.println(buttonstate);
  static int count;
  sevseg.refreshDisplay();
  sevseg.setNumber(count);
  if (buttonstate == HIGH) {
    delay(300);
    count = (count + 1);
  } else {

  }
}
