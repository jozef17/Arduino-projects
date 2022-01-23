#ifndef STATE_HPP_
#define STATE_HPP_

#include <stdint.h>

// State interface
class State
{
  public:
    virtual ~State() = default;
  
    virtual State *HandleButtonPress() = 0;
    virtual State *HandleSensorValue(uint16_t val) = 0;

  protected:
    State() = default;

};

#endif /* STATE_HPP_ */
