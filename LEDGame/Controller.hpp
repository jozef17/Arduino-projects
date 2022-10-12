#ifndef CONTROLLER_HPP_
#define CONTROLLER_HPP_

#include "View.hpp"
#include "Game.hpp"
#include "Message.hpp"

class Controller final
{
  public:
    Controller(Game &game);
    ~Controller();
    Controller(const Controller &) = delete;  
    Controller &operator=(const Controller &) = delete;  

    void Run();
  
  private:
    void RunGame();
    void RunMessage();
  
    View view;
    Game &game;
    Message message;
};

#endif /* CONTROLLER_HPP_ */
