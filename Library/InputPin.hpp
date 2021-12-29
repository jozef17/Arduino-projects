#ifndef INPUT_PIN_HPP_
#define INPUT_PIN_HPP_

#include "Pin.hpp"

class InputPin final : public Pin
{
  public:
    InputPin(uint8_t pin);

    uint8_t Read();

};

#endif /* INPUT_PIN_HPP_ */
