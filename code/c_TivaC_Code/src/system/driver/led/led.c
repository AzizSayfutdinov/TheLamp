/*
 * led.c
 *
 *  Created on: 16.10.2017
 *      Author: Nico
 */

#include "led.h"
#include "../../../hal/gpio/gpio.h"
#include "../../../hal/hal.h"
#include <stdint.h>

static GpioPin_t getPin(LedColor_t led) {
    GpioPin_t pin = 0;
    switch (led) {
    case RED_LED:
        pin = LED_PIN_RED;
        break;
    case GREEN_LED:
        pin = LED_PIN_GREEN;
        break;
    case BLUE_LED:
        pin = LED_PIN_BLUE;
        break;
    }
    return pin;
}

void led_init(LedColor_t led) {
    // Enable clock
    // Enable AHB
    switch (led) {
    case RED_LED:
    case GREEN_LED:
    case BLUE_LED:
        hal_enablePeripheral(LED_PORT);
        break;
    }

    // Set digital out
    // Set driving strength
    Peripheral_t port = LED_PORT;
    GpioPin_t pin = getPin(led);
    gpio_setMode(port, pin, OUTPUT_MODE_DIGITAL_OUTPUT_FULL_STRENGTH);
}

void led_setState(LedColor_t led, bool state) {
    Peripheral_t port = LED_PORT;
    GpioPin_t pin = getPin(led);
    gpio_setData(port, pin, state ? 1 : 0);
}

void led_toggleState(LedColor_t color) {
    GpioPin_t pin = getPin(color);
    if (gpio_getData(LED_PORT, pin) == 0) {
        led_setState(color, true);
    } else {
        led_setState(color, false);
    }
}
