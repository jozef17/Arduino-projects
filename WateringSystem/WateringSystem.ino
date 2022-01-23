#include <Button.hpp>

#include "Analysing.hpp"
#include "PinConst.hpp"

#define DRY 520
#define WET 220

InputPin soilMoistureSensor(MOISTURE_SENSOR_PIN);
Button button(BUTTON_PIN);

State *currentState = nullptr;

void SetState(State * newState);

void setup()
{
  currentState = new Analysing(DRY, WET);
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
