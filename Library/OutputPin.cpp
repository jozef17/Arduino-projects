#include "OutputPin.hpp"
#include "Core.hpp"

OutputPin::OutputPin(uint8_t pin,  bool isAnalog) : Pin(pin), isAnalog(isAnalog)
{
  OpenPin(PinMode::output);
}

void OutputPin::Write(uint8_t value)
{
  if (this->isAnalog)
  {
    analogWrite(this->pinNumber, value);
  }
  else
  {
    digitalWrite(this->pinNumber, value);
  }

}
