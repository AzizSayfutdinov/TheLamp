/*
 * ADC.h
 *
 *  Created on: 06.11.2017
 *      Author: AzizS
 */

#ifndef SRC_HAL_GPIO_ADC_ADC_H_
#define SRC_HAL_GPIO_ADC_ADC_H_

#include "../../hal.h"

typedef enum {

    INTERNAL_TEMP_SENSOR,


}ADCInput_t;

typedef enum {

    OVERSAMPLING_NONE,
    OVERSAMPLING2,
    OVERSAMPLING4,
    OVERSAMPLING8,
    OVERSAMPLING16,
    OVERSAMPLING32,
    OVERSAMPLING64
}ADCOversampling_t;

void adc_configureSampleSequence(Peripheral_t p, ADCInput_t input, ADCOversampling_t o );      //Wie konfigurieren:

void adc_activate(Peripheral_t adc);


#endif /* SRC_HAL_GPIO_ADC_ADC_H_ */
