#ifndef WATTERING_STATE_HPP_
#define WATTERING_STATE_HPP_

#include "State.hpp"
#include "WaterPump.hpp"

// Wattering state
class Wattering : public State
{
  public:
    Wattering(uint16_t dry, uint16_t wet);
    virtual ~Wattering();

    virtual State *HandleButtonPress() override;
    virtual State *HandleSensorValue(uint16_t val);

  private:
    static WaterPump pump;
    static OutputPin led;

    uint16_t dry;
    uint16_t wet;

    uint16_t threshold;

};

#endif /* WATTERING_STATE_HPP_ */
