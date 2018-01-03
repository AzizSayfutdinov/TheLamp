/*
 * systick.h
 *
 *  Created on: 26.11.2017
 *      Author: AzizS
 */

#ifndef SRC_HAL_SYSTICK_SYSTICK_H_
#define SRC_HAL_SYSTICK_SYSTICK_H_
#include <inttypes.h>
typedef void (*SystickCallback_t)(void);

void systickCallbackInternal(void);
void systick_init(uint32_t cycles, SystickCallback_t callback);



#endif /* SRC_HAL_SYSTICK_SYSTICK_H_ */
