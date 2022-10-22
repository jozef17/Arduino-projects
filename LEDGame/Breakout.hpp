#ifndef BREAKOUT_HPP_
#define BREAKOUT_HPP_

#include "Game.hpp"

class Breakout final : public Game
{
  public:
    Breakout();

    virtual void Start() override;
    
    virtual void Reset() override;

    virtual void HandlePress(Key pressedKey) override;

    virtual void Tick() override;

    virtual void Render(uint8_t *buffer) override;

    virtual bool IsRunning() override;

  private:
    void UpdateLoc();

    void GetNewLoc(uint8_t &x, uint8_t &y) const;
    
    bool CheckLoc();
    bool CheckBorders(uint8_t &x, uint8_t &y);

    // Direction 0 is diagonaly down and right.
    // Following directions are counterclokwise by 45 degree
    // e.g. direction 1 - to right, 2 - diagonaly up and right, ...
    uint8_t direction;
    uint8_t ballLoc;
    uint8_t padLoc;
    uint8_t game[4];

    uint8_t tickCount;
    bool    running;    
};

#endif /* BREAKOUT_HPP_ */
