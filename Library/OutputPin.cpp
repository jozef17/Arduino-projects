#include "OutputPin.hpp"

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

OutputPin::OutputPin(uint8_t pin) : Pin(pin)
{
  OpenPin(PinMode::output);
}

void OutputPin::Write(uint8_t value)
{
  digitalWrite(this->pinNumber, value);
}
