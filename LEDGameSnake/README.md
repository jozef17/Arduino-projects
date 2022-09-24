# (WIP) LED Game - Snake

- TODO
- HW componenrts include:
    - Arduino (nano was used)
    - 6x SIPO shift Register - SN74HC595N (**data** connected to pin **D4**, **clock** connected to pin **D6** and **latch** connected to pin **D5**)
    - 24x LEDs
    - 64x 220Ω resistors or 6x 9-pin 220Ω resistor array
    - 4x 10kΩ resistors
    - 4x Push button (connected to **D9** - **D12** pinpins)
    - 9 by 15 prototype PCB board 
    - Cables

TODO IMAGE

## User Manual
TODO

## Hardware Setup

TODO gif

For better clarity, wiring was split into 3 parts:
- Buttons
- One line of LEDs
- Shift registers daisychain

### Buttons
TODO gif

![Demo](media/Buttons.png)

### LEDs
TODO gif

![Demo](media/LEDs.png)

### Shift Registers
TODO gif

![Demo](media/ShiftRegisterChain.png)
**NOTE:** Because of limited space, the diagram does not show sixth schift register. The last shift register is wired in the same way as previous shift registers.

## Architecture
TODO

### State Machine
TODO

### Class Model
TODO

