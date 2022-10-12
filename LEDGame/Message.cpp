#include "Message.hpp"
#include "Alphabet.hpp"

// MSG 1: "Ready"
void Message::SetMsg1()
{
  this->mode = 1; 
  this->location = 0;
}

// MSG 2: "Game Over"
void Message::SetMsg2()
{
  this->mode = 2;
  this->location = 0;
}

void Message::Render(uint8_t *buffer)
{
  memset(buffer, 0, 6);
  if(this->mode == 2)
  {
    char message[] = "GAME OVER";

    RenderMsg(message, 9, buffer);
    if(this->location == 0)
    {
      SetMsg1();
    }
  }
  else
  {
    char message[] = "READY";
    RenderMsg(message, 5, buffer);
  }
}

void Message::RenderMsg(char *message, uint8_t length, uint8_t *buffer)
{
  int8_t x = (this->location +1)/4 - 2;
  Alphabet::GetLetter(message[x < 0 ? 0 : x],7 - this->location + ((x < 0 ? 0 : x)*4)+1,buffer);    
  if((x+1) < length && (x+1) > 0)
  {
    Alphabet::GetLetter(message[x+1],7 - this->location + ((x+1)*4)+1,buffer);    
  }
  if((x+2) < length && (x+2) > 0)
  {
    Alphabet::GetLetter(message[x+2],7 - this->location + ((x+2)*4)+1,buffer);    
  }

  this->location++;
  if(this->location > ((length + 1) * 4 + 2))
  {
    this->location = 0;
  }
}
