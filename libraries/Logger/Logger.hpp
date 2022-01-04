#ifndef LOGGER_HPP_
#define LOGGER_HPP_

class Logger
{
  public:
    virtual void Log(const char * msg)   = 0;
    virtual void Log(int msg)            = 0;

  protected:
    Logger() = default;
    virtual ~Logger() {};

};

#endif /* LOGGER_HPP_ */
