#ifndef PIN_HPP_
#define PIN_HPP_

#include "PinMode.hpp"

#include <stdint.h>

class Pin
{
  protected:
    Pin(uint8_t pinNumber);

    void OpenPin(PinMode mode);

    uint8_t pinNumber;

};

#endif /* PIN_HPP_ */
