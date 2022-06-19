#include "InputPin.hpp"
#include <Core.hpp>

InputPin::InputPin(uint8_t pin) : Pin(pin)
{
  // Set mode register to output
  volatile uint8_t * modeReg = portModeRegister(this->pinPort);
  *modeReg &= ~this->pinBitMask;

  // Get input register
  this->inputRegister = portInputRegister(this->pinPort);
}

uint16_t InputPin::Read() const
{
  // Read the value based on digital vs analog pin use
  if (this->pinNumber < A0)
  {
    return *this->inputRegister & this->pinBitMask ? 1 : 0;
  }
  else
  {
    return analogRead(this->pinNumber);
  }
}
