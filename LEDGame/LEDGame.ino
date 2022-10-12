#include "Controller.hpp"
#include "Snake.hpp"

Snake game;
Controller *controller = nullptr;

void setup() 
{
  controller = new Controller((Game &)game);
}

void loop() 
{    
  controller->Run();
}
