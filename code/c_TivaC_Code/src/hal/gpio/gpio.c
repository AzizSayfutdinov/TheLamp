
#include "gpio.h"
#include <inttypes.h>
#include "../board/board.h"
//TODO board inlcude

#define MAX_PIN                 (16)

static InterruptFunction_t gPortFInterrupts[MAX_PIN] = { 0 };

static InterruptFunction_t gPortDInterrupts[MAX_PIN] = { 0 };


void gpio_setMode(Peripheral_t port, GpioPin_t pin, OutputMode_t mode) {
    if (mode == OUTPUT_MODE_DIGITAL_OUTPUT_FULL_STRENGTH) {
        switch (port) {
        case PORTF:
            // Set direction to output
            GPIO_PORTF_AHB_DIR_R |= (1 << pin);

            // Set driving strength of 8mA
            GPIO_PORTF_AHB_DR8R_R |= (1 << pin);

            // Set digital enable
            GPIO_PORTF_AHB_DEN_R |= (1 << pin);
            break;
        }
    }

    else if (mode == OUTPUT_MODE_INPUT_PULL_UP) {
        switch (port) {

        case PORTD:
            GPIO_PORTD_AHB_DEN_R |= (1 << pin);     //circuit in datasheet, pull up needed
            GPIO_PORTD_AHB_PUR_R |= (1 << pin);
            break;


        case PORTF:
            GPIO_PORTF_AHB_DEN_R |= (1 << pin);
            GPIO_PORTF_AHB_PUR_R |= (1 << pin);
            break;
        }
    }

    else if (mode == OUTPUT_MODE_MULTIPLEXED){
        switch(port){
            case PORTA: GPIO_PORTA_AHB_AFSEL_R |= (1 << pin);
                        GPIO_PORTA_AHB_DEN_R |= (1 << pin);
                        break;
            case PORTB: GPIO_PORTB_AHB_AFSEL_R |= (1 << pin);
                        GPIO_PORTB_AHB_DEN_R |= (1 << pin);
                        break;

            case PORTF: GPIO_PORTF_AHB_AFSEL_R |= (1 << pin);
                        GPIO_PORTF_AHB_DEN_R |= (1 << pin);
                        break;

            case PORTD: GPIO_PORTF_AHB_AFSEL_R |= (1 << pin);
                        GPIO_PORTF_AHB_DEN_R |= (1 << pin);
                        break;

            default:
                break;
        }

    }
}

void gpio_setData(Peripheral_t port, GpioPin_t pin, uint32_t value) {
    switch (port) {
    case PORTF:
        if (value == 1) {
            GPIO_PORTF_AHB_DATA_R |= (1 << pin);
        } else {
            GPIO_PORTF_AHB_DATA_R &= ~(1 << pin);
        }
        break;
    }
}

uint32_t gpio_getData(Peripheral_t p, GpioPin_t pin) {
    switch (p) {
    case PORTF:
        return ((GPIO_PORTF_AHB_DATA_R & (1 << pin)) != 0);
    }
    return 0;
}

void gpio_enableInterrupt(Peripheral_t port, GpioPin_t pin,
                          InterruptEdge_t edge, InterruptFunction_t func) {
    switch (port) {
    case PORTD:
        GPIO_PORTF_AHB_IM_R |= (1 << pin);
        NVIC_EN0_R |= (1 << 3);
        GPIO_PORTF_AHB_IBE_R &= ~(1 << pin);
        GPIO_PORTF_AHB_IEV_R &= ~(1 << pin);
        if (edge == INTERRUPT_EDGE_RISING) {
            GPIO_PORTD_AHB_IEV_R |= (1 << pin);
        } else if (edge == INTERRUPT_EDGE_BOTH) {
            GPIO_PORTD_AHB_IEV_R |= (1 << pin);
            GPIO_PORTD_AHB_IBE_R |= (1 << pin);
        }
        gPortDInterrupts[pin] = func;       //array of functionpointers, func from driver
        break;

    case PORTF:
        GPIO_PORTF_AHB_IM_R |= (1 << pin);  //
        NVIC_EN0_R |= (1 << 30);            //enable, in datasheet, for PORTD pin 3
        GPIO_PORTF_AHB_IBE_R &= ~(1 << pin);
        GPIO_PORTF_AHB_IEV_R &= ~(1 << pin);
        if (edge == INTERRUPT_EDGE_RISING) {
            GPIO_PORTF_AHB_IEV_R |= (1 << pin);
        } else if (edge == INTERRUPT_EDGE_BOTH) {
            GPIO_PORTF_AHB_IEV_R |= (1 << pin);
            GPIO_PORTF_AHB_IBE_R |= (1 << pin);
        }
        gPortFInterrupts[pin] = func;       //array of function pointers, func from driver
        break;
    }
}

void gpio_globalPortFInterrupt() {
    for (uint32_t i = 0; i < MAX_PIN; i++) {
        if ((GPIO_PORTF_AHB_RIS_R & (1 << i)) != 0) {
            // Call callback (Rückruf)
            if (gPortFInterrupts[i] != 0) {
                gPortFInterrupts[i]();
            }
            GPIO_PORTF_AHB_ICR_R |= (1 << i);   //CLEAR INTERRUPT, without there would be no stop
        }
    }
}


void gpio_globalPortDInterrupt() {
    for (uint32_t i = 0; i < MAX_PIN; i++) {
        if ((GPIO_PORTF_AHB_RIS_R & (1 << i)) != 0) { //raw interrupt state
            // Call callback (Rückruf)
            if (gPortDInterrupts[i] != 0) {
                gPortDInterrupts[i]();
            }
            GPIO_PORTD_AHB_ICR_R |= (1 << i);
        }
    }
}




void gpio_setMux(Peripheral_t port, GpioPin_t pin, Mux_t mux){

    switch(port){

    case PORTA:
        if(mux == UART_MODE){
            GPIO_PORTA_AHB_PCTL_R |= (1 << (pin*4));    //bei UART wird (1<<4*pin) bei CAn(siehe tabelle 10-2) ist (8<<4*pin)
        }
        break;

    case PORTB:
        if(mux == UART_MODE){
            GPIO_PORTB_AHB_PCTL_R |= (1 << (pin*4));
        }
        break;

    case PORTF:
        if(mux == PWM_MODE){
            GPIO_PORTF_AHB_PCTL_R |= (5 << (pin*4));
        }

    case PORTD:
        if(mux == I2C_MODE){
            GPIO_PORTD_AHB_PCTL_R |= (3 << (pin*4));
        }

    default:
        break;
    }

}

void gpio_enableOpenDrain(Peripheral_t port){

    switch(port){
    case PORTD: GPIO_PORTD_AHB_ODR_R |= (3 << 1);    //setting pin 1, according datasheet I2CSDA with open drain
    }


}



