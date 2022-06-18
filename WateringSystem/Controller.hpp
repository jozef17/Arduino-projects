#ifndef CONTROLLER_HPP_
#define CONTROLLER_HPP_

#include "Core.hpp"

#include "Model.hpp"
#include "View.hpp"

class State;

class Controller final
{
  public:
    Controller();
    ~Controller();
    Controller(const Controller &) = delete;  
    Controller &operator=(const Controller &) = delete;  

    void Run();
    
  private:
    void UpdateState(State *newState);
  
    State *state = nullptr;
  
    Model model;
    View view;
  
};

#endif /* CONTROLLER_HPP_ */
