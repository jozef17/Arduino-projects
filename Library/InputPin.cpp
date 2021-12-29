#include "InputPin.hpp"

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

InputPin::InputPin(uint8_t pin) : Pin(pin)
{
  OpenPin(PinMode::input);
}

uint8_t InputPin::Read()
{
  return digitalRead(this->pinNumber);
}
