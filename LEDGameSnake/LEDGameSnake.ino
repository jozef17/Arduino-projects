#include <InputPin.hpp>
#include "PinConst.hpp"
#include "Window.hpp"
#include "Snake.hpp"

InputPin upBtn(UP_BUTTON);
InputPin downBtn(DOWN_BUTTON);
InputPin leftBtn(LEFT_BUTTON);
InputPin rightBtn(RIGHT_BUTTON);

Window window(DATA, CLOCK, LATCH);
Snake game;

void setup() 
{ }

void loop() 
{  
  // Check Button 
  if(upBtn.Read())
  {
    game.HandlePress(Key::Up);
  }
  if(downBtn.Read())
  {
    game.HandlePress(Key::Down);
  }
  if(leftBtn.Read())
  {
    game.HandlePress(Key::Left);
  }
  if(rightBtn.Read())
  {
    game.HandlePress(Key::Right);
  }

  // Handle time
  game.Tick(0); // TODO diff

  // Reset game
  if(!game.IsRunning())
  {
    game.Reset();
  }

  // Render
  game.Render(window.GetBuffer());
  window.Render();

  delay(100);
}
