#ifndef WATER_PUMP_HPP_
#define WATER_PUMP_HPP_

#include <OutputPin.hpp>

class WaterPump final // TODO Superclass
{
  public:
    WaterPump(uint8_t pinNumber) : pumpPin(pinNumber) {};

    void On() { pumpPin.Write(1); };
    void Off() { pumpPin.Write(0); };

  private:
    OutputPin pumpPin;

};

#endif /* WATER_PUMP_HPP_ */
