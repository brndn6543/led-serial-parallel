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