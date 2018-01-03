/*
 * apps.h
 *
 *  Created on: 16.10.2017
 *      Author: Nico
 */

#ifndef SRC_APP_APPS_H_
#define SRC_APP_APPS_H_

#include <inttypes.h>

void app_redLED(void);
void app_rgbLED(void);
void app_testWatchdog(void);
void app_testWatchdog2(void);
void app_testButton(void);
void app_tempRead(void);
void app_serialWrite(uint32_t writeValue);
void app_setLEDForTemp(float temp);
void app_console(void);
void app_testPWM(void);
void app_testSystick(void);
void app_testLED_ON_OFF(void);
void app_testPWMPortD(void);

#endif /* SRC_APP_APPS_H_ */
