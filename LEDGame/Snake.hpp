#ifndef SNAKE_HPP_
#define SNAKE_HPP_

#include "Game.hpp"

class Snake final : public Game
{
  public:
    Snake();

    virtual void Start() override;
    
    virtual void Reset() override;

    virtual void HandlePress(Key pressedKey) override;

    virtual void Tick() override;

    virtual void Render(uint8_t *buffer) override;

    virtual bool IsRunning() override;

  private:
    void SetLoc();

    bool    running;
    Key     direction;
    uint8_t tickCount;
    uint8_t loc;
    uint8_t game[6][8];
    uint8_t snakeLength;
};

#endif /* SNAKE_HPP_ */
