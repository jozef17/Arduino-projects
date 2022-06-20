#include "IOPin.hpp"
#include <Core.hpp>

IOPin::IOPin(uint8_t pin) : InputPin(pin), OutputPin(pin)
{
  this->modeRegister = portModeRegister(this->InputPin::pinPort);
}

uint16_t IOPin::Read() const
{
  *this->modeRegister &= ~this->InputPin::pinBitMask;
  return InputPin::Read();
}

void IOPin::Write(uint8_t value)
{
  *this->modeRegister |= this->InputPin::pinBitMask;
  OutputPin::Write(value);
}
