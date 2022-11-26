#include "StepperMotor.hpp"
#include <Core.hpp>

const int8_t StepperMotor::stateMap[8][4] = {
  {LOW,  LOW,  LOW,  HIGH},
  {LOW,  LOW,  HIGH, HIGH},
  {LOW,  LOW,  HIGH, LOW},
  {LOW,  HIGH, HIGH, LOW},
  {LOW,  HIGH, LOW,  LOW},
  {HIGH, HIGH, LOW,  LOW},
  {HIGH, LOW,  LOW,  LOW},
  {HIGH, LOW,  LOW,  HIGH},
};

StepperMotor::StepperMotor(uint8_t in1, uint8_t in2, uint8_t in3, uint8_t in4) :
   pins( { OutputPin(in1), OutputPin(in2), OutputPin(in3), OutputPin(in4) } )
{ }

void StepperMotor::MoveClockwise(uint16_t stepCount)
{
  int steps = 7;
  
  for (int x = 0; x < stepCount * 8; x++) 
  {
    SetPins(steps);
    
    steps--;
    if (steps < 0) 
    {
      steps = 7;
    }

    delayMicroseconds(1000);
  }
}

void StepperMotor::MoveCounterClockwise(uint16_t stepCount)
{
  int steps = 0;
  
  for (int x = 0; x < stepCount * 8; x++) 
  {
    SetPins(steps);
    
    steps++;
    if (steps > 7) 
    {
      steps = 0;
    }

    delayMicroseconds(1000);
  }
}

void StepperMotor::SetPins(int8_t state)
{
  auto row = state % 8; // Make sure input is in range 0-7

  for (uint8_t i = 0; i < 4; i++)
  {
    this->pins[i].Write(stateMap[row][i]);
  }
}
