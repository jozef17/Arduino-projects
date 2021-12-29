#include "OutputPin.hpp"
#include "InputPin.hpp"

//InputPin pin5(5);
OutputPin pin11(11);
OutputPin pin12(12);
OutputPin pin13(13);

void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
  pin11.Write(HIGH);
  pin12.Write(LOW);
  pin13.Write(HIGH);

  delay(1000);              // wait for a second
  pin11.Write(LOW);
  pin12.Write(HIGH);
  pin13.Write(LOW);
  delay(1000);              // wait for a second
}
