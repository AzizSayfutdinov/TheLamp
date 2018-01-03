/*
 * system.c
 *
 *  Created on: 16.10.2017
 *      Author: AzizS
 */

#include "system.h"
#include "src/hal/hal.h"
#include "src/hal/systick/systick.h"

#define CPU_SPEED               (16000000)
#define DEFAULT_WATCHDOG_CLOCK  (8000000)
#define FOR_LOOP_CYCLES         (12)

static uint32_t gWatchdogTime = 0;
static uint32_t gSystime = 0;
static void systickCallback(void);

void system_sleep(uint32_t millis) {
    //for (volatile uint32_t i = 0; i < (CPU_SPEED / FOR_LOOP_CYCLES / 1000) * millis; i++){
    //}
    system_init();
    uint32_t start = system_getTick();
    uint32_t predictedEnd = start + millis;
    while((system_getTick()) < predictedEnd){}
}

void system_initWatchdog(uint32_t millis) {
    gWatchdogTime = DEFAULT_WATCHDOG_CLOCK / 1000 * millis;
    hal_initWatchdog(gWatchdogTime);
}
void system_feedWatchdog() {
    hal_feedWatchdog(gWatchdogTime);
}

void system_init(void){

    //gSystime = 0xFFFFFFFF - 1000;
    systick_init(CPU_SPEED / 1000, systickCallback);
}

void systickCallback(void){
    gSystime++;
}

uint32_t system_getTick(void){

    return gSystime;
}

