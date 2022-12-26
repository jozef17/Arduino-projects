; Delay function with use of Timer0
; Uses R20
#define __SFR_OFFSET 0x00
#include "avr/io.h"

.global delay

delay:
    ; initialize timer0
    LDI   R20, 0
    OUT   TCNT0, R20      ; set timer0 count to zero
    LDI   R20, 0b00000101 ; normal mode with pre-scaler 1024
    OUT   TCCR0B, R20     ; Timer/Counter0 Control Register B

timer_loop:
    IN    R20, TIFR0      ; Timer/Counter0 Interrupt Flag Register
    SBRS  R20, TOV0       ; loop until timer0 owerflow flag (TOV0) is not set
    RJMP  timer_loop

    LDI   R20, 0
    OUT   TCCR0B, R20     ; stop timer0

    LDI   R20, (1<<TOV0)
    OUT   TIFR0, R20      ; clear timer0 owerflow flag
    RET
