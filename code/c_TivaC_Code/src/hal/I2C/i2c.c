/*
 * i2c.c
 *
 *  Created on: 27.11.2017
 *      Author: AzizS
 */

#include "i2c.h"
#define WAIT_UNTIL_READY(i2cModule)         while(*((volatile uint32_t *)(&I2C0_MCS_R + (i2cModule - I2C0) * 0x1000)) & 1);
                                         //parameter sind typlos

void i2c_init(Peripheral_t i2cModule){
    *((volatile uint32_t*)((uint8_t*)(&I2C0_MCR_R + ((i2cModule - I2C0) * 0x1000)))) |= (1 << 4);
}


void i2c_read(Peripheral_t i2cModule, uint8_t slaveAdr, uint8_t reg, uint8_t* pOut){

    *((volatile uint32_t*)((uint8_t*)(&I2C0_MSA_R + ((i2cModule - I2C0) * 0x1000)))) |= ((slaveAdr << 1) | 1);
    *((volatile uint32_t*)((uint8_t*)(&I2C0_MDR_R + ((i2cModule - I2C0) * 0x1000)))) |= ((reg) << 1);
    *((volatile uint32_t*)((uint8_t*)(&I2C0_MCS_R + ((i2cModule - I2C0) * 0x1000)))) |= (I2C_MCS_RUN | I2C_MCS_START);
    WAIT_UNTIL_READY(i2cModule);
    *((volatile uint32_t*)((uint8_t*)(&I2C0_MSA_R + ((i2cModule - I2C0) * 0x1000)))) |= (1 << 0);
    *((volatile uint32_t*)((uint8_t*)(&I2C0_MSA_R + ((i2cModule - I2C0) * 0x1000)))) |= ((slaveAdr << 1));
    *((volatile uint32_t*)((uint8_t*)(&I2C0_MCS_R + ((i2cModule - I2C0) * 0x1000)))) |= (I2C_MCS_RUN | I2C_MCS_STOP | I2C_MCS_RUN);
    WAIT_UNTIL_READY(i2cModule);
    *pOut = I2C0_MDR_R;
}


void i2c_write(Peripheral_t i2cModule, uint8_t slaveAdr, uint8_t reg, uint8_t input){

    *((volatile uint32_t*)((uint8_t*)(&I2C0_MSA_R + ((i2cModule - I2C0) * 0x1000)))) |= (slaveAdr << 4);     //bei read: (((slaveAdr) << 1) | 1)
    *((volatile uint32_t*)((uint8_t*)(&I2C0_MDR_R + ((i2cModule - I2C0) * 0x1000)))) |= ((reg) << 1);
    *((volatile uint32_t*)((uint8_t*)(&I2C0_MCS_R + ((i2cModule - I2C0) * 0x1000)))) |= (I2C_MCS_RUN | I2C_MCS_START);
    WAIT_UNTIL_READY(i2cModule);
    *((volatile uint32_t*)((uint8_t*)(&I2C0_MDR_R + ((i2cModule - I2C0) * 0x1000)))) = input;
    *((volatile uint32_t*)((uint8_t*)(&I2C0_MCS_R + ((i2cModule - I2C0) * 0x1000)))) |= (I2C_MCS_RUN | I2C_MCS_STOP);
    WAIT_UNTIL_READY(i2cModule);

}

//I2C
/*gpio_enableOpenDrain
PortD machen
setMux(portd,0,3)

setMux(portd,1,3)
*/
