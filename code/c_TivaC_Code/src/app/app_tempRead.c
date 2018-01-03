/*
 * app_temp.c
 *
 *  Created on: 06.11.2017
 *      Author: AzizS
 */


#include "apps.h"
#include "../system/driver/Temp/temp.h"
#include <stdio.h>
#include "../system/system/system.h"
#include "../system/driver/led/led.h"

void app_tempRead(void){

    int temp = 0;

    temp_init();
    led_init(RED_LED);
    led_init(GREEN_LED);
    led_init(BLUE_LED);

    while(1){

       temp = (int) temp_read();

        printf("Temperature: %d\n", temp); //\r\n carriage return, new line
        app_setLEDForTemp(temp);
        system_sleep(100);
    }


}

void app_setLEDForTemp(float temp){
    led_init(RED_LED);
    led_init(GREEN_LED);
    led_init(BLUE_LED);

    if(temp < 20){
        led_setState(RED_LED, false);
        led_setState(GREEN_LED, false);
        led_setState(BLUE_LED, true);
    }

    if(temp >= 20 && temp < 30){
        led_setState(RED_LED, false);
        led_setState(GREEN_LED, true);
        led_setState(BLUE_LED, false);
    }

    if(temp >= 30){
        led_setState(RED_LED, true);
        led_setState(GREEN_LED, false);
        led_setState(BLUE_LED, false);
    }
}

