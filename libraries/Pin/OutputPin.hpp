#ifndef OUTPUT_PIN_HPP_
#define OUTPUT_PIN_HPP_

#include "Pin.hpp"

class OutputPin : public Pin
{
  public:
    OutputPin(uint8_t pin, bool isAnalog = false);

    void Write(uint8_t value);

  private:
    bool isAnalog = false;
    
};

#endif /* OUTPUT_PIN_HPP_ */
