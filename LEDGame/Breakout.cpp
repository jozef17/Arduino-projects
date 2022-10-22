#include "Breakout.hpp"

#define SPEED 6
#define PAD_LENGTH 3

Breakout::Breakout()
{
  Reset();
}

void Breakout::Start()
{
  this->running = true;
}
    
void Breakout::Reset()
{
  memset(this->game, 255, 3);
  memset(&this->game[3], 0, 1);
    
  this->direction = 0;
  this->running   = false;
  this->ballLoc   = 5 << 4 | 3;
  this->padLoc    = 5;
  this->tickCount = 0;
}

void Breakout::HandlePress(Key pressedKey)
{
  if(pressedKey == Key::Right)
  {
    this->padLoc--;
    if(this->padLoc < (PAD_LENGTH - 1))
    {
      this->padLoc = (PAD_LENGTH - 1);
    }
  }
  else if(pressedKey == Key::Left)
  {
    this->padLoc++;
    if(this->padLoc > 7)
    {
      this->padLoc = 7;
    }
  }
}

void Breakout::Tick()
{
  this->tickCount = ++this->tickCount % SPEED;
  if(tickCount == SPEED - 1)
  {
    UpdateLoc();
  }
}

void Breakout::Render(uint8_t *buffer)
{
  memset(buffer, 0, 6);

  // Render state
  memcpy(buffer, this->game, 4);

  // Blink ball
  if (!this->running || (this->tickCount % SPEED) >= (SPEED / 2))
  {    
    uint8_t y = this->ballLoc & 0b00001111;
    uint8_t x = this->ballLoc >> 4;
    buffer[y] |= 1 << x;
  }
      
  // Render pad
  for(uint8_t i = 0; i < PAD_LENGTH; i++)
  {
    buffer[5] |= 1<< this->padLoc - i;
  }
}

bool Breakout::IsRunning()
{
  return this->running;
}

void Breakout::UpdateLoc()
{
  // Check if game is still running
  if(!this->running)
  {
    return;
  }

  // Current ball location
  uint8_t y = this->ballLoc & 0b00001111;
  uint8_t x = this->ballLoc >> 4;
    
  // Check if empty
  if(!CheckLoc())
  {
    UpdateLoc();
    return;
  }

  GetNewLoc(x, y);
  if(!CheckBorders(x, y))
  {
    UpdateLoc();
    return;
  }
  
  this->ballLoc = x << 4 | y;
}

void Breakout::GetNewLoc(uint8_t &x, uint8_t &y) const
{
  switch(this->direction)
  {
    case 0:
      x--;
      y++;
      break;
    case 1:
      x--;
      break;
    case 2:
      y--;
      x--;
      break;
    case 3:
      y--;
      break;
    case 4:
      y--;
      x++;
      break;
    case 5:
      x++;
      break;
    case 6:
      y++;
      x++;
      break;
    case 7:
      y++;
      break;
  }
}

