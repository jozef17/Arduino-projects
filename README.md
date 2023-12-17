# Arduino-projects
Multiple Arduino-based project developed with Arduino IDE. 
For more details about given project press the hyperlink or navigate to project directory.

## [libraries](libraries)
Contains shared functionality 
- **Core**
- **Devices**
    - Device abstarcions (like button, stepper motor,...)
- **Logger**
- **Pin**
    - I/O pin abstarcions

## [Assembly](Asm)
- Simple (AVR) assembly language (for ATmega328) project
- LED pattern "changer"

![Demo](Asm/media/Asm.gif)

## [Controller](Controller)
- RF controller

![Demo](Controller/media/Controller.png)

## [LED Games](LEDGame)
- Implemented games:
    - Breakout
    - Snake
    - Tetris
- 6 by 8 (red) LED "display"
- 4 input buttons

**NOTE:** only one game deployed at a time

![Demo](LEDGame/media/SnakeGame.gif)

## [Watering System](WateringSystem)

- Automated plant wattering system
- Includes callibration / re-callibration
- 2 status indicating LEDs
- Button press switches between callibration and wattering mode
- Driven by state machine

![Demo](WateringSystem/media/Watering.gif)
