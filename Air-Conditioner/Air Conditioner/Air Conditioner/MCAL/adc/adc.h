/*
 * adc.h
 *
 * Created: 4/21/2023 12:27:22 AM
 *  Author:  ARAFA ARAFA
 *	EMAIL : arafa.arafa.prog@gmail.com
 */ 


#ifndef ADC_H_
#define ADC_H_

#define F_CPU 8000000UL

#include <util/delay.h>

#include "adc_types.h"
#include "adc_config.h"
#include "../../STD_Types.h"
#include "../dio/dio.h"
#include "../../bit_manipulation.h"


#ifndef ADC_BIT_RESOLUTION
#error ADC bit resolution size
#endif

#ifndef ADC_EXTERNAL_VREF_VOLT
#error ADC external vref
#endif




/*
*   -Description-
*-this function init the ADC
*
*   -Input parameters -
*-1-it holds ADC configuration  (st_adcConfigType* st_config)
*
*   -Return-
*   u8_en_adcErrorsType
*
*   -Return cases-
*-1- (ADC_E_NOK) if there is something wrong
*-2- (ADC_E_OK) otherwise
*/
u8_en_adcErrorsType ADC_init (st_adcConfigType* st_config);

/*
*   -Description-
*-this function read the ADC channel
*
*   -Input parameters -
*-1-it holds ADC channel ID  (u8_en_adcChannelId u8_channelID)
*
*   -Output parameters -
*-1-it holds the result of conversion multiplied by quantisation step value  (double *data)
*
*   -Return-
*   u8_en_adcErrorsType
*
*   -Return cases-
*-1- (ADC_E_NOK) if there is something wrong
*-2- (ADC_E_OK) otherwise
*/
u8_en_adcErrorsType ADC_read (u8_en_adcChannelId u8_channelID,uint16_t * u16_data);


#endif	/*	ADC_H_	*/