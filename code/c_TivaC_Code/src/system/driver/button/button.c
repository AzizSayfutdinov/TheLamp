/*
 * button.c
 *
 *  Created on: 30.10.2017
 *      Author: Nico
 */
#include "button.h"
#include "../../../hal/gpio/gpio.h"
#include "../../../hal/hal.h"
#include "../../../hal/board/board.h"

void button_init(Button_t button, ButtonPressCallback_t cb) {
    GpioPin_t pin = BUTTON_SW2_PIN;
    switch(button) {

    case SENSOR_BUTTON:
        pin = 3; // pin3 due to PD3
        hal_enablePeripheral(PORTD);
        gpio_setMode(PORTD, pin, OUTPUT_MODE_INPUT_PULL_UP);
        gpio_enableInterrupt(PORTD, pin, INTERRUPT_EDGE_RISING, cb);
        return;
    case BUTTON_SW1:
        pin = BUTTON_SW1_PIN;
    case BUTTON_SW2:
        hal_enablePeripheral(BUTTON_PORT);
        break;
    }

    Peripheral_t port = BUTTON_PORT;

    gpio_setMode(port, pin, OUTPUT_MODE_INPUT_PULL_UP);
    gpio_enableInterrupt(port, pin, INTERRUPT_EDGE_RISING, cb);

}
