#include <Core.hpp>
#include <SerialLogger.hpp>

#include "MPU6050.hpp"
#include "SN74HC165.hpp"
#include "PinConsts.hpp"
#include "NRF24L01.hpp"

SN74HC165 shiftRegister(CLOCK, CLOCK_EN, LOAD, DATA); // PISO register for buttons
NRF24L01 rf(NRF_CSN, NRF_CE);                         // RF sender
MPU6050 *mpu = nullptr;

void setup()
{
  mpu = new MPU6050();
  rf.SetAsTransmitter();
}
 
void loop()
{
  uint8_t buffer[2];
  shiftRegister.Load(buffer, 2);
  rf.Send(buffer, sizeof(buffer));

  for(uint8_t i = 0; i < 2; i++)  
  {
    for(uint8_t j = 0; j < 8; j++)  
    {
      SerialLogger::GetInstance().Log(buffer[i] & 1 << j ? "1" : "0");
    }
    SerialLogger::GetInstance().Log("  ");
  }
  SerialLogger::GetInstance().Log("\n");

  auto acc = mpu->ReadAcc();
  auto gyro = mpu->ReadGyro();

  SerialLogger::GetInstance().Log("Acc: ");
  SerialLogger::GetInstance().Log((int)acc.x);
  SerialLogger::GetInstance().Log(", ");
  SerialLogger::GetInstance().Log((int)acc.y);
  SerialLogger::GetInstance().Log(", ");
  SerialLogger::GetInstance().Log((int)acc.z);

  SerialLogger::GetInstance().Log("\tGyro: ");
  SerialLogger::GetInstance().Log((int)gyro.x);
  SerialLogger::GetInstance().Log(", ");
  SerialLogger::GetInstance().Log((int)gyro.y);
  SerialLogger::GetInstance().Log(", ");
  SerialLogger::GetInstance().Log((int)gyro.z);
  SerialLogger::GetInstance().Log("\n");

  delay(200);
}
