#ifndef SERIAL_LOGGER_HPP_
#define SERIAL_LOGGER_HPP_

#include "Logger.hpp"

class SerialLogger final : public Logger
{
  public:
    // Delete copy and asignment constructors
    SerialLogger(const SerialLogger &) = delete;
    SerialLogger& operator=( const SerialLogger& ) = delete;

    // Get singleton instance
    static Logger& GetInstance();

    virtual void Log(const char * msg) override;
    virtual void Log(int msg) override;
    
  protected:
    SerialLogger();
    ~SerialLogger();
};

#endif /* SERIAL_LOGGER_HPP_ */
