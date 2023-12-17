#ifndef CONTROLLER_DATA_HPP_
#define CONTROLLER_DATA_HPP_

#include <Core.hpp>

typedef struct
{
  uint8_t btn_states[2];                              //  Button states

  // Joysticks
  union{ uint8_t lx; uint8_t LX; uint8_t leftX; };    // Left Joystick X
  union{ uint8_t ly; uint8_t LY; uint8_t leftY; };    // Left Joystick Y
  union{ uint8_t rx; uint8_t RX; uint8_t rightX; };   // Right Joystick X
  union{ uint8_t ry; uint8_t RY; uint8_t rightY; };   // Right Joystick Y

  // Reserved for future features (e.g. gyro & acc)
  uint8_t unused[8];

  // Error detection - crc
  uint8_t crc;
} ControllerData;

#endif /* CONTROLLER_DATA_HPP_ */