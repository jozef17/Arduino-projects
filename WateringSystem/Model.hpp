#ifndef MODEL_HPP_
#define MODEL_HPP_

#include <stdint.h>

class Model final
{
  public:
    inline void UpdateDry(uint16_t dry) { this->dry = dry; };
    inline void UpdateWet(uint16_t wet) { this->wet = wet; };

    inline uint16_t GetDry() const { return this->dry; };
    inline uint16_t GetWet() const { return this->wet; };
    
  private:
    uint16_t dry = 0;
    uint16_t wet = -1;
  
};

#endif /* MODEL_HPP_ */
