#ifndef WATER_PUMP_HPP_
#define WATER_PUMP_HPP_

#include <OutputPin.hpp>

class WaterPump final : OutputPin
{
  public:
    WaterPump(uint8_t pinNumber) : OutputPin(pinNumber) {};

    void On() { Write(1); };
    void Off() { Write(0); };

};

#endif /* WATER_PUMP_HPP_ */
