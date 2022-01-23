#include "Wattering.hpp"
#include "Analysing.hpp"
#include "Callibrating.hpp"

#include "PinConst.hpp"

WaterPump Wattering::pump(PUMP_PIN);
OutputPin Wattering::led(GREEN_LED_PIN);

Wattering::Wattering(uint16_t dry, uint16_t wet) : dry(dry), wet(wet)
{
  // Set Trashold
  auto range = this->dry - this->wet;
  this->threshold = (uint16_t)(0.25f * (float)range) + this->wet;

  // Turn on Pump
  pump.On();

  // Turn on LED
  led.Write(1);
}

Wattering::~Wattering()
{
  // Turn off Pump
  pump.Off();
  
  // Turn off LED
  led.Write(0);
}

State *Wattering::HandleButtonPress() 
{
  return new Callibrating();
}

State *Wattering::HandleSensorValue(uint16_t val) 
{
  if(val < this->threshold)
  {
      return new Analysing(this->dry, this->wet);
  }
  return this;
}
