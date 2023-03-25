#ifndef NRF24L01_HPP_
#define NRF24L01_HPP_

#include <OutputPin.hpp>

class NRF24L01
{
  public: 
    NRF24L01(OutputPin csn, OutputPin ce);

    void SetAsTransmitter();
    void SetAsReciever();

    void Send(uint8_t * data, uint8_t size);
    void Recieve(uint8_t * buffer, uint8_t size);

    uint8_t IsDataAvailable();

  private:
    void ReadRegister(uint8_t reg, uint8_t *buffer, uint8_t size);
    void WriteRegister(uint8_t reg, uint8_t *data, uint8_t size);
    void WriteRegister(uint8_t reg, uint8_t data);
    
    enum class Mode : uint8_t { NONE, RECIEVE, TRANSMIT };
    Mode mode = Mode::NONE;
    
    OutputPin csn; // chip select not
    OutputPin ce;  // chip enable
};

#endif /* NRF24L01_HPP_ */