# LEDs Using a Serial to Parallel Converter
This project demonstrates how to sequentially light a number
of LEDs using a serial to parallel converter.

**Watch on YouTube**

[![Watch on YouTube](https://i.postimg.cc/bY7kJTWg/seq-leds.jpg)](https://youtu.be/az8nkSQ2W1M)

Using a Serial to Parallel converter allows you save connections on your board.
This project uses the 74HC595; this chip has eight outputs and three inputs
that can be used to feed data a bit at a time.

## 74HC595 Shift Register
The shift register is a type of chip that holds eight memory locations, each of
which can be `0` or `1`. To set, the data is fed using the `Data` and `Clock`
pins of the chip.

The chip has an output enabled pin used to enable or disable the outputs all at once.
This can be attached to a PWM pin and using `analogWrite()` would allow control
of the brightness of the LEDs.

## Wiring

![](https://i.postimg.cc/Yq8DHsq4/sequential-leds.png)

**Components:**

- Microcontroller: Elegoo UNO R3 (Arduino Compatible)
- Shift Register IC: 74HC595 
- LEDs: 8 (various colors)
- Resistors: 220Ω (one for each LED)
- Breadboard and jumper wires

### Connections ###

**Elegoo UNO R3 → 74HC595:**

Pin 11 (UNO) → Pin 14 (SER - Serial Data Input) of 74HC595

Pin 12 (UNO) → Pin 12 (RCLK - Register Clock) of 74HC595

Pin 8 (UNO) → Pin 11 (SRCLK - Shift Register Clock) of 74HC595

5V (UNO) → Pin 16 (VCC) of 74HC595

GND (UNO) → Pin 8 (GND) of 74HC595

Pin 10 (SRCLR - Shift Register Clear) of 74HC595 → 5V

Pin 13 (OE - Output Enable, active LOW) of 74HC595 → GND

**74HC595 → LEDs:**

Pin 15 (QA) → resistor → LED 1 anode (+)

Pin 1 (QB) → resistor → LED 2 anode (+)

Pin 2 (QC) → resistor → LED 3 anode (+)

Pin 3 (QD) → resistor → LED 4 anode (+)

Pin 4 (QE) → resistor → LED 5 anode (+)

Pin 5 (QF) → resistor → LED 6 anode (+)

Pin 6 (QG) → resistor → LED 7 anode (+)

Pin 7 (QH) → resistor → LED 8 anode (+)

**Common LED Connection:**

All LED cathodes (-) → common ground rail on breadboard → GND (UNO)

**Power Rails:**

- Connect UNO 5V pin to breadboard positive (+) rail.

- Connect UNO GND pin to breadboard negative (-) rail.

