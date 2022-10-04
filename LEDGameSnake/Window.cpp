#include "Window.hpp"

Window::Window(uint8_t dataPin, uint8_t clockPin, uint8_t latchPin) : window(ShiftRegister(dataPin, clockPin, latchPin))
{ }

void Window::SetBuffer(uint8_t *frameBuffer)
{
   this->frameBuffer = frameBuffer;
}

void Window::Render()
{
  if(this->frameBuffer != nullptr)
  {
    this->window.ShiftOut(this->frameBuffer, 6); 
  }
  else
  {
    // If framebuffer wasn't set, turn of all LEDs
    for(uint8_t i= 0;i<6;i++)
    {
      this->window.ShiftOut((uint8_t)0);
    }
  }
  this->window.PushOut();
}
