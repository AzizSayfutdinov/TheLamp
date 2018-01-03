/*
 * i2c.h
 *
 *  Created on: 27.11.2017
 *      Author: AzizS
 */

#ifndef SRC_HAL_I2C_I2C_H_
#define SRC_HAL_I2C_I2C_H_

#include "../hal.h"
#include "../gpio/gpio.h"

void i2c_init(Peripheral_t i2cModule);
void i2c_read(Peripheral_t i2cModule, uint8_t slaveAdr, uint8_t reg, uint8_t* pOut);
void i2c_write(Peripheral_t i2cModule, uint8_t slaveAdr, uint8_t red, uint8_t input);


#endif /* SRC_HAL_I2C_I2C_H_ */
