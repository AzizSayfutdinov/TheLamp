/*
 * uart.h
 *
 *  Created on: 13.11.2017
 *      Author: AzizS
 */

#ifndef SRC_HAL_UART_UART_H_
#define SRC_HAL_UART_UART_H_
#include "../hal.h"
#include "../board/board.h"
#include <stdbool.h>

typedef enum{
    NONE,
    EVEN,
    ODD
}Parity_t;

void uart_config(Peripheral_t p, uint32_t baud, Parity_t parity);
bool uart_isRXFifoEmpty(Peripheral_t p);
bool uart_isTXFifoEmpty(Peripheral_t p);
bool uart_isTXFifoFull(Peripheral_t p);
void uart_pread(Peripheral_t p, uint32_t* pValue);
void uart_write(Peripheral_t p, uint32_t value);
void uart_writeChar(Peripheral_t p, char value);
char uart_read(Peripheral_t p);


#endif /* SRC_HAL_UART_UART_H_ */
