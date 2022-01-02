#include "InputPin.hpp"
#include "Core.hpp"

InputPin::InputPin(uint8_t pin) : Pin(pin)
{
  OpenPin(PinMode::input);
}

uint8_t InputPin::Read()
{
  return digitalRead(this->pinNumber);
}
