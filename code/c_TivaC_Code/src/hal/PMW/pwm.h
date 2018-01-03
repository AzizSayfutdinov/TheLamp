/*
 * pwm.h
 *
 *  Created on: 20.11.2017
 *      Author: AzizS
 */

#ifndef SRC_HAL_PMW_PWM_H_
#define SRC_HAL_PMW_PWM_H_

#include <inttypes.h>
#include <stdbool.h>
#include "../hal.h"

//congig
//setDuty
//setFrequency, not so important
//setEndable

void pwm_config(Peripheral_t pwm, uint8_t generator, uint32_t frequency);     //A and B coppled over frequency
void pwm_setDuty(Peripheral_t pwm, uint8_t generator, uint8_t outputnumber, uint8_t percent);
void pwm_setEnable(Peripheral_t pwm, uint8_t generator, bool enable);

#endif /* SRC_HAL_PMW_PWM_H_ */



/*pwm init
PWM0_0_LOAD_R //für ote register
PWM1_2_LOAD_R // M1PWM4 and M1 PWM5
PWM1_3_LOAD_R // M1PWM6 and M1 PWM6 function to calculate the generator number
PWM1_0_GENA_R // M1PWM4
PWM1_0_GENB_R // M1PWM5, odd number is OUTPUT B
PWM1_CMPA_R   // M1PWM4, even number is OUTPUT A
*/
