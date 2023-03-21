#include "SN74HC165.hpp"

SN74HC165::SN74HC165(OutputPin clock, OutputPin clockEn, OutputPin load, InputPin data) : clock(clock), clockEn(clockEn), load(load), data(data)
{ }
 /*
  // Setup 74HC165 connections
  pinMode(load, OUTPUT);
  pinMode(clockEnablePin, OUTPUT);
  pinMode(clockIn, OUTPUT);
  pinMode(dataIn, INPUT); 
  
  
    // Write pulse to load pin
  digitalWrite(load, LOW);
  delayMicroseconds(5);
  digitalWrite(load, HIGH);
  delayMicroseconds(5);


    // Get data from 74HC165
  digitalWrite(clockIn, HIGH);
  digitalWrite(clockEnablePin, LOW);
  byte incoming1 = shiftIn(dataIn, clockIn, LSBFIRST);
  byte incoming2 = shiftIn(dataIn, clockIn, LSBFIRST);
  digitalWrite(clockEnablePin, HIGH);

  */

void SN74HC165::Load(uint8_t *buffer, uint8_t byteLength)
{
  // load data
  this->load.Write(0);
  delayMicroseconds(5);
  this->load.Write(1);

  this->clock.Write(1);
  this->clockEn.Write(0);

  // Shift in data
  for(uint8_t i = 0; i < byteLength; i++)
  {
    buffer[i] = ShiftInByte();
  }
  // End
  this->clockEn.Write(1);
}

uint8_t SN74HC165::ShiftInByte()
{
  uint8_t value = 0;
  
  for(uint8_t i = 0; i < 8; i++)
  {
    this->clock.Write(0);

    uint8_t bit = this->data.Read();
    value = (value << 1) | bit;

    this->clock.Write(1);
    delayMicroseconds(2);
  }

  return value;
}
