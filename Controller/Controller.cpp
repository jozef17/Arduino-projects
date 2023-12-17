#include "Controller.hpp"

#include <Core.hpp>
#include <SerialLogger.hpp>

#include "RFTransmitter.hpp"
#include "ControllerData.hpp"

Controller::Controller()
{}

void Controller::Initialize()
{
  this->transmitter = new RFTransmitter();
  // TODO any runtime initialization add here
}


void Controller::Run()
{
  ControllerData data = { 0 };

  // Get current controller state
  GetState(data);

  // Send data
  this->transmitter->Send(&data);

  // Debug logging - To be removed !!!
  for(int8_t j = 7; j >= 0; j--)  
  {
      SerialLogger::GetInstance().Log(data.btn_states[0] & 1 << j ? "1" : "0");
  }
  SerialLogger::GetInstance().Log(", lx ");
  SerialLogger::GetInstance().Log((int)(data.leftX));
  SerialLogger::GetInstance().Log(", ly ");
  SerialLogger::GetInstance().Log((int)(data.leftY));
  SerialLogger::GetInstance().Log(", rx ");
  SerialLogger::GetInstance().Log((int)(data.rightX));
  SerialLogger::GetInstance().Log(", ry ");
  SerialLogger::GetInstance().Log((int)(data.rightY));
  SerialLogger::GetInstance().Log("\n");

  delay(100);
}

void Controller::GetState(ControllerData &data)
{
  data.btn_states[0] = this->inputs.GetButtonsStates();
  data.btn_states[1] = 0;

  data.leftX  = this->inputs.GetLeftJoistickX();
  data.leftY  = this->inputs.GetLeftJoistickY();
  data.rightX = this->inputs.GetRightJoistickX();
  data.rightY = this->inputs.GetRightJoistickY();
}
