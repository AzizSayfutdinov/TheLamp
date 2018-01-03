/*
 * app_comsole.c
 *
 *  Created on: 23.11.2017
 *      Author: AzizS
 */

#include "apps.h"
#include "../system/driver/serial/serial.h"
#include <inttypes.h>
#include "../hal/UART/uart.h"
#include "src/system/system/system.h"
#include "src/system/driver/led/led.h"
#include "src/hal/board/board.h"
#include <string.h>

char buffer[200] = { 0 };
char hello[20] = "HELLO!";
uint32_t i = 0;

void app_console(){

    serial_init(UART1);
    serial_writeText("Welcome to TIVAC!\n\r");
    serial_writeText("Now try to type in something ... I hope it'll work ...");

    while(1){

        serial_pReadChar(&buffer[i]);
        serial_writeChar(buffer[i]);
        system_sleep(5);
        i++;

        if (buffer[i - 1] == '\r') {

           i = 0;
           serial_writeText("\r\n");
           if ((strncmp(buffer, "say hello", 9)) == 0) {
               serial_writeText(hello);
               serial_writeText("\r\n");
               //i = 0;
           }
           if ((strncmp(buffer, "red led on", 10)) == 0) {
               serial_writeText("\r\n");
               led_init(RED_LED);
               led_setState(GREEN_LED, 0);
               led_setState(BLUE_LED, 0);
               led_setState(RED_LED, 1);
               serial_writeText("RED_LED is active\r\n");
               //i = 0;
           }
           if ((strncmp(buffer, "red led off", 11)) == 0) {
               serial_writeText("\r\n");
               led_init(RED_LED);
               led_setState(GREEN_LED, 0);
               led_setState(BLUE_LED, 0);
               led_setState(RED_LED, 0);
               serial_writeText("RED_LED is off\r\n");
               //i = 0;
           }
       }

    }

}
