#ifndef VIEW_HPP_
#define VIEW_HPP_

#include "PinConst.hpp"
#include "WaterPump.hpp"

#include <Button.hpp>

class View final
{
  public:
    View() {};
    ~View() {};

    // TODO CHECK INPUTS

    inline Button::BtnState CheckButton() { return button.GetChange(); }
    inline uint16_t GetMoisture() const { return soilMoistureSensor.Read(); }

    inline void TurnPumpOn() { this->pump.On(); };
    inline void TurnGreenLEDOn() { this->greenLED.Write(1); };
    inline void TurnYellowLEDOn() { this->yellowLED.Write(1); };

    inline void TurnPumpOff() { this->pump.Off(); };
    inline void TurnGreenLEDOff() { this->greenLED.Write(0); };
    inline void TurnYellowLEDOff() { this->yellowLED.Write(0); };
    
  private:
    // TODO Controller
  
    // Inputs
    Button button{BUTTON_PIN};
    InputPin soilMoistureSensor{MOISTURE_SENSOR_PIN};

    // Outputs
    WaterPump pump{PUMP_PIN};
    OutputPin greenLED{GREEN_LED_PIN};
    OutputPin yellowLED{YELLOW_LED_PIN};
    
};

#endif /* VIEW_HPP_ */
