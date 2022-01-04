#include "OutputPin.hpp"
#include "InputPin.hpp"
#include "SerialLogger.hpp"

InputPin pinA0(A0);  // Potentiometer
InputPin pin5(5);    // Button
OutputPin pin11(11); // LED
OutputPin pin12(12); // LED
OutputPin pin13(13); // LED
OutputPin pin9(9,true); // LED

void setup() {
  // put your setup code here, to run once:
}

void loop() {
  auto& logger = SerialLogger::GetInstance();
  logger.Log("Hello from SerialLogger!");

  // Button (Digital) Input
  auto btnVal = pin5.Read();
  logger.Log(btnVal);

  // Potentiometer (Analog) Input
  auto pmVal = pinA0.Read();
  logger.Log(pmVal);
  pin9.Write((pmVal / 10.23) * 2.55);

  // Digital Output
  pin11.Write(HIGH);
  pin12.Write(LOW);
  pin13.Write(HIGH);
  delay(pmVal);

  // Update Potentiometer (Analog) Input
  pmVal = pinA0.Read();
  logger.Log(pmVal);
  pin9.Write((pmVal / 10.23) * 2.55);

  pin11.Write(LOW);
  pin12.Write(HIGH);
  pin13.Write(LOW);
  delay(pmVal);
}
