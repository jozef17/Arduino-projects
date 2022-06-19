#ifndef PIN_HPP_
#define PIN_HPP_

#include <stdint.h>

class Pin
{
  protected:
    Pin(uint8_t pinNumber);

    uint8_t pinPort;
    uint8_t pinBitMask;
    uint8_t pinNumber;
};

#endif /* PIN_HPP_ */
