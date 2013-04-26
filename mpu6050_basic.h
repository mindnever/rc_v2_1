#ifndef _MPU6050_BASIC_H_
#define _MPU6050_BASIC_H_

#include <stdint.h>

int mpu6050_basic_init(void);

int16_t mpu6050_temperature_raw(void);
int16_t mpu6050_temperature(void);

#endif /* _MPU6050_BASIC_H_ */
