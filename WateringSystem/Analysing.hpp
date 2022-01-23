#ifndef ANALYSING_STATE_HPP_
#define ANALYSING_STATE_HPP_

#include "State.hpp"

// Analysing state
class Analysing final: public State
{
  public:
    Analysing(uint16_t dry, uint16_t wet);
    virtual ~Analysing() = default;

    virtual State *HandleButtonPress() override;
    virtual State *HandleSensorValue(uint16_t val) override;

  private:  
    uint16_t dry;
    uint16_t wet;

    uint16_t threshold;
    
};

#endif /* ANALYSING_STATE_HPP_ */
