/*
 * light.c
 *
 *  Created on: 03.12.2017
 *      Author: AzizS
 */

#include "src/hal/I2C/i2c.h"
#include "src/hal/hal.h"
#include "src/hal/gpio/gpio.h"
#include "src/hal/gpio/ADC/ADC.h"

void light_init(){

    gpio_setMode(PORTD, 0, OUTPUT_MODE_MULTIPLEXED);
    gpio_setMode(PORTD, 1, OUTPUT_MODE_MULTIPLEXED);
    gpio_setMux(PORTD, 0, I2C_MODE);
    gpio_setMux(PORTD, 1, I2C_MODE);
    i2c_init(I2C3);

}


