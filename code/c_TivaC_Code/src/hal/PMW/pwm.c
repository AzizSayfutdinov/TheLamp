/*
 * pwm.c
 *
 *  Created on: 20.11.2017
 *      Author: AzizS
 */

#include "pwm.h"
#include <stdbool.h>



void pwm_config(Peripheral_t pwm, uint8_t generator, uint32_t frequency){

    //SYSCTL_RCC_R &= ~(1<<17);
    //SYSCTL_RCC_R &= ~(1<<18);
    //SYSCTL_RCC_R &= ~(1<<19);
    SYSCTL_RCC_R |= (1<<17);
    SYSCTL_RCC_R |= (1<<18);
    SYSCTL_RCC_R |= (1<<19);
    SYSCTL_RCC_R |= (1<<20);

    uint16_t clocktickets = 0;
    clocktickets = (CPU_SPEED/(frequency*64));

    if (pwm == PWM0){
        switch(generator){
        case 0:
            PWM0_0_GENA_R |= (1<<0);
            PWM0_0_GENB_R |= (1<<0);
            PWM0_0_GENA_R |= (1<<1);
            PWM0_0_GENB_R |= (1<<1);
            PWM0_0_GENA_R |= (1<<7);
            PWM0_0_GENB_R |= (1<<11);
            PWM0_0_LOAD_R = (clocktickets-1);
            PWM0_0_CTL_R |= (1<<0);
            PWM0_0_CTL_R |= (1<<2);
            break;

        case 1:
            PWM0_1_GENA_R |= (1<<0);
            PWM0_1_GENB_R |= (1<<0);
            PWM0_1_GENA_R |= (1<<1);
            PWM0_1_GENB_R |= (1<<1);
            PWM0_1_GENA_R |= (1<<7);
            PWM0_1_GENB_R |= (1<<11);
            PWM0_1_LOAD_R = (clocktickets-1);
            PWM0_1_CTL_R |= (1<<0);
            PWM0_1_CTL_R |= (1<<2);
            break;

        case 2:
            PWM0_2_GENA_R |= (1<<0);
            PWM0_2_GENB_R |= (1<<0);
            PWM0_2_GENA_R |= (1<<1);
            PWM0_2_GENB_R |= (1<<1);
            PWM0_2_GENA_R |= (1<<7);
            PWM0_2_GENB_R |= (1<<11);
            PWM0_2_LOAD_R = (clocktickets-1);
            PWM0_2_CTL_R |= (1<<0);
            PWM0_2_CTL_R |= (1<<2);
            break;

        case 3:
            PWM0_3_GENA_R |= (1<<0);
            PWM0_3_GENB_R |= (1<<0);
            PWM0_3_GENA_R |= (1<<1);
            PWM0_3_GENB_R |= (1<<1);
            PWM0_3_GENA_R |= (1<<7);
            PWM0_3_GENB_R |= (1<<11);
            PWM0_3_LOAD_R = (clocktickets-1);
            PWM0_3_CTL_R |= (1<<0);
            PWM0_3_CTL_R |= (1<<2);
            break;
        }
    }
    if (pwm == PWM1){
            switch(generator){
            case 0:
                PWM1_0_GENA_R |= (1<<0);
                PWM1_0_GENB_R |= (1<<0);
                PWM1_0_GENA_R |= (1<<1);
                PWM1_0_GENB_R |= (1<<1);
                PWM1_0_GENA_R |= (1<<7);
                PWM1_0_GENB_R |= (1<<11);
                PWM1_0_LOAD_R = (clocktickets-1);
                PWM1_0_CTL_R |= (1<<0);
                PWM1_0_CTL_R |= (1<<2);
                break;

            case 1:
                PWM1_1_GENA_R |= (1<<0);
                PWM1_1_GENB_R |= (1<<0);
                PWM1_1_GENA_R |= (1<<1);
                PWM1_1_GENB_R |= (1<<1);
                PWM1_1_GENA_R |= (1<<7);
                PWM1_1_GENB_R |= (1<<11);
                PWM1_1_LOAD_R = (clocktickets-1);
                PWM1_1_CTL_R |= (1<<0);
                PWM1_1_CTL_R |= (1<<2);
                break;

            case 2:
                PWM1_2_GENA_R |= (1<<0);
                PWM1_2_GENB_R |= (1<<0);
                PWM1_2_GENA_R |= (1<<1);
                PWM1_2_GENB_R |= (1<<1);
                PWM1_2_GENA_R |= (1<<7);
                PWM1_2_GENB_R |= (1<<11);
                PWM1_2_LOAD_R |= (clocktickets-1);
                PWM1_2_CTL_R |= (1<<0);
                PWM1_2_CTL_R |= (1<<2);
                break;

            case 3:
                PWM1_3_GENA_R |= (1<<0);
                PWM1_3_GENB_R |= (1<<0);
                PWM1_3_GENA_R |= (1<<1);
                PWM1_3_GENB_R |= (1<<1);
                PWM1_3_GENA_R |= (1<<7);
                PWM1_3_GENB_R |= (1<<11);
                PWM1_3_LOAD_R = (clocktickets-1);
                PWM1_3_CTL_R |= (1<<0);
                PWM1_3_CTL_R |= (1<<2);
                break;
            }
        }

}

