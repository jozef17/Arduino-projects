#ifndef CONTROLLER_HPP_
#define CONTROLLER_HPP_

#include "View.hpp"
#include "Game.hpp"

class Controller final
{
  public:
    Controller(Game &game);
    ~Controller();
    Controller(const Controller &) = delete;  
    Controller &operator=(const Controller &) = delete;  

    void Run();
  
  private:
    View view;
    Game &game;
    
};

#endif /* CONTROLLER_HPP_ */
