; Functions related to SN74HC595N SIPO
; shift register
; Wiring:
;   DATA   -> D4 pin
;   LATCH  -> D5 pin
;   CLOCK  -> D6 pin
; Input in R26
; Uses R27
#define __SFR_OFFSET 0x00
#include "avr/io.h"

.global init_shift_register
.global shift_out
.global push_out

init_shift_register:
    SBI   DDRD, 4         ; set PD4 (D4) as output - Data
    SBI   DDRD, 5         ; set PD5 (D5) as output - Latch
    SBI   DDRD, 6         ; set PD6 (D6) as output - Clock
    RET

shift_out:
    LDI   R27, 8          ; 8 bits to shift
shift_out_loop:           ; shift out one bit at a time
    LSR   R26
    BRCS  data_high
    CBI   PORTD, 4        ; clear data   
    RJMP  clock_out
data_high:
    SBI   PORTD, 4        ; set data
clock_out:                ; clock out data
    SBI   PORTD, 6
    CBI   PORTD, 6
    DEC   R27
    BRNE  shift_out_loop  ; not last bit
    RET 
    
push_out:
    SBI   PORTD, 5       ; set D5 (Latch)
    CBI   PORTD, 5       ; clear D5
    RET
