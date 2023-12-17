#ifndef INPUTS_HPP_
#define INPUTS_HPP_

#include <Core.hpp>
#include <InputPin.hpp>

#include "PinConsts.hpp"
#include "SN74HC165.hpp"

class Inputs final
{
public:
  uint8_t GetButtonsStates();

  inline uint8_t GetLeftJoistickX()  { return LeftJoystickX.Read()  / 4; };
  inline uint8_t GetLeftJoistickY()  { return LeftJoysticky.Read()  / 4; };
  inline uint8_t GetRightJoistickX() { return 255 - RightJoystickX.Read() / 4; };
  inline uint8_t GetRightJoistickY() { return 255 - RightJoystickY.Read() / 4; };

private:
  SN74HC165 buttons = {CLOCK, CLOCK_EN, LOAD, DATA};

  InputPin LeftJoystickX  =  { L_JOYSTICK_X };
  InputPin LeftJoysticky  =  { L_JOYSTICK_Y };
  InputPin RightJoystickX =  { R_JOYSTICK_X };
  InputPin RightJoystickY =  { R_JOYSTICK_Y };

};

#endif /* INPUTS_HPP_ */