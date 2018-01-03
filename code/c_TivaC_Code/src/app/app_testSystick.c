/*
 * app_testSystick.c
 *
 *  Created on: 27.11.2017
 *      Author: AzizS
 */

#include "src/system/system/system.h"
#include "src/hal/systick/systick.h"
#include <stdio.h>

void app_testSystick(){

    system_init();
    while(1){

        printf("%d\n", system_getTick());
        system_sleep(1000);
    }

}
