; Delay function
; Uses R20 & R21
#define __SFR_OFFSET 0x00
#include "avr/io.h"

.global delay

delay:
    LDI   R21, 0xFF       ; outer loop counter
outer_loop:
    LDI   R20, 0xFF       ; inner loop counter
    DEC   R21
    BRNE  inner_loop
    RET
inner_loop:
    NOP                   ; Do nothing
    NOP
    NOP
    NOP
    NOP
    DEC   R20
    BRNE  inner_loop
    RJMP  outer_loop
