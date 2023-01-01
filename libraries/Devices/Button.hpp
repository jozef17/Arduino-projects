#ifndef BUTTON_HPP_
#define BUTTON_HPP_

#include <InputPin.hpp>

class Button final : public InputPin
{
  public:
    enum class BtnState : uint8_t { NoChange, Pressed, Released, LongPressed, LongReleased };

    Button(uint8_t pinNumber);

    BtnState GetChange();

  private:
    BtnState HandleChangedState(uint8_t newValue);

    bool longPressed = false;
    uint8_t lastValue = 0;
    unsigned long pressedAt = 0;

};

#endif /* BUTTON_HPP_ */
