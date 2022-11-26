#include "Button.hpp"
#include "Core.hpp"

#define SecondsToMilliseconds(s) s*1000

Button::Button(uint8_t pinNumber) : InputPin(pinNumber)
{
  this->lastValue = Read();
}

Button::BtnState Button::GetChange()
{
  auto value = Read();

  if (this->lastValue != value)
  {
      return HandleChangedState(value);
  }
  else if(value)
  {
      // Medium press
      auto now = millis();
      if (now - this->pressedAt > SecondsToMilliseconds(3) && !this->longPressed)
      {
          this->longPressed = true;
          return BtnState::LongPressed;
      }
  }
  return BtnState::NoChange;
}

Button::BtnState Button::HandleChangedState(uint8_t newValue)
{
    this->lastValue = newValue;

    if (newValue)
    {
        this->pressedAt = millis();
        return BtnState::Pressed;        
    }
    else
    {
        if (this->longPressed)
        {
            this->longPressed = false;
            return BtnState::LongReleased;
        }
        return  BtnState::Released;
    }
}
