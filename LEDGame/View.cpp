#include "View.hpp"

Key View::CheckKey()
{
  if(upBtn.GetChange() == Button::BtnState::Pressed)
  {
    return Key::Up;
  }
  if(downBtn.GetChange() == Button::BtnState::Pressed)
  {
    return Key::Down;
  }
  if(leftBtn.GetChange() == Button::BtnState::Pressed)
  {
    return Key::Left;
  }
  if(rightBtn.GetChange() == Button::BtnState::Pressed)
  {
    return Key::Right;
  }
  return Key::None;
}
    
