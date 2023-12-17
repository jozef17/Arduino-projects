#include "Inputs.hpp"

uint8_t Inputs::GetButtonsStates()
{
  uint8_t buttons[2];
  this->buttons.Load(&buttons[0], 2);

  return buttons[1] << 4 | (buttons[0] & 0x0f);
}