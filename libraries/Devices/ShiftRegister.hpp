#ifndef SHIFT_REGISTER_HPP_
#define SHIFT_REGISTER_HPP_

#include <OutputPin.hpp>

class ShiftRegister final
{
  public:
    ShiftRegister(uint8_t dataPin, uint8_t clockPin, uint8_t latchPin);
    ShiftRegister(OutputPin dataPin, OutputPin clockPin, OutputPin latchPin);

    template <typename T>
    inline void ShiftOut(T data)
    {
      ShiftOut((void *)&data, sizeof(T));
    };

    void ShiftOut(uint8_t data);

    void ShiftOut(void *data, uint8_t size);

    void PushOut();

  private:
    OutputPin dataPin;
    OutputPin clockPin;
    OutputPin latchPin;

};

#endif /* SHIFT_REGISTER_HPP_ */
