/*
 * ledPWM.h
 *
 *  Created on: 20.11.2017
 *      Author: AzizS
 */

#ifndef SRC_SYSTEM_DRIVER_LED_LEDPWM_LEDPWM_H_
#define SRC_SYSTEM_DRIVER_LED_LEDPWM_LEDPWM_H_

void ledPWM_init(LedColor_t led);
void ledPWM_setBrightness(LedColor_t led, uint8_t percent);



#endif /* SRC_SYSTEM_DRIVER_LED_LEDPWM_LEDPWM_H_ */
