/*
 * hal.c
 *
 *  Created on: 16.10.2017
 *      Author: AzizS
 */

#include "hal.h"
#include <inttypes.h>

void hal_enablePeripheral(Peripheral_t peripheral) {

    switch(peripheral){

    case ADC0:
        SYSCTL_RCGCADC_R |= (1 << 0); // falscher Register muss iweas mit _R: GELÖST
        return;

    case UART0:
        SYSCTL_RCGCUART_R |= (1 << 0);
        return;

    case UART1:
       SYSCTL_RCGCUART_R |= (1 << 1);
       return;

    case PWM1:
        SYSCTL_RCGCPWM_R |= (1 << 1);
        return;

    case PWM0:
        SYSCTL_RCGCPWM_R |= (1 << 0);
        return;
    case I2C0:
    case I2C1:
    case I2C2:
    case I2C3:
        SYSCTL_RCGCI2C_R |= (1 << (peripheral - I2C0)); //if peripheral == I2C -> I2C-I2C = 0, bit 0 is set
        return;

    }

    // Enable clock
    SYSCTL_RCGCGPIO_R |= (1 << peripheral); //only valid for PORTA to PORTF


    // Enable Advanced High-Performance Bus (AHB) instead of legacy Advanced Peripheral Bus (APB)
    switch (peripheral) {

    case PORTA:
        SYSCTL_GPIOHBCTL_R |= SYSCTL_GPIOHBCTL_PORTA;
        break;

    case PORTB:
        SYSCTL_GPIOHBCTL_R |= SYSCTL_GPIOHBCTL_PORTB;
        break;

    case PORTD:
        SYSCTL_GPIOHBCTL_R |= SYSCTL_GPIOHBCTL_PORTD;
        break;
    // TODO Other cases for PORT B to E
    case PORTF:
        SYSCTL_GPIOHBCTL_R |= SYSCTL_GPIOHBCTL_PORTF;
        break;

    }
}

void hal_initWatchdog(uint32_t loadReg) {
    SYSCTL_RCGCWD_R |= (1 << 0);
    while ((SYSCTL_RCGCWD_R & (1 << 0)) == 0) {

    }
    WATCHDOG0_LOAD_R = loadReg;
    WATCHDOG0_CTL_R = 0b11;
}

void hal_feedWatchdog(uint32_t loadReg) {
    WATCHDOG0_LOAD_R = loadReg;
}
