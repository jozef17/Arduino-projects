#include "Button.hpp"

Button::Button(uint8_t pinNumber) : InputPin(pinNumber)
{
  this->lastValue = Read();
}

Button::BtnState Button::GetChange()
{
  auto returnValue = BtnState::NoChange;
  auto value = Read();

  if (this->lastValue != value)
  {
    if (value)
    {
      returnValue = BtnState::Pressed;
    }
    else
    {
      returnValue = BtnState::Released;
    }
    this->lastValue = value;
  }

  return returnValue;
}
