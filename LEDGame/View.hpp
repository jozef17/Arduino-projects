#ifndef VIEW_HPP_
#define VIEW_HPP_

#include <Button.hpp>
#include "Window.hpp"
#include "PinConst.hpp"
#include "Key.hpp"

class View final
{
  public:
    inline uint8_t *GetBuffer() { return this->window.GetBuffer(); };
    inline void Render() { this->window.Render(); };

    Key CheckKey();
    
  private:    
    Button upBtn    = { UP_BUTTON };
    Button downBtn  = { DOWN_BUTTON };
    Button leftBtn  = { LEFT_BUTTON };
    Button rightBtn = { RIGHT_BUTTON };

    Window window = { DATA, CLOCK, LATCH };
  
};

#endif /* VIEW_HPP_ */
