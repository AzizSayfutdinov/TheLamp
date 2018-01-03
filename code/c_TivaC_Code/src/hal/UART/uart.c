/*
 * uart.c
 *
 *  Created on: 13.11.2017
 *      Author: AzizS
 */

#include "../../hal/UART/uart.h"
#include "../board/board.h"

void uart_config(Peripheral_t p, uint32_t baudrate, Parity_t parity){

    float brd = 0.0;

    switch(p){

    case UART0:
        UART0_CTL_R &= ~(1 << 0);   //waiting until bit is really deleted is favorable

        while(UART0_CTL_R & (1 << 0)){  //we wait until really deleted
        }


        //BAUDRATE
        brd = 0.0;
        brd = ((float)(CPU_SPEED))/(16.0 * BAUDRATE_9600);     //clock of the PCU: 16MHz       ((float)(CPU_SPEED))/(16.0 * 115200)
        UART0_IBRD_R = (int) (brd);
        UART0_FBRD_R = (int) (((brd - ((int)(brd))) * 64) + 0.5);
        UART0_LCRH_R = (1 << 5) | (1 << 6);        //the same as: (1<<5) | (1<<6), setting bit 5 and 6
        //technique: das erste setzen bei NONE(0|0)
        //parity, es sind nur 2,3 bit wichtig


        //PARITY, not mentioned in the script!
        UART0_LCRH_R &= ~0b110;
        if(parity != NONE){
            UART0_LCRH_R = 0b10;        //das bit, das ODD(1|1) und EVEN(0|1) gemeinsam haben
        }
        if(parity == ODD){
            UART0_LCRH_R = 0b100;
        }

        UART0_LCRH_R |= (1 << 4);
        UART0_CTL_R |= (1 << 0);
        break;

    case UART1:
        UART1_CTL_R &= ~(1 << 0);
        while(UART1_CTL_R & (1 << 0)){
        }


        //BAUDRATE
        brd = ((float)(CPU_SPEED))/(16.0 * BAUDRATE_9600);
        UART1_IBRD_R = (int) (brd);
        UART1_FBRD_R = (int) (((brd - ((int)(brd))) * 64) + 0.5);
        UART1_LCRH_R = (1 << 5) | (1 << 6);

        //PARITY, not mentioned in the script!
        UART1_LCRH_R &= ~0b110;
        if(parity != NONE){
            UART1_LCRH_R = 0b10;
        }
        if(parity == ODD){
            UART1_LCRH_R = 0b100;
        }

        UART1_LCRH_R |= (1 << 4);
        UART1_CTL_R |= (1 << 0);
        break;
    }



}


bool uart_isRXFifoEmpty(Peripheral_t p){            //switch case is missing: switch(p)

    bool returnValue = false;
    switch(p){
    case UART0:
        if(UART0_FR_R & (1 << 4)){
            returnValue = true;
        }
        break;
        //returnValue = ((UART0_FR_R & (1 << 4)) ?  true: false);
    case UART1:
        if(UART1_FR_R & (1 << 4)){
            returnValue = true;
        }
        break;
        //return ((UART0_FR_R & (1 << 4)) ?  true: false);
    }
    return returnValue;
}

bool uart_isTXFifoEmpty(Peripheral_t p){

    bool returnValue = true;
    switch(p){
    case UART0:
        if(UART0_FR_R & (1 << 5)){
            returnValue = false;
        }
        break;
        //returnValue = ((UART0_FR_R & (1 << 5)) ? false: true);

    case UART1:
        if(UART1_FR_R & (1 << 5)){
            returnValue = false;
        }
        break;
        //returnValue = ((UART1_FR_R & (1 << 5)) ? false: true);
    }
    return returnValue;
    //switch(p){
      //  case UART1:
            //return ((UART0_FR_R & (1 << 5)) ? false: true);
    //}
}

bool uart_isTXFifoFull(Peripheral_t p){

    bool returnValue = true;
    switch(p){
    case UART0:
        returnValue = (!(uart_isTXFifoEmpty(p)));
        break;
    case UART1:
        returnValue = (!(uart_isTXFifoEmpty(p)));
        break;
    }
    return returnValue;

    //switch(p){
    //case UART1:
        //return !(uart_isTXFifoEmpty(p));

    //}
}


void uart_pread(Peripheral_t p, uint32_t* pOutValue){

    switch(p){
    case UART0:
        *pOutValue = UART0_DR_R;    //durch* wird auf den Wert derefernziert, sonst wäre es die Adresse original: UART0_DR_R = *pOutValue
        break;
    case UART1:
        *pOutValue = UART1_DR_R;    //durch* wird auf den Wert derefernziert, sonst wäre es die Adresse original: UART0_DR_R = *pOutValue
        break;

    default:
        break;
    }

}


char uart_read(Peripheral_t p){

    char Value = 0;                 //Stack
    switch(p){
    case UART0:
        Value = UART0_DR_R;    //durch* wird auf den Wert derefernziert, sonst wäre es die Adresse original: UART0_DR_R = *pOutValue,  FIFO: after writing Register, the value is gone
        break;
    case UART1:
        Value = UART1_DR_R;
        break;
    default:
        break;
    }
    return Value;
}



void uart_write(Peripheral_t p, uint32_t value) { //DR_R schreiben: in das Daten Register schreiben                         //POSSIBLE ERROR: PARANTHESIS

    switch(p){
    case UART0:
        if(uart_isTXFifoFull(UART0)){
        }
        else{
            UART0_DR_R = value;
        }
            break;
    case UART1:
        if(uart_isTXFifoFull(UART1)){
        }
        else{
            UART1_DR_R = value;
        }
            break;
    }

}


void uart_writeChar(Peripheral_t p, char value) { //DR_R schreiben: in das Daten Register schreiben

    switch(p){
    case UART0:
        if(!(uart_isTXFifoFull(UART0))){
            UART0_DR_R = value;
        }
        break;
    case UART1:
        if(!(uart_isTXFifoFull(UART1))){
            UART1_DR_R = value;
        }
        break;
    }

}




//TODO: Im driver kommt ein serial rein

/*serial_init(): uart aufrufen mit enable periaral zuerstsetMode, dan setPinMux und so

        app_connsole machen: serial init(), für serail read einen array machen mit ateas platz: nachh serailRead am ende serial Write
        strncmp (say, command, 4) == 0

        farbe: steuerzeicehen: <ße["0;30m"] bei wikipedia suchen;

        oder snake machen statt der Husi
        Schwanz merken, auf den kopf navigieren: komplizierter, je mehr kurven man macht*/



