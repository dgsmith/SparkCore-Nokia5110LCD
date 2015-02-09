// Nokia 5100 LCD Example Code
// 	Graphics driver and PCD8544 interface code for SparkFun's
// 	84x48 Graphic LCD.
// 	https://www.sparkfun.com/products/10168
// 
// 	by: Jim Lindblom
// 		adapted from code by Nathan Seidle and mish-mashed with
// 		code from the ColorLCDShield.
// 	date: October 10, 2013
// 	license: Beerware. Feel free to use, reuse, and modify this
// 	code as you see fit. If you find it useful, and we meet someday,
// 	you can buy me a beer.
// 
// 	Adapted as a Spark Core library by Grayson Smith.
#ifndef _NOKIA_5110_LCD
#define _NOKIA_5110_LCD

#include "application.h"
#include "math.h"

// PCD8544-specific defines:
#define LCD_COMMAND  0 
#define LCD_DATA     1

// 84x48 LCD Defines:
#define LCD_WIDTH   84 // Note: x-coordinates go wide
#define LCD_HEIGHT  48 // Note: y-coordinates go high
#define WHITE       0  // For drawing pixels. A 0 draws white.
#define BLACK       1  // A 1 draws black.

namespace Nokia5110LCD
{
	class Display
	{
		public:
			// constructor
			Display(int _pinSCE, int _pinRESET, int _pinDC,
				int _pinBL, int _pinSDIN = A5, int _pinSCLK = A3);
			~Display();

			//This sends the magical commands to the PCD8544
			void begin();

			// There are two memory banks in the LCD, data/RAM and commands.
			// This function sets the DC pin high or low depending, and then 
			// sends the data byte
			void write(byte data_or_command, byte data);

			// This function sets a pixel on displayMap to your preferred
			// color. 1=Black, 0= white.
			void setPixel(int x, int y, boolean bw = BLACK);

			void clearPixel(int x, int y);

			// setLine draws a line from x0,y0 to x1,y1 with the set color.
			// This function was grabbed from the SparkFun ColorLCDShield 
			// library.
			void setLine(int x0, int y0, int x1, int y1, boolean bw = BLACK);

			// setRect will draw a rectangle from x0,y0 top-left corner to
			// a x1,y1 bottom-right corner. Can be filled with the fill
			// parameter, and colored with bw.
			// This function was grabbed from the SparkFun ColorLCDShield
			// library.
			void setRect(int x0, int y0, int x1, int y1, boolean fill, boolean bw);

			// setCircle draws a circle centered around x0,y0 with a defined
			// radius. The circle can be black or white. And have a line
			// thickness ranging from 1 to the radius of the circle.
			// This function was grabbed from the SparkFun ColorLCDShield 
			// library.
			void setCircle (int x0, int y0, int radius, boolean bw, int lineThickness);

			// This function will draw a char (defined in the ASCII table
			// near the beginning of this sketch) at a defined x and y).
			// The color can be either black (1) or white (0).
			void setChar(char character, int x, int y, boolean bw = BLACK);

			// setStr draws a string of characters, calling setChar with
			// progressive coordinates until it's done.
			// This function was grabbed from the SparkFun ColorLCDShield
			// library.
			void setStr(char * dString, int x, int y, boolean bw = BLACK);

			// This function will draw an array over the screen. (For now) the
			// array must be the same size as the screen, covering the entirety
			// of the display.
			void setBitmap(char * bitArray);

			// This function clears the entire display either white (0) or
			// black (1).
			// The screen won't actually clear until you call updateDisplay()!
			void clearDisplay(boolean bw = WHITE);
			
			// Helpful function to directly command the LCD to go to a 
			// specific x,y coordinate.
			void gotoXY(int x, int y);
			
			// This will actually draw on the display, whatever is currently
			// in the displayMap array.
			void updateDisplay();
			
			// Set contrast can set the LCD Vop to a value between 0 and 127.
			// 40-60 is usually a pretty good range.
			void setContrast(byte contrast);
			
			// There are two ways to do this. Either through direct commands
			// to the display, or by swapping each bit in the displayMap array.
			// We'll leave both methods here, comment one or the other out if 
			// you please.
			void invertDisplay();

		private:
			int pinSCE;   // SCE    - Chip select, pin 3 on LCD
			int pinRESET; // RST    - Reset, pin 4 on LCD
			int pinDC;    // DC     - Data/Command, pin 5 on LCD
			int pinSDIN;  // DN(MOSI) - Serial data, pin 6 on LCD
			int pinSCLK;  // SCLK   - Serial clock, pin 7 on LCD
			int pinBL;    // LED    - Backlight LED, pin 8 on LCD
			int lcdX;
			int lcdY;
			byte contrast;

			// The displayMap variable stores a buffer representation of the
			// pixels on our display. There are 504 total bits in this array,
			// same as how many pixels there are on a 84 x 48 display.
			// 
			// Each byte in this array covers a 8-pixel vertical block on the 
			// display. Each successive byte covers the next 8-pixel column over
			// until you reach the right-edge of the display and step down 8 rows.
			// 
			// To update the display, we first have to write to this array, then
			// call the updateDisplay() function, which sends this whole array
			// to the PCD8544.
			// 
			// Because the PCD8544 won't let us write individual pixels at a 
			// time, this is how we can make targeted changes to the display.
			static byte displayMap[LCD_WIDTH * LCD_HEIGHT / 8];

			// Font table:
			// This table contains the hex values that represent pixels for a
			// font that is 5 pixels wide and 8 pixels high. Each byte in a row
			// represents one, 8-pixel, vertical column of a character. 5 bytes
			// per character. 
			static byte ASCII[96][5];
	};
}

#endif
