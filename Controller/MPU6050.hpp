#ifndef MPU6050_HPP_
#define MPU6050_HPP_

#include <Core.hpp>

typedef struct
{
  uint16_t x, y, z;
} AccValues;

typedef struct
{
  uint16_t x, y, z;
} GyroValues;

// IMU Inertial Measurement Unit
class MPU6050
{
public:
  MPU6050();

  AccValues  ReadAcc();
  GyroValues ReadGyro();

private:
  void WriteRegister(uint8_t reg, uint8_t value); // TODO Move to I2C Manage

};

#endif /* MPU6050_HPP_ */