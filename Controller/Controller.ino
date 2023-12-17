#include "Controller.hpp"

Controller controller;

void setup()
{
  controller.Initialize();
}
 
void loop()
{
  controller.Run();
}
