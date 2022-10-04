#ifndef WINDOW_HPP_
#define WINDOW_HPP_

#include "ShiftRegister.hpp"

class Window final
{
public:
  Window(uint8_t dataPin, uint8_t clockPin, uint8_t latchPin);

  void SetBuffer(uint8_t *frameBuffer);

  void Render();

private:
  ShiftRegister window;
  uint8_t * frameBuffer = nullptr;
  
};

#endif
