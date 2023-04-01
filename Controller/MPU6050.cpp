#include "MPU6050.hpp"
#include <Wire.h>  // TODO create manager class for use with multiple I2C devicess

#define I2C_ADDRESS 0x68  // 0x69

// MPU6065 Registers
#define CONFIG       0x1A
#define GYRO_CONFIG  0x1B
#define ACCEL_CONFIG 0x1C
#define ACCEL_XOUT   0x3B
#define GYRO_XOUT    0x43
#define PWR_MGMT_1   0x6B

MPU6050::MPU6050()
{
  // Initialize I2C
  Wire.begin();

  // Configure MPU6050
  WriteRegister(CONFIG,       0x05);  // Enable low-pass filter TODO: Check if needed
  WriteRegister(GYRO_CONFIG,  0x10);  // Gyro config
  WriteRegister(ACCEL_CONFIG, 0x10);  // Accel config
  WriteRegister(PWR_MGMT_1,   0x00);  // Reset

  delay(50);
}

AccValues MPU6050::ReadAcc()
{
  AccValues acc = {0, 0, 0};

  // Read Accelerometer data
  Wire.beginTransmission(I2C_ADDRESS);
  Wire.write(ACCEL_XOUT);
  Wire.endTransmission(false);

  Wire.requestFrom(I2C_ADDRESS, 6);
  acc.x = Wire.read() << 8 | Wire.read();
  acc.y = Wire.read() << 8 | Wire.read();
  acc.z = Wire.read() << 8 | Wire.read();

  return acc;
}

GyroValues MPU6050::ReadGyro()
{
  GyroValues gyro = {0, 0, 0};

  // Read Gyroscope data
  Wire.beginTransmission(I2C_ADDRESS);
  Wire.write(GYRO_XOUT);
  Wire.endTransmission(false);

  Wire.requestFrom(I2C_ADDRESS, 6);
  gyro.x = Wire.read() << 8 | Wire.read();
  gyro.y = Wire.read() << 8 | Wire.read();
  gyro.z = Wire.read() << 8 | Wire.read();

  return gyro;
}

void MPU6050::WriteRegister(uint8_t reg, uint8_t value)
{
  Wire.beginTransmission(I2C_ADDRESS);
  Wire.write((unsigned int)reg);
  Wire.write((unsigned int)value);
  Wire.endTransmission(true);
}

