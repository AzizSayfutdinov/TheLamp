/*
 * serial.c
 *
 *  Created on: 14.11.2017
 *      Author: AzizS
 */
#include "serial.h"
#include "../../../hal/UART/uart.h"
#include "../../../hal/hal.h"
#include "src/system/system/system.h"

void serial_init(Peripheral_t p){                                                   //es müssen nicht alle parameter übergeben werden. Nur die, die in der funkton verwendet werden, aber niht die parameter, die
                                                                                    //innerhalb der funktion von anderen funktionen verwendet werden. HIER: nur für switch(p)!
    switch(p){

    case UART0:

        hal_enablePeripheral(UART0);                //Enable UART0          kann hier der parameter p als parameter eingegeben werden oder muss es explizit angegeben werden? als parameter oder als wert?
        hal_enablePeripheral(PORTA);                //Enable PORTA
        gpio_setMode(PORTA, PIN_A0, OUTPUT_MODE_MULTIPLEXED);
        gpio_setMode(PORTA, PIN_A1, OUTPUT_MODE_MULTIPLEXED);
        gpio_setMux(PORTA, PIN_A0, UART_MODE);
        gpio_setMux(PORTA, PIN_A1, UART_MODE);
        uart_config(UART0, BAUDRATE_9600, NONE);
        break;

    case UART1:

       hal_enablePeripheral(UART1);                //Enable UART1
       hal_enablePeripheral(PORTB);                //Enable PORTB
       gpio_setMode(PORTB, PIN_B0, OUTPUT_MODE_MULTIPLEXED);
       gpio_setMode(PORTB, PIN_B1, OUTPUT_MODE_MULTIPLEXED);
       gpio_setMux(PORTB, PIN_B0, UART_MODE);
       gpio_setMux(PORTB, PIN_B1, UART_MODE);
       uart_config(UART1, BAUDRATE_9600, NONE);
       break;

    }

}




//UART0
void serial_write(uint32_t value){

    if(!uart_isTXFifoFull(UART1)){

        uart_write(UART1, value);               //TODO: Check if register empty/full
    }

}

void serial_writeChar(char value){
    if((uart_isTXFifoFull(UART1))){
        return;
    }

    else{
        uart_write(UART1, value);
    }
}

void serial_writeText(char* text){

    if(!(uart_isTXFifoFull(UART1))){

        uart_writeChar(UART1, '\n');
        uart_writeChar(UART1, '\r');

        for(int i = 0; text[i] != '\0'; i++){
            uart_writeChar(UART1, text[i]);
            system_sleep(5);
        }
        uart_writeChar(UART1, '\n');
        uart_writeChar(UART1, '\r');
    }

}

void serial_read(uint32_t *pOutValue){

    while((UART1_FR_R & (1 << 4) != 0)){
    }
    uart_pread(UART1, pOutValue);



}

char serial_readChar(void){

    while((UART1_FR_R & (1 << 4) != 0)){
    }
    char text = uart_read(UART1);

    return text;


}

void serial_pReadChar(char* text){

    while(((UART1_FR_R & (1 << 4)) != 0)){
    }

    //if(!(uart_isRXFifoEmpty(UART0))){
        *text = uart_read(UART1);
    //}

}








