#include "Callibrating.hpp"
#include "Analysing.hpp"

#include "Model.hpp"
#include "View.hpp"

State *Callibrating::HandleButtonPress(Button::BtnState btnstate)
{
  if(btnstate == Button::BtnState::Released)
  {
    return new Analysing(this->model);
  }
  return this;
}

State *Callibrating::HandleSensorValue(uint16_t val)
{
  // Wet - min value
  if (val < this->model.GetWet())
  {
    this->model.UpdateWet(val);
  }

  // Dry - max value
  if (val > this->model.GetDry())
  {
    this->model.UpdateDry(val);
  }

  return this;
}

void Callibrating::UpdateView(View &view)
{
  view.TurnPumpOff();
  view.TurnGreenLEDOff();
  view.TurnYellowLEDOn();
}
