#include "Wattering.hpp"
#include "Analysing.hpp"
#include "Callibrating.hpp"

#include "Model.hpp"
#include "View.hpp"

Wattering::Wattering(Model& model) : model(model)
{
  // Set Trashold
  auto range = this->model.GetDry() - this->model.GetWet();
  this->threshold = (uint16_t)(0.25f * (float)range) + this->model.GetWet();
}

State *Wattering::HandleButtonPress(Button::BtnState btnstate)
{
  if(btnstate == Button::BtnState::Released)
  {
    return new Callibrating(this->model);
  }
  return this;
}

State *Wattering::HandleSensorValue(uint16_t val) 
{
  if(val < this->threshold)
  {
      return new Analysing(this->model);
  }
  return this;
}

void Wattering::UpdateView(View &view)
{
  view.TurnPumpOn();
  view.TurnGreenLEDOn();
  view.TurnYellowLEDOff();
}
