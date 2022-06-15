#ifndef WATER_PUMP_HPP_
#define WATER_PUMP_HPP_

#include <OutputPin.hpp>

class WaterPump final 
{
  public:
    WaterPump(uint8_t pinNumber) : pin(OutputPin(pinNumber)) {};

    inline void On() { pin.Write(1); };
    inline void Off() { pin.Write(0); };

  private:
    OutputPin pin;

};

#endif /* WATER_PUMP_HPP_ */
