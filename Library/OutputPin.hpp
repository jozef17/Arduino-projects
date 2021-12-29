#ifndef OUTPUT_PIN_HPP_
#define OUTPUT_PIN_HPP_

#include "Pin.hpp"

class OutputPin final : public Pin
{
  public:
    OutputPin(uint8_t pin);

    void Write(uint8_t value);

};

#endif /* OUTPUT_PIN_HPP_ */
