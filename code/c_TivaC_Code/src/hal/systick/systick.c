/*
 * systick.c
 *
 *  Created on: 26.11.2017
 *      Author: AzizS
 */

#include "systick.h"
#include "src/hal/board/board.h"
#include "src/system/system/system.h"

SystickCallback_t gsystickCallback = 0;

void systick_init(uint32_t cycles, SystickCallback_t callback){

    NVIC_ST_RELOAD_R = cycles;
    NVIC_ST_CURRENT_R = 0;
    //NVIC_ST_CTRL_R |= (1<<0) | (1<<1) | (1<<2);
    NVIC_ST_CTRL_R |= NVIC_ST_CTRL_CLK_SRC;
    NVIC_ST_CTRL_R |= NVIC_ST_CTRL_INTEN;
    NVIC_ST_CTRL_R |= NVIC_ST_CTRL_ENABLE;
    gsystickCallback = callback;
}

void systick_CallbackInternal(void)
{
    if((NVIC_ST_CTRL_R & NVIC_ST_CTRL_COUNT)){
        if(gsystickCallback != 0){
            gsystickCallback();
        }
    }
}



