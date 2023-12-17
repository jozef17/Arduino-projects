#ifndef TRANSMITTER_HPP_
#define TRANSMITTER_HPP_

#include <Core.hpp>
#include "ControllerData.hpp"

class Transmitter
{
public:
  void Send(ControllerData * data);

protected:
  virtual void Send(uint8_t *data, uint16_t size) = 0;

};

#endif /* TRANSMITTER_HPP_ */
