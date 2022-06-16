#include "Analysing.hpp"
#include "Callibrating.hpp"
#include "ExtraWattering.hpp"
#include "Wattering.hpp"

#include "Model.hpp"
#include "View.hpp"

Analysing::Analysing(Model &model) : model(model)
{
  // Get range
  auto range = this->model.GetDry() - model.GetWet();
  this->threshold = (uint16_t)(0.5f * (float)range) + model.GetWet();
}

State *Analysing::HandleButtonPress(Button::BtnState btnstate) 
{
  if(btnstate == Button::BtnState::Released)
  {
    return new Callibrating(this->model);
  }else if(btnstate == Button::BtnState::LongPressed)
  {
    return new ExtraWattering(this->model);
  }
  return this;
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
