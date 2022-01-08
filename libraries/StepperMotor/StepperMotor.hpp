#ifndef STEPPER_MOTOR_HPP_
#define STEPPER_MOTOR_HPP_

#include <OutputPin.hpp>

// Stepper motor (28BYJ-48) with driver
class StepperMotor
{
  public:
    StepperMotor(uint8_t in1, uint8_t in2, uint8_t in3, uint8_t in4);

    void MoveClockwise(uint16_t stepCount);
    void MoveCounterClockwise(uint16_t stepCount);

  private:
    void SetPins(int8_t state);
  
    OutputPin pins[4];

    static const int8_t stateMap[8][4];
    
};

#endif /* STEPPER_MOTOR_HPP_ */
