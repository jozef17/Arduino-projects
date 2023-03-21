#include "SN74HC165.hpp"
#include "PinConsts.hpp"
#include <SerialLogger.hpp>

SN74HC165 shiftRegister(CLOCK, CLOCK_EN, LOAD, DATA);

void setup()
{}
 
void loop()
{
  uint8_t buffer[2] = { 0, 0 };
  shiftRegister.Load(buffer, 2);
  
  for(uint8_t i = 0; i < 2; i++)  
  {
    for(uint8_t j = 0; j < 8; j++)  
    {
      SerialLogger::GetInstance().Log(buffer[i] & 1 << j ? "1" : "0");
    }
    SerialLogger::GetInstance().Log(" ");
  }
  SerialLogger::GetInstance().Log("\n");

  delay(200);
}