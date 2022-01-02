#include "OutputPin.hpp"
#include "Core.hpp"

OutputPin::OutputPin(uint8_t pin) : Pin(pin)
{
  OpenPin(PinMode::output);
}

void OutputPin::Write(uint8_t value)
{
  digitalWrite(this->pinNumber, value);
}
