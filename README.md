# Arduino-projects
Arduino projects

## [libraries](libraries)
Contains shared functionality 
- Core
- Devices
    - Device abstarcions (like button, Stepper motor,...)
- Logger
- Pin
    - I/O pin abstarcions

## [Assembly](Asm)
- Simple (AVR) assembly language (for ATmega328) project
- LED pattern "changer"

![Demo](Asm/media/Asm.gif)

## [LED Games](LEDGame)
- Implemented games:
    - Breakout
    - Snake
    - Tetris
- 6 by 8 (red) LED "display"

**NOTE:** only one game deployed at a time

![Demo](LEDGame/media/BreakoutGame.gif)

![Demo](LEDGame/media/SnakeGame.gif)

![Demo](LEDGame/media/TetrisGame.gif)

## [Watering System](WateringSystem)

- Automated plant wattering system
- Includes callibration / re-callibration
- 2 status indicating LEDs
- Button press switches between callibration and wattering mode
- Driven by state machine

![Demo](WateringSystem/media/Watering.gif)
