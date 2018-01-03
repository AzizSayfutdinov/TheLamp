/*
 * gpio.h
 *
 *  Created on: 16.10.2017
 *      Author: Nico
 */

#ifndef SRC_HAL_GPIO_GPIO_H_
#define SRC_HAL_GPIO_GPIO_H_

#include "../hal.h"
#include <inttypes.h>

typedef uint8_t GpioPin_t;

typedef enum {
    OUTPUT_MODE_DIGITAL_OUTPUT_FULL_STRENGTH,
    OUTPUT_MODE_INPUT_PULL_UP,
    OUTPUT_MODE_MULTIPLEXED,
    OUTPUT_MODE_TEST
} OutputMode_t;

typedef enum {
    INTERRUPT_EDGE_RISING,
    INTERRUPT_EDGE_FALLING,
    INTERRUPT_EDGE_BOTH
} InterruptEdge_t;

typedef void(*InterruptFunction_t)(void);

typedef enum{
    UART_MODE,
    PWM_MODE,
    I2C_MODE
}Mux_t;

void gpio_setMode(Peripheral_t port, GpioPin_t pin, OutputMode_t mode);
void gpio_setData(Peripheral_t port, GpioPin_t pin, uint32_t value);
uint32_t gpio_getData(Peripheral_t p, GpioPin_t pin);
void gpio_enableInterrupt(Peripheral_t port, GpioPin_t pin,
                          InterruptEdge_t edge, InterruptFunction_t func);
void gpio_setMux(Peripheral_t port, GpioPin_t pin, Mux_t mux);

#endif /* SRC_HAL_GPIO_GPIO_H_ */
