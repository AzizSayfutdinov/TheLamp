/*
 * led.h
 *
 *  Created on: 16.10.2017
 *      Author: Nico
 */

#ifndef SRC_SYSTEM_DRIVER_LED_LED_H_
#define SRC_SYSTEM_DRIVER_LED_LED_H_

#include <stdbool.h>

typedef enum {
    RED_LED,
    GREEN_LED,
    BLUE_LED
} LedColor_t;

void led_init(LedColor_t led);
void led_setState(LedColor_t led, bool state);
void led_toggleState(LedColor_t led);

#endif /* SRC_SYSTEM_DRIVER_LED_LED_H_ */
