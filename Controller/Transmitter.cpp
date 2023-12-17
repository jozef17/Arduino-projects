#include "Transmitter.hpp"

void Transmitter::Send(ControllerData * data)
{
  // TODO CRC

  Send((uint8_t)data, sizeof(ControllerData));
}