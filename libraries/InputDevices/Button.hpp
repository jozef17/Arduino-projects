#ifndef BUTTON_HPP_
#define BUTTON_HPP_

#include <InputPin.hpp>

class Button final : public InputPin
{
  public:
    enum class BtnState : uint8_t { NoChange, Pressed, Released };

    Button(uint8_t pinNumber);

    BtnState GetChange();

  private:
    uint8_t lastValue = 0;
};

#endif /* BUTTON_HPP_ */
