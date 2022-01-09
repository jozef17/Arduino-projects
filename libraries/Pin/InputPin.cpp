#include "InputPin.hpp"
#include <Core.hpp>

InputPin::InputPin(uint8_t pin) : Pin(pin)
{
    OpenPin(PinMode::input);
}

uint16_t InputPin::Read()
{
  // Read the value based on digital vs analog pin use
  if (this->pinNumber < A0)
  {
    return digitalRead(this->pinNumber);
  }
  else
  {
    return analogRead(this->pinNumber);
  }
}
