#include "Callibrating.hpp"
#include "Analysing.hpp"
#include "PinConst.hpp"

OutputPin Callibrating::led(YELLOW_LED_PIN);

Callibrating::Callibrating()
{
  // Turn on LED
  led.Write(1);
}

Callibrating::~Callibrating()
{
  // Turn off LED
  led.Write(0);
}


State *Callibrating::HandleButtonPress()
{
  return new Analysing(this->dry, this->wet);
}

State *Callibrating::HandleSensorValue(uint16_t val)
{
  // Wet - min value
  if (val < this->wet)
  {
    this->wet = val;
  }

  // Dry - max value
  if (val > this->dry)
  {
    this->dry = val;
  }

  return this;
}
