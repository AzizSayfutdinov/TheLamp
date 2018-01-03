/*
 * serial.h
 *
 *  Created on: 14.11.2017
 *      Author: AzizS
 */

#ifndef SRC_SYSTEM_DRIVER_SERIAL_SERIAL_H_
#define SRC_SYSTEM_DRIVER_SERIAL_SERIAL_H_

#include "../../../hal/UART/uart.h"
#include "../../../hal/gpio/gpio.h"

void serial_init(Peripheral_t p);   //use UART0
void serial_write(uint32_t value);
void serial_read(uint32_t *pOutValue);
char serial_readChar(void);
void serial_pReadChar(char* text);
void serial_writeChar(char value);
void serial_writeText(char* text);


#endif /* SRC_SYSTEM_DRIVER_SERIAL_SERIAL_H_ */
