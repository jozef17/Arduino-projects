#ifndef IO_PIN_HPP_
#define IO_PIN_HPP_

#include "InputPin.hpp"
#include "OutputPin.hpp"

class IOPin : public InputPin, public OutputPin
{
  public:
    IOPin(uint8_t pin);

    uint16_t Read() const;
    void Write(uint8_t value);

  private:
    volatile uint8_t *modeRegister;
    
};

#endif /* IO_PIN_HPP_ */
