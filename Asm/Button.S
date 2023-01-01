; Functions related to Push Button
; Wiring:
;   BTN   -> D10 pin
; Uses R22
#define __SFR_OFFSET 0x00
#include "avr/io.h"

.global init_btn
.global was_released

init_btn:
    CBI   DDRB, 2            ; set PB2 (D10) as input
    LDI   R22, 0             ; R19 stores last btn state
    RET

was_released:
    LDI R23,0;               ; result
    
    ; is button pressed
    SBIC  PINB, 2
    RJMP  is_pressed
    
    ; check if btn was previously pressed
    CPI   r22,0xFF
    BREQ  just_released

    RJMP was_pressed_done

just_released:
    ; btn was pressed but now is released
    LDI   R22,0
    LDI   R23,1
    RJMP  was_pressed_done
    
is_pressed:
    ; mark btn as pressed
    LDI   R22,0xFF
    
was_pressed_done:
    CPI   R23,1    
    RET
