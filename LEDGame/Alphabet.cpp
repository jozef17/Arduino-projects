#include "Alphabet.hpp"

uint8_t *GetArray(char letter)
{
  static const uint8_t space[5] = { 0 }; 
  if(letter == ' ')
  {
    return space;
  }
  
  letter = letter >= 'a' ? letter - ('a'-'A') : letter;
  letter = (letter - 'A') / 2;
  
  static const uint8_t letters[] = { 0b01001100, // AB
                                     0b10101010,
                                     0b11101100,
                                     0b10101010,
                                     0b10101100, 

                                     0b01101100, // CD
                                     0b10001010,
                                     0b10001010,
                                     0b10001010,
                                     0b01101100,

                                     0b11101110, // EF
                                     0b10001000,
                                     0b11001100,
                                     0b10001000,
                                     0b11101000,

                                     0b01101010, // GH
                                     0b10001010,
                                     0b10101110,
                                     0b10101010,
                                     0b01101010,

                                     0b11101110, // IJ
                                     0b01000010,
                                     0b01000010,
                                     0b01001010,
                                     0b11100100,

                                     0b10101000, // KL
                                     0b10101000,
                                     0b11001000,
                                     0b10101000,
                                     0b10101110,
                                     
                                     0b10101010, // MN
                                     0b11101110,
                                     0b10101110,
                                     0b10101010,
                                     0b10101010,

                                     0b01001100, // OP
                                     0b10101010,
                                     0b10101100,
                                     0b10101000,
                                     0b01001000,

                                     0b01001100, // QR
                                     0b10101010,
                                     0b10101100,
                                     0b11101010,
                                     0b01101010,

                                     0b01101110, // ST
                                     0b10000100,
                                     0b01000100,
                                     0b00100100,
                                     0b11000100,

                                     0b10101010, // UV
                                     0b10101010,
                                     0b10101010,
                                     0b10101010,
                                     0b11100100,

                                     0b10101010, // WX
                                     0b10101010,
                                     0b10100100,
                                     0b11101010,
                                     0b10101010,

                                     0b10101110, // YZ
                                     0b10100010,
                                     0b01000100,
                                     0b01001000,
                                     0b01001110,
                                   };  

  return &letters[letter * 5];
}

uint8_t GetLocation(char letter)
{
  return letter % 2;
}

static void Alphabet::GetLetter(char letter, int8_t offset, uint8_t * buffer)
{
  if(offset > 7)
  {
    return;
  }
  
  auto off = 4 - offset;
  auto data = GetArray(letter);
  auto loc = GetLocation(letter);

  for(uint8_t i = 0; i<5;i++)
  {
    for(int8_t j = 0; j<4;j++)
    {
      if((off + j) < 0)
      {
        continue;
      }

      auto bit = (data[i] & 1 << (j + loc * 4)) >> (j + loc * 4);
      buffer[i] |= bit << (off + j);
    }
  }
}
