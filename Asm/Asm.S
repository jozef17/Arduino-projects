; Main loop

#define __SFR_OFFSET 0x00
#include "avr/io.h"

.global main

.equ pattern_steps_count, 8

.org  0x00

main:
    ; initialization
    RCALL init_shift_register
    RCALL init_btn

    LDI   R19,0             ; which pattern changed by button press

; main loop
loop:
    LDI   R18,0             ; step in pattern
    
pattern_loop_inc:
    ; Get byte to shift out
    LDI   ZL,lo8(patterns)
    LDI   ZH,hi8(patterns)
    ADD   ZL,R19
    ADD   ZL,R18

    ; shift out byte
    LPM   R26,Z             ; load program memory
    RCALL shift_out
    RCALL push_out

    ; delay and check btn
    LDI   R17,0
delay_and_btn_check:
    RCALL delay
    RCALL delay

    ; Check Button
    RCALL was_released
    BREQ next_pattern
    
    INC   R17
    CPI   R17,4
    BRNE  delay_and_btn_check

    ; increment to next byte
    INC   R18
    CPI   R18, pattern_steps_count
    BRNE  pattern_loop_inc  ; pattern end loop

    RJMP  loop

next_pattern:
    LDI   R18,8
    ADD   R19,R18           ; next pattern
    CPI   R19,49            ; was last pattern?
    BRLT  loop
    LDI   R19,0             ; set first pattern
    RJMP  loop
    
patterns:
.byte 0b10000000,0b01000000,0b00100000,0b00010000,0b00001000,0b00000100,0b00000010,0b00000001   ; 0
.byte 0b00000001,0b00000010,0b00000100,0b00001000,0b00010000,0b00100000,0b01000000,0b10000000   ; 8
.byte 0b10000000,0b11000000,0b11100000,0b11110000,0b11111000,0b11111100,0b11111110,0b11111111   ; 16
.byte 0b11111111,0b11111110,0b11111100,0b11111000,0b11110000,0b11100000,0b11000000,0b10000000   ; 24
.byte 0b00000001,0b00000011,0b00000111,0b00001111,0b00011111,0b00111111,0b01111111,0b11111111   ; 32
.byte 0b11111111,0b01111111,0b00111111,0b00011111,0b00001111,0b00000111,0b00000011,0b00000001   ; 40
.byte 0b10000001,0b01000010,0b00100100,0b00011000,0b00100100,0b01000010,0b10000001,0b00000000   ; 48
