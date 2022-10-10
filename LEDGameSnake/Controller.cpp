#include "Controller.hpp"
    
Controller::Controller(Game &game) : game(game)
{
  game.Reset();
}

Controller::~Controller()
{}

void Controller::Run()
{
  // Check Button 
  this->game.HandlePress(view.CheckKey());

  // Handle time
  this->game.Tick(0); // TODO diff

  // Reset game
  if(!this->game.IsRunning())
  {
    this->game.Reset();
  }

  // Render
  this->game.Render(view.GetBuffer());
  this->view.Render();

  delay(100); // TODO change
}
