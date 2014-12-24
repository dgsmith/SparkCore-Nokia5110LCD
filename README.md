SparkCore-Nokia5110LCD
==================

A library for manipulating Nokia's 5110 LCD for the Spark Core.
Implementation based on Sparkfun's Nokia 5110 LCD Library.


Components Required
---
- A Nokia 5110 LCD (get at [sparkfun.com](https://www.sparkfun.com/products/10168) or eBay or Amazon)


Example Usage
---

See this [flashable, extensive example](firmware/examples/example.cpp) for details, or, in a nutshell:

```cpp
Nokia5110LCD::Display nokiaLCD(D0, D1, D2, A0); // SCE pin, RESET pin, Data/Command, and backlight pins
void setup() {
  nokiaLCD.begin();
  nokiaLCD.updateDisplay(); // with displayMap untouched, SFE logo
}
void loop() {
  // send various chars, strings, shapes to the buffer and write them to the display...
}
```

Nuances
---

- The first three parameters in the constructor can be any output pin

- The Backlight pin should be able to implement PWM (aka analog pin)

- the Serial data dnd Serial clock pins should stay at the default A3 and A5, respetively.


Building locally
---

If you are building locally, place the files here:

```
..\core-firmware\inc\neopixel.h
..\core-firmware\src\application.cpp (renamed from extra-examples.cpp)
..\core-firmware\src\neopixel.cpp
..\core-firmware\src\build.mk (optional, if you have your own make file going, just add the neopixel.cpp to it)
```
