#include "Snake.hpp"

#define SPEED 4

Snake::Snake()
{
  Reset();
}

void Snake::Reset()
{
  this->running     = true;
  this->direction   = Key::Right;
  this->tickCount   = 0;
  this->snakeLength = 3;

  memset(this->game, 0, 6 * 8);
  this->game[3][3] = 1;
  this->game[3][4] = 2;
  this->game[3][5] = 3;
 
  SetLoc();
}

void Snake::HandlePress(Key pressedKey)
{
    if (pressedKey != Key::None)
    {
        this->direction = pressedKey;
    }
}

void Snake::Tick(uint16_t diff)
{
  if(!this->running)
  {
    return;
  }
  
  this->tickCount = (this->tickCount + 1 % SPEED);
  if(tickCount % SPEED == SPEED - 1)
  {
    uint8_t headX = 0;
    uint8_t headY = 0;
    uint8_t *tail;

    // Update location
    for(uint8_t i = 0; i < 6; i++)
    {
      for(uint8_t j = 0; j < 8; j++)
      {
        if(this->game[i][j] == this->snakeLength)
        {
          tail = &this->game[i][j];
        }
        else if(this->game[i][j] == 1)
        {
          headX = j;
          headY = i;
        }
        
        if(this->game[i][j] > 0)
        {
          this->game[i][j]++;
        }
      }
    }

    // Get direction
    switch(this->direction)
    {      
    case Key::Up:
      headY--;
      break;
    case Key::Down:
      headY++;
      break;
    case Key::Left:
      headX++;
      break;
    case Key::Right:
      headX--;
      break;
    }

    // Check if new position is / will be empty
    if(headY >= 6 || headX >= 8 || 
      (this->game[headY][headX] > 0 && this->game[headY][headX] <= this->snakeLength))
    {
      this->running = false;
      return;
    }

    // Update
    this->game[headY][headX] = 1;
    
    uint8_t foodX = this->loc >> 4;
    uint8_t foodY = this->loc & 0b00001111;
    if((headY == foodY) && (headX == foodX))
    {
      this->snakeLength++;
      SetLoc();
    }
    else
    {
      *tail = 0;
    }
  }
}

void Snake::Render(uint8_t *buffer)
{
  // Render snake
  memset(buffer, 0, 6);
  for(uint8_t i = 0; i<6; i++)
  {
    for(uint8_t j = 0; j < 8; j++)
    {
      if(this->game[i][j] > 0)
      {
        buffer[i] |= 1 << j; 
      }
    }
  }

  // blink food
  if (!this->running || (this->tickCount % SPEED) < (SPEED / 2))
  {    
    uint8_t y = this->loc & 0b00001111;
    uint8_t x = this->loc >> 4;
    buffer[y] |= 1 << x;
  }
}

bool Snake::IsRunning()
{
  return this->running;
}

void Snake::SetLoc()
{
  uint8_t loc = random(6 * 8 - this->snakeLength );
  while(true)
  {
    uint8_t y = loc / 8;
    uint8_t x = loc % 8;
    if(this->game[y][x] == 0)
    {
      this->loc = x << 4 | y;
      break;
    }
    
    if( ++loc > 6 * 8)
    {
      loc = 0;
    }
  }
}
