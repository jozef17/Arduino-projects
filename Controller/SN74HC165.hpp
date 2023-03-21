#ifndef SN74HC165_HPP_
#define SN74HC165_HPP_

#include <OutputPin.hpp>
#include <InputPin.hpp>
#include <Core.hpp>

class SN74HC165
{
  public:
    SN74HC165(OutputPin clock, OutputPin clockEn, OutputPin load, InputPin data);

    // Loads state of 74HC165 chain
    // buffer - memory location to store data
    // byteLength - number of bytes to be loaded into buffer
    void Load(uint8_t *buffer, uint8_t byteLength);

  private:

    uint8_t ShiftInByte();

    OutputPin clock;
    OutputPin clockEn;
    OutputPin load;
    InputPin data;

};

#endif /* SN74HC165_HPP_ */