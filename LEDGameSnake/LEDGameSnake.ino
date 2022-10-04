#include <InputPin.hpp>
#include <SerialLogger.hpp>
#include "PinConst.hpp"
#include "Window.hpp"
#include "ShiftRegister.hpp"

InputPin upBtn(UP_BUTTON);
InputPin downBtn(DOWN_BUTTON);
InputPin leftBtn(LEFT_BUTTON);
InputPin rightBtn(RIGHT_BUTTON);

Window window(DATA, CLOCK, LATCH);

void setup() 
{
  window.Render();
  delay(5000); 
}

void loop() 
{
  uint8_t img1[6] = { 0b01010101,
                      0b10101010,
                      0b01010101,
                      0b10101010,
                      0b01010101,
                      0b10101010 }; 
  window.SetBuffer(img1);
  window.Render();
  delay(1000); 

  uint8_t img2[6] = { 0b10101010,
                      0b01010101,
                      0b10101010,
                      0b01010101,
                      0b10101010,
                      0b01010101 }; 
  window.SetBuffer(img2);
  window.Render();

  delay(1000); 

  if(upBtn.Read())
    SerialLogger::GetInstance().Log("UP Button Pressed\n");
  if(downBtn.Read())
    SerialLogger::GetInstance().Log("DOWN Button Pressed\n");
  if(leftBtn.Read())
    SerialLogger::GetInstance().Log("LEFT Button Pressed\n");
  if(rightBtn.Read())
    SerialLogger::GetInstance().Log("RIGHT Button Pressed\n");
}
