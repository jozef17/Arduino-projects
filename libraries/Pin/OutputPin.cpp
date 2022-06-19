#include "OutputPin.hpp"
#include <Core.hpp>

OutputPin::OutputPin(uint8_t pin,  bool isAnalog) : Pin(pin), isAnalog(isAnalog)
{  
  // Set mode register to output
  volatile uint8_t *modeReg = portModeRegister(this->pinPort);
  *modeReg |= this->pinBitMask;
  
  // Get output register
  this->outputRegister = portOutputRegister(this->pinPort);
}

void OutputPin::Write(uint8_t value)
{
  
  if (this->isAnalog)
  {
    analogWrite(this->pinNumber, value);
  }
  else
  {
    if(value)
    {
      *this->outputRegister |= this->pinBitMask; // Set
    }
    else
    {
      *this->outputRegister &= ~this->pinBitMask; // Clear
    }
  }
}