void pwm_setDuty(Peripheral_t pwm, uint8_t generator, uint8_t outputnumber, uint8_t percent){
    uint16_t var =0;
    uint16_t compare = 0;
    if (pwm == PWM0){
        switch(generator){
        case 0:
            compare = ((int)PWM0_0_LOAD_R /100 * (100-percent));
            if(outputnumber == 0){
                PWM0_0_CMPA_R = compare;
            }
            if(outputnumber == 1){
                PWM0_0_CMPB_R = compare;
            }
            break;
        case 1:
            compare = ((int)PWM0_1_LOAD_R /100 * (100-percent));
            if(outputnumber == 0){
                 PWM0_1_CMPA_R = compare;
            }
            if(outputnumber == 1){
                 PWM0_1_CMPB_R = compare;
            }
            break;
        case 2:
            compare = ((int)PWM0_2_LOAD_R /100 * (100-percent));
            if(outputnumber == 0){
                  PWM0_2_CMPA_R = compare;
            }
            if(outputnumber == 1){
                  PWM0_2_CMPB_R = compare;
            }
            break;
        case 3:
            compare = ((int)PWM0_3_LOAD_R /100 * (100-percent));
            if(outputnumber == 0){
                   PWM0_3_CMPA_R = compare;
            }
            if(outputnumber == 1){
                PWM0_3_CMPB_R = compare;
            }
            break;
        }
    }
    if (pwm == PWM1){
            switch(generator){
            case 0:
                compare = ((int)PWM1_0_LOAD_R /100 * (100-percent));
                if(outputnumber == 0){
                    PWM1_0_CMPA_R = compare;
                }
                if(outputnumber == 1){
                    PWM1_0_CMPB_R = compare;
                }
                break;
            case 1:
                compare = ((int)PWM1_1_LOAD_R /100 * (100-percent));
                if(outputnumber == 0){
                     PWM1_1_CMPA_R = compare;
                }
                if(outputnumber == 1){
                     PWM1_1_CMPB_R = compare;
                }
                break;
            case 2:
                var = (int)PWM1_2_LOAD_R + 1;
                compare = (var - ((percent * var) / 100 ));
                if(outputnumber == 0){
                      PWM1_2_CMPA_R = compare;
                }
                if(outputnumber == 1){
                      PWM1_2_CMPB_R = compare;
                }
                break;
            case 3:
                compare = ((int)PWM1_3_LOAD_R /100 * (100-percent));
                if(outputnumber == 0){
                       PWM1_3_CMPA_R = compare;
                }
                if(outputnumber == 1){
                    PWM1_3_CMPB_R = compare;
                }
                break;
            }
        }

}


