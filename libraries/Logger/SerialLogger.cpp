#include "SerialLogger.hpp"

SerialLogger::SerialLogger()
{
  Serial.begin(9600);
}

SerialLogger::~SerialLogger()
{
  Serial.end();
}

void SerialLogger::Log(const char* message)
{
  Serial.print(message);
}

void SerialLogger::Log(long msg, int base)
{
  Serial.print(msg, base);
}

Logger& SerialLogger::GetInstance()
{
  static SerialLogger instance;
  return instance;
}
