#define BREAKOUT
//#define TETRIS

#include "Controller.hpp"

#if defined(BREAKOUT)
#include "Breakout.hpp"
Breakout game;
#elif defined(TETRIS)
//#include "Tetris.hpp"
//Tetris game;
#else
#include "Snake.hpp"
Snake game;
#endif

Controller *controller = nullptr;

void setup() 
{
  controller = new Controller((Game &)game);
}

void loop() 
{    
  controller->Run();
}
