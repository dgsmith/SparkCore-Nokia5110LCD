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

- The Serial data and Serial clock pins should stay at the default A3 and A5, respectively.


Building locally
---

If you are building locally, place the files here:

```
..\core-firmware\inc\nokia-5110-lcd.h
..\core-firmware\src\application.cpp (renamed from example.cpp)
..\core-firmware\src\nokia-5110-lcd.cpp
```
