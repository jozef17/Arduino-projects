#ifndef WATTERING_STATE_HPP_
#define WATTERING_STATE_HPP_

#include "State.hpp"

class Model;

// Wattering state
class Wattering final: public State
{
  public:
    Wattering(Model& model);
    virtual ~Wattering() = default;

    virtual State *HandleButtonPress(Button::BtnState btnstate) override;
    virtual State *HandleSensorValue(uint16_t val) override;

    virtual void UpdateView(View &view) override;

  private:
    Model &model;

    uint16_t threshold;

};

#endif /* WATTERING_STATE_HPP_ */
