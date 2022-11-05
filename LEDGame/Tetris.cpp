#include "Tetris.hpp"

#define SPEED 5

Tetris::Tetris()
{
  Reset();
}

void Tetris::Start()
{
  this->running = true;
}
    
void Tetris::Reset()
{
  memset(this->game, 0, 6);
  this->tickCount = 0;
  this->running = false;
  NewTetrino();
}

void Tetris::HandlePress(Key pressedKey)
{
  if(pressedKey != Key::Up && pressedKey != Key::Down) 
  {
    return;
  }

  // Check new position
  uint8_t y = this->tetrinoLoc & 0b00001111;
  uint8_t x = this->tetrinoLoc >> 4;
  pressedKey == Key::Down ? x++ : x--;

  if(IsEmpty(x, y))
  { 
    this->tetrinoLoc = x << 4 | y;  
  }
}

void Tetris::Tick()
{
  this->tickCount = ++this->tickCount % SPEED;
  if(tickCount == SPEED - 1)
  {
    uint8_t y = this->tetrinoLoc & 0b00001111;
    uint8_t x = this->tetrinoLoc >> 4;
    
    if(y == 0)
    {
      UpdateState();
      NewTetrino();
      return;
    }
    
    // Check Map
    bool isEmpty = IsEmpty(x, y - 1);

    // End game check
    auto map = GetMap();
    for(uint8_t i = 0; (i < 4) && !isEmpty; i++)
    {
      uint8_t ty = map[i] & 0b00001111;
      if((ty + y) > 7)
      {
        this->running = false;
        return;
      }
    }

    // Update state
    if(!isEmpty && this->running)
    {
      UpdateState();
      NewTetrino();
    }
    else
    {
      this->tetrinoLoc = x << 4 | (--y); // move down
    }    
  } // Time
}

void Tetris::Render(uint8_t *buffer)
{
  memcpy(buffer, this->game, 6);

  // Get Tetrino
  auto map = GetMap();
  // Get Tetrino current location
  uint8_t y = this->tetrinoLoc & 0b00001111;
  uint8_t x = this->tetrinoLoc >> 4;

  // Display current tertino
  for(uint8_t i = 0; i < 4; i++)
  {
    uint8_t ty = map[i] & 0b00001111;
    uint8_t tx = map[i] >> 4;
    buffer[tx + x] |= 1 << (ty + y);
  }
}

bool Tetris::IsRunning()
{
  return this->running;
}

void Tetris::NewTetrino()
{
  uint8_t type = random(7);
  uint8_t rotation = random(4);
  this->tetrinoState = rotation << 4 | type;
  this->tetrinoLoc = 2 << 4 | 7;
}

bool Tetris::IsEmpty(uint8_t x, uint8_t y) const
{
  auto map = GetMap();
  for (uint8_t i = 0; i < 4; i++)
  {
    uint8_t ty = map[i] & 0b00001111;
    uint8_t tx = map[i] >> 4;

    if (tx + x > 5)
    {
      return false;
    }
    
    if (ty + y > 7)
    {
        continue;
    }

    if (this->game[tx + x] & 1 << (ty + y))
    {
       return false;
    }
  }
  return true;
}

void Tetris::UpdateState()
{
  uint8_t y = this->tetrinoLoc & 0b00001111;
  uint8_t x = this->tetrinoLoc >> 4;

  auto map = GetMap();
  for (uint8_t i = 0; i < 4; i++)
  {
    uint8_t ty = map[i] & 0b00001111;
    uint8_t tx = map[i] >> 4;
    this->game[tx + x] |= 1 << (ty + y);
  }

  CheckState();
}

void Tetris::CheckState()
{
  // Check for clearing
  for (uint8_t i = 0; i < 8; i++)
  {
    // Check if line is full
    bool full = true;
    for (uint8_t j = 0; j < 6; j++)
    {
      if ((this->game[j] & 1 << i) == 0)
      {
        full = false;
        break;
      }
    }

    // Clear full line
    if (full)
    {
      for (uint8_t j = 0; j < 6; j++)
      {
        // Bits to the right from current line
        uint8_t before = this->game[j] << (8 - i);
        before = before >> (8 - i);

        // Bits to the left from current line
        uint8_t after = this->game[j] >> i + 1;
        after = after << i;

        this->game[j] = after | before;
      }
      i--;
    } // if(full) end
  } // Check for clearing End      
}

const uint8_t *Tetris::GetMap() const
{
  uint8_t type = this->tetrinoState & 0b00001111;
  uint8_t rotation = this->tetrinoState >> 4;

  static const uint8_t maps[4][7][4] = { 
      // Rot 0
      { {1 << 4 | 2, 1 << 4 | 1, 1 << 4, 0},  // L
        {2 << 4 | 1, 1 << 4 | 1, 1 << 4, 0},  // Z
        {2 << 4    , 1 << 4 | 1, 1 << 4, 1},  // S
        {1 << 4    ,          2,      1, 0},  // J
        {2 << 4 | 1, 1 << 4 | 1, 1 << 4, 1},  // T
        {         3,          2,      1, 0},  // I
        {1 << 4 | 1, 1 << 4    ,      1, 0},  // O
      },
      // Rot 1
      { {2 << 4    , 1 << 4    ,      1, 0},  // L
        {1 << 4    , 1 << 4 | 1,      1, 2},  // Z
        {1 << 4 | 2, 1 << 4 | 1,      1, 0},  // S
        {2 << 4 | 1, 1 << 4 | 1,      1, 0},  // J
        {1 << 4 | 2, 1 << 4 | 1, 1 << 4, 1},  // T
        {3 << 4    , 2 << 4    , 1 << 4, 0},  // I
        {1 << 4 | 1, 1 << 4    ,      1, 0},  // O
      },
      // Rot 2
      { {1 << 4 | 2,          2,      1, 0},  // L
        {2 << 4 | 1, 1 << 4 | 1, 1 << 4, 0},  // Z
        {2 << 4    , 1 << 4 | 1, 1 << 4, 1},  // S
        {1 << 4 | 2, 1 << 4 | 1, 1 << 4, 2},  // J
        {2 << 4    , 1 << 4 | 1, 1 << 4, 0},  // T
        {         3,          2,      1, 0},  // I
        {1 << 4 | 1, 1 << 4    ,      1, 0},  // O
      },
      // Rot 3
      { {2 << 4 | 1, 1 << 4 | 1,      1, 0},  // L
        {1 << 4    , 1 << 4 | 1,      1, 2},  // Z
        {1 << 4 | 2, 1 << 4 | 1,      1, 0},  // S
        {2 << 4 | 1, 2 << 4    , 1 << 4, 0},  // J
        {         2, 1 << 4 | 1,      1, 0},  // T
        {3 << 4    , 2 << 4    , 1 << 4, 0},  // I
        {1 << 4 | 1, 1 << 4    ,      1, 0},  // O
      } };

  return &maps[rotation][type][0];
}
