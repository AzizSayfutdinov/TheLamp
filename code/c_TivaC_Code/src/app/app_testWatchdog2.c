/*
 * app_testWatchdog2.c
 *
 *  Created on: 19.11.2017
 *      Author: AzizS
 */

#include "apps.h"
#include "../system/system/system.h"
#include "../system/driver/led/led.h"
#include "tm4c123gh6pm.h"

void app_testWatchdog2(){

    led_init(RED_LED);
    led_init(GREEN_LED);
    led_init(BLUE_LED);
    system_sleep(100);
    led_setState(RED_LED, true);
    system_sleep(1000);
    led_setState(RED_LED, false);
    system_sleep(100);
    led_setState(RED_LED, true);

    system_initWatchdog(3000);

    while(1){

        system_feedWatchdog();

        led_setState(BLUE_LED, true);
        led_setState(GREEN_LED, false);
        system_sleep(150);
        led_setState(BLUE_LED, false);
        led_setState(GREEN_LED, true);
        system_sleep(150);

       /*+ if(WATCHDOG0_LOAD_R == 0){
            SYSCTL_RESC_R = 0;
        }*/
    }




}

