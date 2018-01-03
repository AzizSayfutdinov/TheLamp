/*
 * system.h
 *
 *  Created on: 16.10.2017
 *      Author: AzizS
 */

#ifndef SRC_SYSTEM_SYSTEM_SYSTEM_H_
#define SRC_SYSTEM_SYSTEM_SYSTEM_H_

#include <inttypes.h>

void system_sleep(uint32_t millis);
void system_initWatchdog(uint32_t millis);
void system_feedWatchdog(void);
void system_init(void);
uint32_t system_getTick(void);


#endif /* SRC_SYSTEM_SYSTEM_SYSTEM_H_ */
