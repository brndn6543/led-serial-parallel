#include <Arduino.h>

int tDelay      = 1000;
int latchPin    = 11;
int clockPin    = 9;
int dataPin     = 12;

byte leds = 0;

void updateShiftRegister() {
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, leds);
    digitalWrite(latchPin, HIGH);
}

void setup() {
    pinMode(latchPin, OUTPUT);
    pinMode(clockPin, OUTPUT);
    pinMode(dataPin, OUTPUT);
}

void loop() {
    leds = 0;
    updateShiftRegister();
    delay(tDelay);

    // Sequentially light LEDs.
    for (int i = 0; i < 8; ++i) {
        bitSet(leds, i);
        updateShiftRegister();
        delay(tDelay);
    }
}