void pwm_setEnable(Peripheral_t pwm, uint8_t generator, bool enable){

    if (enable == true){
        if(pwm == PWM0){
            switch(generator){
            case 0:
                PWM0_ENABLE_R |= (1<<0);
                PWM0_ENABLE_R |= (1<<1);
                break;
            case 1:
                PWM0_ENABLE_R |= (1<<2);
                PWM0_ENABLE_R |= (1<<3);
                break;
            case 2:
                PWM0_ENABLE_R |= (1<<4);
                PWM0_ENABLE_R |= (1<<5);
                break;
            case 3:
                PWM0_ENABLE_R |= (1<<6);
                PWM0_ENABLE_R |= (1<<7);
                break;
            }
        }
        if(pwm == PWM1){
            switch(generator){
            case 0:
                PWM1_ENABLE_R |= (1<<0);
                PWM1_ENABLE_R |= (1<<1);
                break;
            case 1:
                PWM1_ENABLE_R |= (1<<2);
                PWM1_ENABLE_R |= (1<<3);
                break;
            case 2:
                PWM1_ENABLE_R |= (1<<4);
                PWM1_ENABLE_R |= (1<<5);
                break;
            case 3:
                PWM1_ENABLE_R |= (1<<6);
                PWM1_ENABLE_R |= (1<<7);
                break;
            }
        }
    }
    else{
        PWM1_ENABLE_R &= ~(1<<4);
        PWM1_ENABLE_R &= ~(1<<5);
    }
}

//Lerchs version
//void pwm_setDuty(Peripheral_t pwm, uint8_t generator/*,uint8_t output*/, uint8_t dutycycle){

/*    uint8_t generatorNumber = generator / 2;
       uint8_t outputNumber = generator % 2;

       uint32_t loadValue = *((volatile uint32_t*) (((uint8_t*)&PWM0_0_LOAD_R) + (pwm - PWM0) * 0x1000
               + 0x40 * generatorNumber));
       uint32_t compareValue = (loadValue * (100 - dutycycle)) / 100-1;

       *((volatile uint32_t*) (((uint8_t*)&PWM0_0_CMPA_R) + (pwm - PWM0) * 0x1000
                   + 0x40 * generatorNumber + 0x4 * outputNumber)) = compareValue;
}*/

//Lerchs version
/*void pwm_config(Peripheral_t pwm, uint8_t generator, uint32_t frequency){

    //set bit 17,18,19,20
    pwm_setDuty(pwm, generator, 0, 50);

        SYSCTL_RCC_R &= ~(0b111 << 17);
        uint8_t devider = 2;
        if (frequency < 500)
        {
            SYSCTL_RCC_R = (0b111 << 17);
            devider = 64;
        }

        uint8_t generatorNumber = generator / 2;
        uint8_t outputNumber = generator % 2;

        *((volatile uint32_t*) (((uint8_t*) &PWM0_0_GENA_R)
                + (pwm - PWM0) * 0x1000 + 0x40 * generatorNumber
                + 0x4 * outputNumber)) |= (0b11 << 0)
                | (1 << (outputNumber == 0 ? 7 : 11));  //set bit 7 if output a or bit 11 if output b

        uint32_t loadValue = (16e6 / devider) / (frequency);

        *((volatile uint32_t*) (((uint8_t*)&PWM0_0_LOAD_R) + (pwm - PWM0) * 0x1000
                + 0x40 * generatorNumber)) = loadValue;

}*/

/*void pwm_setEnable(Peripheral_t pwm, uint8_t generator, bool enable){

    uint8_t generatorNumber = generator / 2;

        if (enable)
        {
            *((volatile uint32_t*) (((uint8_t*)&PWM0_0_CTL_R) + (pwm - PWM0) * 0x1000
                    + 0x40 * generatorNumber)) |= (1 << 0) | (1 << 2);

            *((volatile uint32_t*) (((uint8_t*)&PWM0_ENABLE_R) + (pwm - PWM0) * 0x1000)) |= (1<<generator);

            *((volatile uint32_t*) (((uint8_t*)&PWM0_0_CTL_R) + (pwm - PWM0) * 0x1000)) |= (1<<generatorNumber);
        }
        else
        {
            *((volatile uint32_t*) (((uint8_t*)&PWM0_0_CTL_R) + (pwm - PWM0) * 0x1000
                    + 0x40 * generatorNumber)) &= ~((1 << 0) | (1 << 2));

            *((volatile uint32_t*) (((uint8_t*)&PWM0_0_CTL_R) + (pwm - PWM0) * 0x1000)) &= ~(1<<generatorNumber);
        }

}*/