bool Breakout::CheckLoc()
{
  const uint8_t above = 0b00000001;
  const uint8_t below = 0b00000010;
  const uint8_t left  = 0b00000100;
  const uint8_t right = 0b00001000;

  uint8_t y = this->ballLoc & 0b00001111;
  uint8_t x = this->ballLoc >> 4;
  
  uint8_t cleared = 0;

  if(y > 3)
  {
    return true;
  }

  // Check neighbouring locations
  // Check above
  if(y > 0 && (this->game[y-1] & 1 << x) // Above loc
     && this->direction >= 2 && this->direction <= 4) // Current direction is up
  {
    this->game[y-1] &= ~(1 << x);
    cleared |= above;
  }
  // Check below
  else if(y < 3 && (this->game[y+1] & 1 << x) // below loc
          && (this->direction == 0 || this->direction == 6 || this->direction == 7)) // Current direction is down
  {
    this->game[y+1] &= ~(1 << x);
    cleared |= below;
  }

  // Check left
  if(x < 8 && (this->game[y] & 1 << (x+1)) // Left loc
     && this->direction >= 4 && this->direction <= 6) // Current direction is left
  {
    this->game[y] &= ~(1 << (x+1));
    cleared |= left;
  // check right
  }else if(x > 0 && (this->game[y] & 1 << (x-1)) // Right loc
           && this->direction >= 0 && this->direction <= 2)// Current direction is right
  {
    this->game[y] &= ~(1 << (x-1));
    cleared |= right;
  }

  // Nothing cleared
  if(cleared == 0)
  {
    // Check diagonals
    if(this->direction == 0 && y < 3 && x > 0
       && this->game[y + 1] & 1 << (x - 1))
    {
      this->game[y + 1] &= ~(1 << (x -1));
      this->direction = 4;
    }
    if(this->direction == 2 && y > 0 && x > 0
       && this->game[y - 1] & 1 << (x - 1))
    {
      this->game[y - 1] &= ~(1 << (x - 1));
      this->direction = 6;
    }
    if(this->direction == 4 && y > 0 && x < 8
       && this->game[y - 1] & 1 << (x + 1))
    {
      this->game[y - 1] &= ~(1 << (x + 1));
      this->direction = 0;
    }
    if(this->direction == 6 && y < 3 && x < 8
       && this->game[y + 1] & 1 << (x + 1))
    {
      this->game[y + 1] &= ~(1 << (x + 1));
      this->direction = 2;
    }
    return true;
  }

  // Get Random New Direction
  uint8_t rand = random(100);
  if(cleared == above) // cleared only above
  {
    switch(this->direction)
    {
      case 2:
        this->direction = rand < 60 ? 0 : 7;
        break;
      case 3:
        this->direction = rand < 50 ? 0 : 6;
        break;
      case 4:
        this->direction = rand < 60 ? 6 : 7;
        break;
    }
    return false;
  }
  else if(cleared == below) // cleared only below
  {
    switch(this->direction)
    {
      case 0:
        this->direction = rand < 60 ? 2 : 3;
        break;
      case 6:
        this->direction = rand < 4 ? 0 : 3;
        break;
      case 7:
        this->direction = rand < 60 ? 2 : 4;
        break;
    }
    return false;
  }
  else if(cleared == left) // cleared only left
  {
    switch(this->direction)
    {
      case 4:
        this->direction = rand < 60 ? 2 : 1;
        break;
      case 5:
        this->direction = rand < 50 ? 0 : 2;
        break;
      case 6:
        this->direction = rand < 60 ? 0 : 1;
        break;
    }
    return false;
  }
  else if(cleared == right) // cleared only right
  {
    switch(this->direction)
    {
      case 0:
        this->direction = rand < 60 ? 6 : 5;
        break;
      case 1:
        this->direction = rand < 50 ? 4 : 6;
        break;
      case 2:
        this->direction = rand < 60 ? 4 : 5;
        break;
    }
    return false;
  }
  else if(cleared == above | left) // cleared above and left
  {
    this->direction = 0;
    return false;
  }
  else if(cleared == above | right) // cleared above and right
  {
    this->direction = 6;
    return false;
  }
  else if(cleared == below | left) // cleared below and left
  {
    this->direction = 2;
    return false;
  }
  else if(cleared == below | right) // cleared below and right
  {
    this->direction = 4;
    return false;
  }
}

bool Breakout::CheckBorders(uint8_t &x, uint8_t &y)
{
  uint8_t oldY = this->ballLoc & 0b00001111;
  uint8_t oldX = this->ballLoc >> 4;

  // Check borders
  if(x == 8)
  {
    uint8_t rand = random(100);
    if(this->direction == 4)
    {
      this->direction = rand < 60 ? 2 : 1;
    }
    else if(this->direction == 5)
    {
      this->direction = rand < 50 ? 0 : 2;
    }
    else if(this->direction == 6)
    {
      this->direction = rand < 60 ? 0 : 1;
    }
    return false;
  }
  else if(x == (uint8_t)-1)
  {
    uint8_t rand = random(100);
    if(this->direction == 0)
    {
      this->direction = rand < 60 ? 6 : 5;
    }
    else if(this->direction == 1)
    {
      this->direction = rand < 50 ? 4 : 6;
    }
    else if(this->direction == 2)
    {
      this->direction = rand < 60 ? 4 : 5;
    }
    return false;
  }
  else if(y == 5)
  {
    // Bottom border check
    if(oldX <= this->padLoc && oldX >= this->padLoc - 2)
    {
      uint8_t rand = random(100);
      if(this->direction == 0)
      {
        this->direction = rand < 60 ? 2 : 3;
      }
      else if(this->direction == 6)
      {
        this->direction = rand < 60 ? 4 : 3;
      }
      else if(this->direction == 7)
      {
        this->direction = rand < 50 ? 2 : 4;
      }
      return false;
    } 
    else
    {
      this->running = false;
      return false;
    }
  }
  else if(y == (uint8_t)-1)
  {
    uint8_t rand = random(100);
    if(this->direction == 2)
    {
      this->direction = rand < 60 ? 0 : 7;
    }
    else if(this->direction == 3)
    {
      this->direction = rand < 50 ? 0 : 6;
    }
    else if(this->direction == 4)
    {
      this->direction = rand < 60 ? 6 : 7;
    }
    return false;
  }
  return true;
}
