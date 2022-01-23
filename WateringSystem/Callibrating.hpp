#ifndef CALLIBRATING_STATE_HPP_
#define CALLIBRATING_STATE_HPP_

#include "State.hpp"
#include "OutputPin.hpp"

// Callibrating state
class Callibrating final: public State
{
  public:
    Callibrating();
    virtual ~Callibrating();
    
    virtual State *HandleButtonPress() override;
    virtual State *HandleSensorValue(uint16_t val) override;

  private:
    uint16_t wet = (uint16_t) - 1; 
    uint16_t dry = 0;

    static OutputPin led;

};

#endif /* CALLIBRATING_STATE_HPP_ */
