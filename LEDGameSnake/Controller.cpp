#include "Controller.hpp"

Controller::Controller(Game &game) : game(game)
{
  game.Reset();
}

Controller::~Controller()
{}

void Controller::Run()
{
  if(!this->game.IsRunning())
  {
    RunMessage();
  }
  else
  {
    RunGame();    
  }
  
  delay(100);
}

void Controller::RunGame()
{
  // Check Button 
  this->game.HandlePress(view.CheckKey());

  // Handle time
  this->game.Tick();

  // Render
  this->game.Render(view.GetBuffer());
  this->view.Render();
}

void Controller::RunMessage()
{
  volatile uint8_t randVal = random(100);
  static uint8_t counter   = 0;

  // Check key
  if(view.CheckKey() != Key::None)
  {
    this->message.SetMsg2();
    this->game.Reset();
    this->game.Start();
    counter == 0;
    return;
  }

  // Display Message
  if(counter == 0)
  {  
    this->message.Render(view.GetBuffer());
    this->view.Render();
  }
  
  counter = (counter + 1) % 4;
}
