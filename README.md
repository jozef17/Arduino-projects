# Arduino-projects
Arduino projects

## [libraries](libraries)
Contains shared functionality 
### Core
Core library contains commonly used includes
### InputDevices
Includes input devices abstractions
- Button
    - Distinguishes five states: **No Change**, **Pressed**, **Released**, **Long Pressed** and **Long Released**
### Logger
Contains all functionality needed for logging purposes.
- Logger interface
- SerialLogger class
    - Loggs message or number via Arduino's serial interface
    - Bound rate is **9600**
### Pin
Contains functionality related to Arduino's IO pins
- Abstract class Pin contains common functionality
- Uses registers to set and read digital values
- InputPin represents any input pin (both analog and digital)     
    - Reads current value on pin
- OutputPin represents any output pin (both PWM and digital)
    - Writes value to pin
- IOPin enables to switch between input and output of given pin
### StepperMotor
Encapsulates functionality needed for stepper motor 28BYJ-48 with driver
- Allows move stepper motor by required amount of steps in required direction
- <span style="color:Red">**Note: Changing speed is not yet supported**</span>

![Demo](libraries/ClassDiagram.png)

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
