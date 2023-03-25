#include "SN74HC165.hpp"
#include "PinConsts.hpp"
#include "NRF24L01.hpp"

SN74HC165 shiftRegister(CLOCK, CLOCK_EN, LOAD, DATA); // PISO register for buttons
NRF24L01 rf(NRF_CSN, NRF_CE);                         // RF sender

void setup()
{
  rf.SetAsTransmitter();
}
 
void loop()
{
  uint8_t buffer[2];
  shiftRegister.Load(buffer, 2);
  rf.Send(buffer, sizeof(buffer));
  delay(200);
}