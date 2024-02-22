/*
 * adc.c
 *
 * Created: 4/21/2023 12:27:22 AM
 *  Author:  ARAFA ARAFA
 *	EMAIL : arafa.arafa.prog@gmail.com
 */ 



#include "adc.h"

double Quantisation_step;
u8_en_adcErrorsType ADC_init (st_adcConfigType* st_config)
{
	u8_en_adcErrorsType ret = ADC_E_OK;
	if(st_config == NULL){
		ret = ADC_E_NOT_OK;
	}else{
		
		ADCSRA_ADD =	(1<<ADC_ENABLE)|(st_config->u8_prescaler_selection);
		ADMUX_ADD =	 (st_config->u8_ref_selection<<ADC_VREF_SELECT);
		uint16_t result = 2;
		for(int i=1; i<ADC_BIT_RESOLUTION;i++){
			result *= 2;
			
		}
		Quantisation_step= ((double)ADC_EXTERNAL_VREF_VOLT)/(result);
		
	}
	return ret;
	
}
u8_en_adcErrorsType ADC_read (u8_en_adcChannelId u8_channelID, uint16_t * u16_data)
{
	u8_en_adcErrorsType ret = ADC_E_OK;
	if(u8_channelID < ADC_CHANNEL_0 || u8_channelID > ADC_CHANNEL_7 || u16_data == NULL){
		ret =	ADC_E_NOT_OK;
	}
	else{
		if(((DDRA & (1U<<u8_channelID))>>u8_channelID) != 0)
		{
			DIO_init (porta, u8_channelID, STD_INPUT);
		}
		
		while(READ_BIT(ADCSRA_ADD, ADC_START_CONVERSION) == 1);
		
		ADMUX_ADD  = (0xf8 & ADMUX_ADD) | u8_channelID;
		SET_BIT(ADCSRA_ADD, ADC_START_CONVERSION);
		_delay_ms(10);
		while(READ_BIT(ADCSRA_ADD, ADC_INT_FLAG) == 0);
		uint16_t	adc_data_temp=0;	
		adc_data_temp = ADCL_ADD;
		adc_data_temp |=(ADCH_ADD<<8);
		*u16_data  = adc_data_temp;
	}
	
	return ret;
}