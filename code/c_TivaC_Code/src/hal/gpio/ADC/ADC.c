/*
 * ADC.c
 *
 *  Created on: 06.11.2017
 *      Author: AzizS
 */

#include "ADC.h"
#include "../../../system/system/system.h"
static int gADC0SSIndex = 0;

void adc_configureSampleSequence(Peripheral_t p, ADCInput_t input, ADCOversampling_t o ){

    switch(p){
    case ADC0:
        ADC0_ACTSS_R &= ~(1 << 0); // 0 bit deleted: Deactivate Sample Sequencer
        ADC0_SAC_R = o;             //Oversampling setting


        if(input == INTERNAL_TEMP_SENSOR) {

            ADC0_SSCTL0_R |= (1<<(3+(4*gADC0SSIndex)));        //nicht das 3.bit, sondern das 3+gADC0SSIndex und so weiter has to be deleted
            ADC0_SSCTL0_R |= (1<<(1+(4*gADC0SSIndex)));
        }

        if(gADC0SSIndex >= 1){
            ADC0_SSCTL0_R &= ~(1<<(3+(4*(gADC0SSIndex-1))));
        }

        gADC0SSIndex++;
        //TODO: OVERSAMPLING

        ADC0_ACTSS_R |= (1 << 0);
        break;//Active Sample Sequencer

    }
}

void adc_activate(Peripheral_t adc){

    switch(adc){

    case ADC0: ADC0_PSSI_R = 0b0001;
               ADC0_ACTSS_R |= (1 << 16);
        break;

    }
    system_sleep(500);
}

