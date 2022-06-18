#include "ExtraWattering.hpp"
#include "Analysing.hpp"

#include "Model.hpp"
#include "View.hpp"

State *ExtraWattering::HandleButtonPress(Button::BtnState btnstate)
{
  if(btnstate == Button::BtnState::LongPressed)
  {
    return new Analysing(this->model);
  }
  return this;
}

State *ExtraWattering::HandleSensorValue(uint16_t val) 
{
  return this;
}

void ExtraWattering::UpdateView(View &view)
{
  view.TurnPumpOn();
  view.TurnYellowLEDOff();

  this->LEDon = !this->LEDon;
  if(this->LEDon)
  {
    view.TurnGreenLEDOn();
  }
  else
  {
    view.TurnGreenLEDOff();
  }
}
