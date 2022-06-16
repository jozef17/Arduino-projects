#ifndef CALLIBRATING_STATE_HPP_
#define CALLIBRATING_STATE_HPP_

#include "State.hpp"

class Model;

// Callibrating state
class Callibrating final: public State
{
  public:
    Callibrating(Model &model) : model(model) {};
    virtual ~Callibrating() = default;
    
    virtual State *HandleButtonPress(Button::BtnState btnstate) override;
    virtual State *HandleSensorValue(uint16_t val) override;

    virtual void UpdateView(View &view) override;

  private:
    Model &model;

};

#endif /* CALLIBRATING_STATE_HPP_ */
