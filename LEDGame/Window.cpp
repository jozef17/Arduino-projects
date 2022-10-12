#include "Window.hpp"

Window::Window(uint8_t dataPin, uint8_t clockPin, uint8_t latchPin) : window(ShiftRegister(dataPin, clockPin, latchPin))
{
  Render();
}

void Window::Render()
{
  this->window.ShiftOut(this->frameBuffer, 6); 
  this->window.PushOut();
}
