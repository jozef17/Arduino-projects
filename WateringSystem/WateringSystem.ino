#include "Controller.hpp"
#include "SerialLogger.hpp"

Controller controller;

void setup()
{
}

void loop() 
{  
  controller.Run();
  delay(50);
}
