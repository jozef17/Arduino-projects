#ifndef STATE_HPP_
#define STATE_HPP_

#include <stdint.h>
#include <Button.hpp>

class View;

// State interface
class State
{
  public:  
    virtual ~State() = default;
  
    virtual State *HandleButtonPress(Button::BtnState btnstate) = 0;
    virtual State *HandleSensorValue(uint16_t val) = 0;

    virtual void UpdateView(View &view) = 0;

  protected:
    State() = default;

};

#endif /* STATE_HPP_ */
