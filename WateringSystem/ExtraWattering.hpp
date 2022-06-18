#ifndef EXTRA_WATTERING_STATE_HPP_
#define EXTRA_WATTERING_STATE_HPP_

#include "State.hpp"

class Model;

// Extra Wattering state
class ExtraWattering final: public State
{
  public:
    ExtraWattering(Model& model) : model(model) {};
    virtual ~ExtraWattering() = default;

    virtual State *HandleButtonPress(Button::BtnState btnstate) override;
    virtual State *HandleSensorValue(uint16_t val) override;

    virtual void UpdateView(View &view) override;

  private:
    Model &model;
    bool LEDon = false;

};

#endif /* EXTRA_WATTERING_STATE_HPP_ */
