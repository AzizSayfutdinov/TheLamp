/*
 * app_serial.c
 *
 *  Created on: 16.11.2017
 *      Author: AzizS
 */

#include "../system/driver/serial/serial.h"
#include "../system/system/system.h"


void app_serialWrite(uint32_t writeValue){

    serial_init(UART0);

    while(1){

        uart_write(UART0, writeValue);
        system_sleep(250);
    }


}

