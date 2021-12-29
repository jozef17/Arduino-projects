#include "Pin.hpp"

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

Pin::Pin(uint8_t pinNumber) : pinNumber(pinNumber)
{}

void Pin::OpenPin(PinMode mode)
{
  pinMode(this->pinNumber, static_cast<uint8_t>(mode));
}
