#include "Controller.hpp"
#include "Callibrating.hpp"

Controller::Controller()
{
  UpdateState(new Callibrating(this->model));
}

Controller::~Controller()
{
  delete this->state;
}
   
void Controller::Run()
{
  // Check Button & Update state on button release
  auto btn = view.CheckButton();
  auto newState = this->state->HandleButtonPress(btn);
  UpdateState(newState);

  // Check soil Moisture sensor & Update state
  auto soilMoisture = view.GetMoisture();
  UpdateState(this->state->HandleSensorValue(soilMoisture));

  this->state->UpdateView(this->view);
}

void Controller::UpdateState(State *newState)
{
  if(this->state != newState)
  {
    delete this->state;
    this->state = newState;
  }
}
