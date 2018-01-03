/*
 * ledPWM.c
 *
 *  Created on: 20.11.2017
 *      Author: AzizS
 */

#include "../led.h"
#include "../../../../hal/gpio/gpio.h"
#include "src/hal/PMW/pwm.h"

void ledPWM_init(LedColor_t led){
    switch (led) {
        case RED_LED:
        case GREEN_LED:
        case BLUE_LED:
            hal_enablePeripheral(LED_PORT);
            hal_enablePeripheral(PWM1);
            break;
        }

    GpioPin_t pin = 0;
        switch (led) {
        case RED_LED:
            pin = LED_PIN_RED;
            break;
        case GREEN_LED:
            pin = LED_PIN_GREEN;
            break;
        case BLUE_LED:
            pin = LED_PIN_BLUE;
            break;
        }
        gpio_setMode(LED_PORT, pin, OUTPUT_MODE_MULTIPLEXED);
        gpio_setMux(LED_PORT, pin, PWM_MODE);


}

void ledPWM_setBrightness(LedColor_t led, uint8_t percent){

    switch(led){

    case RED_LED:
        pwm_setDuty(PWM1, 2, 1, percent);
        pwm_setEnable(PWM1, 2, true);
        break;

    case BLUE_LED:
        pwm_setDuty(PWM1, 3, 0, percent);
        pwm_setEnable(PWM1, 3, true);
        break;

    case GREEN_LED:
        pwm_setDuty(PWM1, 3, 1, percent);
        pwm_setEnable(PWM1, 3, true);
        break;

    }

}


