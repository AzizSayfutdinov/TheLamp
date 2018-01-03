/*
 * hal.h
 *
 *  Created on: 16.10.2017
 *      Author: Nico
 */

#ifndef SRC_HAL_HAL_H_
#define SRC_HAL_HAL_H_

#include "board/board.h"
#include <inttypes.h>
#include <stdbool.h>

typedef enum {
    PORTA,
    PORTB,
    PORTC,
    PORTD,
    PORTE,
    PORTF,
    PORTG,
    ADC0,
    UART0,
    UART1,
    PWM0,
    PWM1,
    I2C0,
    I2C1,
    I2C2,
    I2C3


} Peripheral_t;

void hal_enablePeripheral(Peripheral_t peripheral);
void hal_initWatchdog(uint32_t loadReg);
void hal_feedWatchdog(uint32_t loadReg);


#endif /* SRC_HAL_HAL_H_ */
