/*
 * app_testWatchdog.c
 *
 *  Created on: 29.10.2017
 *      Author: AzizS
 */

#include "apps.h"
#include "../system/system/system.h"
#include "../system/driver/led/led.h"

void app_testWatchdog() {

    led_init(RED_LED);
    system_sleep(100);
    led_setState(RED_LED, true);
    system_sleep(1000);
    led_setState(RED_LED, false);
    system_sleep(100);
    led_setState(RED_LED, true);

    system_initWatchdog(10000);

    while(1) {
        system_feedWatchdog();
        system_sleep(2000);
        led_toggleState(RED_LED);
    }
}
