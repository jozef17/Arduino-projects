#include "nRF24L01.hpp"
#include <SerialLogger.hpp>

#include <SPI.h>

#define Enable()      ce.Write(1)
#define Disable()     ce.Write(0)

#define CsnSelect()   csn.Write(0)
#define CsnUnselect() csn.Write(1)

// NRF24L01 registers
#define CONFIG        0x00
#define EN_AA         0x01
#define EN_RXADDR     0x02
#define SETUP_AW      0x03
#define SETUP_RETR    0x04
#define RF_CH         0x05
#define RF_SETUP      0x06
#define STATUS        0x07
#define RX_ADDR_P1    0x0B
#define TX_ADDR       0x10
#define RX_PW_P1      0x12
#define FIFO_STATUS   0x17
#define R_RX_PAYLOAD  0x61
#define W_TX_PAYLOAD  0xA0
#define FLUSH_RX      0xE2

// RF config
static const char addr[6] = "00001";
static const uint8_t channel = 76;

NRF24L01::NRF24L01(OutputPin csn, OutputPin ce) : csn(csn), ce(ce)
{
  // Init SPI
  // TODO: Change to use begin and end transaction
  //       when used with multiple SPI devices
  SPI.begin();
  SPI.setBitOrder(MSBFIRST);
  SPI.setDataMode(SPI_MODE0);

  // Init NRF24L01
  Disable();

  WriteRegister(CONFIG, 0);
  WriteRegister(EN_AA, 0);          // No Auto ACK
  WriteRegister(EN_RXADDR, 0);
  WriteRegister(SETUP_AW, 0x03);    // 5 Bytes for the TX/RX address
  WriteRegister(SETUP_RETR, 0);     // No retransmission
  WriteRegister(RF_CH, channel);    // Set Channel
  WriteRegister(RF_SETUP, 0x0E);

  Enable();
}

void NRF24L01::SetAsTransmitter()
{
  this->mode = Mode::TRANSMIT;
  Disable();

  // address
  WriteRegister(TX_ADDR, (uint8_t *)&addr, 5);

  // Power up device
  uint8_t conf;
  ReadRegister(CONFIG, &conf, 1);
  WriteRegister(CONFIG, conf | (1 << 1));

  Enable();
}

void NRF24L01::SetAsReciever()
{
  this->mode = Mode::RECIEVE;

  Disable();

  // Select data pipe no1
  WriteRegister(EN_RXADDR, 0x02);

  // address
  WriteRegister(RX_ADDR_P1, (uint8_t *)&addr, 5); 
  WriteRegister(RX_PW_P1, 32);      // 32 bit paiload for pipe 1

  // Power up device in recieve mode
  uint8_t conf;
  ReadRegister(CONFIG, &conf, 1);
  WriteRegister(CONFIG, conf | (1 << 1) | (1 << 0)); // power on & enable recieve

  Enable();
}

void NRF24L01::Send(uint8_t * data, uint8_t size)
{
  if(this->mode != Mode::TRANSMIT)
  {
    return;
  }
  
  // Prepare data
  uint8_t sendBuffer[32];
  for(int i = 0; i < 32; i++)
  {
    if(i < size)
    {
      sendBuffer[i] = data[i];
    }
    else
    {
      sendBuffer[i] = 0;
    }
  }

  // Send data
  CsnSelect();
  SPI.transfer(W_TX_PAYLOAD);
  for(int8_t siz = 31; siz >= 0; siz--)
  {
    SPI.transfer(sendBuffer[siz]);
  }
  CsnUnselect();

  delay(10);

  // Get Status
  uint8_t status;
  ReadRegister(FIFO_STATUS, &status, 1);
  if( (status & (1 < 4 )) && (!(status & ( 1 << 3 ))) )
  {
    SerialLogger::GetInstance().Log("Data Sent\n");
  }
  else
  {
    SerialLogger::GetInstance().Log("Sent ERROR !!!\n");
  }
}

void NRF24L01::Recieve(uint8_t * buffer, uint8_t size)
{
  if(this->mode != Mode::RECIEVE)
  {
    return;
  }

  // Recieve buffer
  uint8_t recieveBuffer[32];

  // Recieve data
  CsnSelect();
  SPI.transfer(R_RX_PAYLOAD);
  for(int8_t siz = 31; siz >= 0; siz--)
  {
    recieveBuffer[siz] = SPI.transfer(0xff);
  }
  CsnUnselect();

  // Copy recieved data to output buffer
  for(uint8_t i = 0; i < size; i++)
  {
    buffer[i] = recieveBuffer[i];
  }

  delay(10);

  WriteRegister(FLUSH_RX, nullptr, 0);
}

uint8_t NRF24L01::IsDataAvailable()
{
  if(this->mode != Mode::RECIEVE)
  {
    return 0;
  }

  uint8_t status;
  ReadRegister(STATUS, &status, 1);

  // Check RX_DR bit
  if(status & (1 << 6))
  {
    // Check pipe
    if(status & (1 << 1))
    {
      WriteRegister(STATUS, 1 << 6);
      return 1;
    }
  }
  return 0;
}

void NRF24L01::ReadRegister(uint8_t reg, uint8_t *buffer, uint8_t size)
{
  CsnSelect();
  
  SPI.transfer(reg); // Set register
  while(size--)
  {
    buffer[size] = SPI.transfer(0xff);
  }

  CsnUnselect();
}

void NRF24L01::WriteRegister(uint8_t reg, uint8_t *data, uint8_t size)
{
  reg = reg | 1 << 5; // 5th bit has to be 1

  CsnSelect();
  SPI.transfer(reg); // Set register
  while(size--)
  {
    SPI.transfer(data[size]);
  }

  CsnUnselect();
}

void NRF24L01::WriteRegister(uint8_t reg, uint8_t data)
{
  WriteRegister(reg, &data, 1);
}
