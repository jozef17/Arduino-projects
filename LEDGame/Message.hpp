#ifndef MESSAGE_HPP_
#define MESSAGE_HPP_

#include <Core.hpp>

class Message final
{
  public:
    // MSG 1: "Ready"
    void SetMsg1();
    // MSG 2: "Game Over"
    void SetMsg2();

    void Render(uint8_t *buffer);
    
  private:
    void RenderMsg(char *message, uint8_t length, uint8_t *buffer);
  
    uint8_t mode     = 1;
    uint8_t location = 0;
};

#endif /* MESSAGE_HPP_ */
