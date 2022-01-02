#include "Pin.hpp"
#include "Core.hpp"

Pin::Pin(uint8_t pinNumber) : pinNumber(pinNumber)
{}

void Pin::OpenPin(PinMode mode)
{
  pinMode(this->pinNumber, static_cast<uint8_t>(mode));
}
