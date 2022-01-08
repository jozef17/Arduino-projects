#include <StepperMotor.hpp>

// Stepper motor (28BYJ-48)
// Motor IN1 connected to pin 11
// Motor IN2 connected to pin 10
// Motor IN3 connected to pin  9
// Motor IN4 connected to pin  8
StepperMotor motor(11,10,9,8);

void setup()
{
}

void loop()
{
  motor.MoveCounterClockwise(512);
  delay(2000);

  motor.MoveClockwise(512);
  delay(2000);
}
