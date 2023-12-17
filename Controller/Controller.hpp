#ifndef CONTROLLER_HPP_
#define CONTROLLER_HPP_

#include "Transmitter.hpp"
#include "Inputs.hpp"

class Controller
{
  public:
    Controller();

    void Initialize();
    void Run();

  private:
    void GetState(ControllerData &data);

    Transmitter *transmitter = nullptr;
    Inputs inputs;
};

#endif /* CONTROLLER_HPP_ */ 