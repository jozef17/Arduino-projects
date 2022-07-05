#include "ShiftRegister.hpp"

int latchPin = 5;  // Latch pin of 74HC595 is connected to Digital pin 5
int clockPin = 6; // Clock pin of 74HC595 is connected to Digital pin 6
int dataPin = 4;  // Data pin of 74HC595 is connected to Digital pin 4

byte leds1 = 0;
byte leds2 = 0;
byte leds3 = 0;

ShiftRegister shiftRegister(dataPin, clockPin, latchPin);

#define DELAY 50
/*
 * setup() - this function runs once when you turn your Arduino on
 * We initialize the serial connection with the computer
 */
void setup() 
{
  // Set all the pins of 74HC595 as OUTPUT
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);  
  pinMode(clockPin, OUTPUT);
}

/*
 * loop() - this function runs over and over again
 */
void loop() 
{
  leds1 = 0; // Initially turns all the LEDs off, by giving the variable 'leds' the value 0
  leds2 = 0; // Initially turns all the LEDs off, by giving the variable 'leds' the value 0

  updateShiftRegister();
  delay(DELAY);
  for (int i = 0; i < 8; i++) // Turn all the LEDs ON one by one.
  {    
    for (int j = 0; j < 8; j++) // Turn all the LEDs ON one by one.
    {
       bitSet(leds2, j);    // Set the bit that controls that LED in the variable 'leds'
       updateShiftRegister();
       delay(DELAY);
    }

    bitSet(leds1, i);    // Set the bit that controls that LED in the variable 'leds'
    leds2 = 0; // Initially turns all the LEDs off, by giving the variable 'leds' the value 0
    updateShiftRegister();
    delay(DELAY);    
  }
}

/*
 * updateShiftRegister() - This function sets the latchPin to low, then calls the Arduino function 'shiftOut' to shift out contents of variable 'leds' in the shift register before putting the 'latchPin' high again.
 */
void updateShiftRegister()
{
   shiftRegister.ShiftOut((uint8_t)255);
   shiftRegister.ShiftOut(leds2);
   shiftRegister.ShiftOut(leds1);
   
   shiftRegister.PushOut();
}
