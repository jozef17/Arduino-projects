#ifndef PIN_MODE_HPP_
#define PIN_MODE_HPP_

#include <stdint.h>

enum class PinMode : uint8_t
{
  input = 0,
  output,
  inputPullu
};

#endif /* PIN_MODE_HPP_ */
