/*
 * button.h
 *
 *  Created on: 30.10.2017
 *      Author: Nico
 */

#ifndef SRC_SYSTEM_DRIVER_BUTTON_BUTTON_H_
#define SRC_SYSTEM_DRIVER_BUTTON_BUTTON_H_

typedef enum {
    BUTTON_SW1,
    BUTTON_SW2,
    SENSOR_BUTTON
} Button_t;

typedef void(*ButtonPressCallback_t)(void);

void button_init(Button_t button, ButtonPressCallback_t cb);

#endif /* SRC_SYSTEM_DRIVER_BUTTON_BUTTON_H_ */
