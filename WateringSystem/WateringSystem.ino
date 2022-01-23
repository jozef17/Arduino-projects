#include <Button.hpp>

#include "Callibrating.hpp"
#include "PinConst.hpp"

Button button(BUTTON_PIN);
InputPin soilMoistureSensor(MOISTURE_SENSOR_PIN);

State *currentState = nullptr;

void SetState(State * newState);

void setup()
{
  currentState = new Callibrating();
}

void loop() 
{  
  // Check Button & Update state on button release
  auto btn = button.GetChange();
  if (btn == Button::BtnState::Released)
  {
    SetState(currentState->HandleButtonPress());
  }

  // Check soil Moisture sensor & Update state
  auto soilMoisture = soilMoistureSensor.Read();
  SetState(currentState->HandleSensorValue(soilMoisture));

  delay(50);
}

void SetState(State * newState)
{
  if(currentState != newState)
  {
    delete currentState;
    currentState = newState;
  }
}
