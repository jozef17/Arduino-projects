#ifndef GAME_HPP_
#define GAME_HPP_

#include "Key.hpp"

// Game Interface
class Game
{
  public:
    virtual ~Game() = default;
  
    // Resets game to start
    virtual void Reset() = 0;

    // Key press handler
    virtual void HandlePress(Key pressedKey) = 0;

    // Tick / Time handler
    virtual void Tick(uint16_t diff) = 0;

    // Updates game view
    virtual void Render(uint8_t *buffer) = 0;

    // Is game still running?
    virtual bool IsRunning() = 0;

    // TODO Start funct

  protected:
    Game() = default;
    
};

#endif /* GAME_HPP_ */
