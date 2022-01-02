#include "OutputPin.hpp"
#include "InputPin.hpp"
#include "SerialLogger.hpp"

InputPin pin5(5);
OutputPin pin11(11);
OutputPin pin12(12);
OutputPin pin13(13);

void setup() {
  // put your setup code here, to run once:
}

void loop() {
  auto& logger = SerialLogger::GetInstance();
  logger.Log("Hello from SerialLogger!");

  auto btnVal = pin5.Read();
  logger.Log(btnVal);

  pin11.Write(HIGH);
  pin12.Write(LOW);
  pin13.Write(HIGH);
  delay(500);

  btnVal = pin5.Read();
  logger.Log(btnVal);

  pin11.Write(LOW);
  pin12.Write(HIGH);
  pin13.Write(LOW);
  delay(500);
}
