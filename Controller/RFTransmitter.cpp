#include "RFTransmitter.hpp"
#include "PinConsts.hpp"
#include "NRF24L01.hpp"

RFTransmitter::RFTransmitter()
{
  this->transmitter = new NRF24L01(NRF_CSN, NRF_CE);
  this->transmitter->SetAsTransmitter();
}

void RFTransmitter::Send(uint8_t *data, uint16_t size)
{
    this->transmitter->Send(data, size);
}