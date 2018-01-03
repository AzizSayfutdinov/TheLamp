/*
 * app_testButton.c
 *
 *  Created on: 30.10.2017
 *      Author: Nico
 */

#include "apps.h"
#include "../system/system/system.h"
#include "../system/driver/button/button.h"
#include "../system/driver/led/led.h"
#include <inttypes.h>

static void buttonPressCallback(void);
static void buttonSensorPressCallback(void);
static bool gState = false;

void app_testButton() {

    led_init(RED_LED);
    led_init(BLUE_LED);
    button_init(BUTTON_SW1, buttonPressCallback);
    button_init(SENSOR_BUTTON, buttonSensorPressCallback);

    led_setState(RED_LED, true);

    bool state = false;
    while(1) {
        system_sleep(1000);
        led_setState(BLUE_LED, (state = !state));
    }
}

void buttonPressCallback() {
    // I want to toggle the red LED w/o led_toggleState(..)
    led_setState(RED_LED, (gState = !gState));
}

void buttonSensorPressCallback() {
    // I want to toggle the red LED w/o led_toggleState(..)
    led_setState(RED_LED, (gState = !gState));
}
