#ifndef LOGGER_HPP_
#define LOGGER_HPP_

#include <Core.hpp>

class Logger
{
  public:
    virtual void Log(const char* message) = 0;
    virtual void Log(long msg, int base = DEC) = 0;

    virtual void NewLine() = 0;

  protected:
    Logger() = default;
    virtual ~Logger() = default;

};

#endif /* LOGGER_HPP_ */
