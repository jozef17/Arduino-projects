#ifndef TETRIS_HPP_
#define TETRIS_HPP_

#include "Game.hpp"

class Tetris final : public Game
{
  public:
    Tetris();

    virtual void Start() override;
    
    virtual void Reset() override;

    virtual void HandlePress(Key pressedKey) override;

    virtual void Tick() override;

    virtual void Render(uint8_t *buffer) override; 

    virtual bool IsRunning() override;
    
  private:
    void NewTetrino();
    
    bool IsEmpty(uint8_t x, uint8_t y) const;

    void UpdateState();

    void CheckState();

    const uint8_t *GetMap() const;
    
    uint8_t game[6];
    uint8_t tetrinoLoc;   // 0bXXXXYYYY
    uint8_t tetrinoState; // 0bRRRRTTTT (Rotation, Type)

    bool    running; 
    uint8_t tickCount;
    
};

#endif /* TETRIS_HPP_ */
