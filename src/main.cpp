#include <Arduino.h>

// Digital outs connected to latch, clock, and
// data pins of the 74HC.
int tDelay      = 1000;
int latchPin    = 11;
int clockPin    = 9;
int dataPin     = 12;

// Hold the pattern of which LEDs are off/on.
byte leds = 0;

void updateShiftRegister() {
    digitalWrite(latchPin, LOW);

    /**
     * dataPin      > pin to use for data
     * clockPin     > pin to use for clock
     * LSBFIRST     > which end of data to start
     * leds         > data to be shifted into the shift register
     */
    shiftOut(dataPin, clockPin, LSBFIRST, leds);
    digitalWrite(latchPin, HIGH);
}

// Setup digital out pins.
void setup() {
    pinMode(latchPin, OUTPUT);
    pinMode(clockPin, OUTPUT);
    pinMode(dataPin, OUTPUT);
}

void loop() {
    leds = 0;               // Start with LEDs off.
    updateShiftRegister();  // Send LEDs pattern to the shift register.
    delay(tDelay);          // Pause.

    // Sequentially light LEDs.
    // Uses bitSet to set the bit that controls that LED
    // in the leds variable.
    for (int i = 0; i < 8; ++i) {
        bitSet(leds, i);
        updateShiftRegister();  // Update LEDs to reflect the variable.
        delay(tDelay);
    }
}