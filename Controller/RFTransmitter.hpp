#ifndef RF_TRANSMITTER_HPP_
#define RF_TRANSMITTER_HPP_

#include "Transmitter.hpp"

class NRF24L01;

class RFTransmitter final : public Transmitter
{
public:
  RFTransmitter();

  virtual void Send(uint8_t *data, uint16_t size) override;

private:
  NRF24L01 *transmitter = nullptr;

};

#endif /* RF_TRANSMITTER_HPP_ */