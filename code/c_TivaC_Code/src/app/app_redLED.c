/*
 * app_redLED.c
 *
 *  Created on: 16.10.2017
 *      Author: Nico
 */

#include "apps.h"
#include <stdbool.h>
#include "../system/driver/led/led.h"
#include "../system/system/system.h"

void app_redLED() {

    led_init(RED_LED);

    bool state = false;
    while(true) {

        led_setState(RED_LED, (state = !state));
        system_sleep(1000 /* ms */);
    }

}

