#ifndef ANALYSING_STATE_HPP_
#define ANALYSING_STATE_HPP_

#include "State.hpp"

class Model;

// Analysing state
class Analysing final: public State
{
  public:
    Analysing(Model &model);
    virtual ~Analysing() = default;

    virtual State *HandleButtonPress() override;
    virtual State *HandleSensorValue(uint16_t val) override;

    virtual void UpdateView(View &view) override;

  private:  
    Model &model;
    
    uint16_t threshold;
    
};

#endif /* ANALYSING_STATE_HPP_ */
