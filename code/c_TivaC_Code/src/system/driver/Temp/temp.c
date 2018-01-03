/*
 * temp.c
 *
 *  Created on: 06.11.2017
 *      Author: AzizS
 */
#include "../../../hal/hal.h"
#include "../../../hal/gpio/ADC/ADC.h"


void temp_init(void){

    hal_enablePeripheral(ADC0); //initialize
    adc_configureSampleSequence(ADC0, INTERNAL_TEMP_SENSOR, OVERSAMPLING64);



}

float temp_read(void){

    adc_activate(ADC0);

    float vRef = 3.3;
    float temp = 2.0;


    //float currentVoltage = ADC0_ACTSS_R;                                //float currentTemp = 147.5 - ((75*(3.3)*currentVoltage)/4095);

    //while(/*ADC0_ACTSS_R*/1){

        float adcValue = ADC0_SSFIFO0_R;
        temp = 147.5f - ((75.0f* vRef * adcValue)/4095);
        return temp;


}

// HÜ: Register auslesen unf in Temperatur umwandeln, wie in Folien und mit Oversampling herumspielen ...
//
