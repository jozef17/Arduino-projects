#include "SerialLogger.hpp"
#include <Core.hpp>

SerialLogger::SerialLogger()
{
  Serial.begin(9600);
}

SerialLogger::~SerialLogger()
{
  Serial.end();
}

void SerialLogger::Log(const char * msg)
{
  Serial.println(msg);
}

void SerialLogger::Log(int msg)
{
  Serial.println(msg, DEC);
}

Logger& SerialLogger::GetInstance()
{
  static SerialLogger instance;
  return instance;
}
