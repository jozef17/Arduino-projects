#include "Pin.hpp"
#include <Core.hpp>

Pin::Pin(uint8_t pinNumber) : pinNumber(pinNumber), pinPort(digitalPinToPort(pinNumber)), pinBitMask(digitalPinToBitMask(pinNumber))
{
}
