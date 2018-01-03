/*
 * app_testPWM.c
 *
 *  Created on: 20.11.2017
 *      Author: AzizS
 */

#include "apps.h"
#include "src/system/driver/led/led.h"
#include "src/system/system/system.h"
#include <inttypes.h>
#include "../system/driver/led/ledPWM/ledPWM.h"
#include "../hal/PMW/pwm.h"


void app_testPWM(){

    //ledPWM_init(RED_LED);
    ledPWM_init(BLUE_LED);
    //ledPWM_init(GREEN_LED);
    //pwm_config(PWM1, 2, 5);
    pwm_config(PWM1, 3, 100);
    uint8_t percent = 100;

    while(1){

        ledPWM_setBrightness(BLUE_LED, percent);

        if(percent >= 100){
            percent = 0;
        }
        percent++;
        system_sleep(20);
    }

}


