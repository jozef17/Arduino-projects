#include "Analysing.hpp"
#include "Wattering.hpp"
#include "Callibrating.hpp"

Analysing::Analysing(uint16_t dry, uint16_t wet) : dry(dry), wet(wet)
{
  // Get range
  auto range = this->dry - this->wet;
  this->threshold = (uint16_t)(0.65f * (float)range) + this->wet;
}

State *Analysing::HandleButtonPress() 
{
  return new Callibrating();
}

State *Analysing::HandleSensorValue(uint16_t val) 
{
  if(val > this->threshold)
  {
      return new Wattering(this->dry, this->wet);
  }
  return this;
}
