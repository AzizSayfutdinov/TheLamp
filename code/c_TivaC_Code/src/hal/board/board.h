/*
 * board.h
 *
 *  Created on: 16.10.2017
 *      Author: Aziz
 */

#ifndef SRC_HAL_BOARD_BOARD_H_
#define SRC_HAL_BOARD_BOARD_H_

#include <tm4c123gh6pm.h>
#include "../hal.h"

#define LED_PORT                (PORTF)
#define LED_PIN_RED             (1)
#define LED_PIN_BLUE            (2)
#define LED_PIN_GREEN           (3)

#define BUTTON_PORT             (PORTF)
#define BUTTON_SW1_PIN          (4)
#define BUTTON_SW2_PIN          (0)

#define PIN_A0                  (0) // UART0Rx, nicht wie im Datenblatt Pin 17, sondern 0
#define PIN_A1                  (1) // UART0Tx

#define PIN_B0                  (0)
#define PIN_B1                  (1)

#define CPU_SPEED               (16000000)
#define BAUDRATE_115200         (115200)
#define BAUDRATE_9600           (9600)

#endif /* SRC_HAL_BOARD_BOARD_H_ */
