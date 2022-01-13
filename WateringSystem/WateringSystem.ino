#include <SerialLogger.hpp>
#include <InputPin.hpp>

#include "WaterPump.hpp"

// Hihher value, dryer the surrounding of sensor is (520 is dry in the air)
#define START_WATERING_AT 400
// Sensor submerged in water 220
#define STOP_WATERING_AT 300

InputPin soilMoistureSensor(A0);
WaterPump waterPump(10);

void setup() {}

void loop() {
  auto soilMoisture = soilMoistureSensor.Read();
  SerialLogger::GetInstance().Log(soilMoisture);

  // Start watering if soils is dry enough
  if (soilMoisture >= START_WATERING_AT)
  {
    // Turn on pump
    waterPump.On();
    SerialLogger::GetInstance().Log("ON");
    
    // leave pump on until soil is wet enough
    do
    {
      soilMoisture = soilMoistureSensor.Read();
      SerialLogger::GetInstance().Log(soilMoisture);
      delay(1000);
    } while (soilMoisture > STOP_WATERING_AT); // Stop wattering if soil is wet enough

    // Turn off pump
    waterPump.Off();
    SerialLogger::GetInstance().Log("OFF");

  }

  delay(10000);
}
