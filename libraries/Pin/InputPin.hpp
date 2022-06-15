#ifndef INPUT_PIN_HPP_
#define INPUT_PIN_HPP_

#include "Pin.hpp"

class InputPin : public Pin
{
  public:
    InputPin(uint8_t pin);

    uint16_t Read() const;

};

#endif /* INPUT_PIN_HPP_ */
