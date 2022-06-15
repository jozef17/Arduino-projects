#include "Analysing.hpp"
#include "Wattering.hpp"
#include "Callibrating.hpp"

#include "Model.hpp"
#include "View.hpp"

Analysing::Analysing(Model &model) : model(model)
{
  // Get range
  auto range = this->model.GetDry() - model.GetWet();
  this->threshold = (uint16_t)(0.65f * (float)range) + model.GetWet();
}

State *Analysing::HandleButtonPress() 
{
  return new Callibrating(this->model);
}

State *Analysing::HandleSensorValue(uint16_t val) 
{
  if(val > this->threshold)
  {
      return new Wattering(this->model);
  }
  return this;
}

void Analysing::UpdateView(View &view)
{
  view.TurnPumpOff();
  view.TurnGreenLEDOff();
  view.TurnYellowLEDOff();
}
