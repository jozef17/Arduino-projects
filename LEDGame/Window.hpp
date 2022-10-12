#ifndef WINDOW_HPP_
#define WINDOW_HPP_

#include "ShiftRegister.hpp"

class Window final
{
  public:
    Window(uint8_t dataPin, uint8_t clockPin, uint8_t latchPin);

    inline uint8_t* GetBuffer() { return this->frameBuffer; };

    void Render();

  private:
    ShiftRegister window;
    uint8_t frameBuffer[6] = { 0 };
  
};

#endif /* WINDOW_HPP_ */
