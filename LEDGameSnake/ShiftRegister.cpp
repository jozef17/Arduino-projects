#include "ShiftRegister.hpp"
#include <Core.hpp>

#define DELAY 50

ShiftRegister::ShiftRegister(uint8_t dataPin, uint8_t clockPin, uint8_t latchPin) : dataPin(dataPin), clockPin(clockPin), latchPin(latchPin) 
{
   this->clockPin.Write(0);
   this->latchPin.Write(0);
}

ShiftRegister::ShiftRegister(OutputPin dataPin, OutputPin clockPin, OutputPin latchPin) : dataPin(dataPin), clockPin(clockPin), latchPin(latchPin) 
{
   this->clockPin.Write(0);
   this->latchPin.Write(0);
}

void ShiftRegister::ShiftOut(uint8_t data)
{
   for(auto i = 0; i < 8; i++)
   {
      // Set Bit
      auto currentBit = data & 1 << i;
      this->dataPin.Write(currentBit);

      // Clock out
      this->clockPin.Write(1);
      delayMicroseconds(DELAY);
      this->clockPin.Write(0);
      delayMicroseconds(DELAY);
   }  
}

void ShiftRegister::ShiftOut(void *data, uint8_t size)
{
   uint8_t *outArray = (uint8_t *)data;
   for(auto i = size-1; i >=0; i--)
   {
      ShiftOut(outArray[i]);
   }
}

void ShiftRegister::PushOut()
{
   this->latchPin.Write(1);
   delayMicroseconds(DELAY);
   this->latchPin.Write(0);
}
