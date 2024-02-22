/*
 * buzzer.c
 *
 * Created: 4/20/2023 5:49:45 AM
 *  Author: Mahmoud Sarhan
 *	EMAIL : Eng.mahmoud.adel94@gmail.com
 */ 
 #include "buzzer.h"
#include "../../MCAL/dio/dio.h"



#define INIT		0x01
#define NOT_INIT	0x00


static st_buzzerConfigType st_gs_buzzerConfig;
static uint8_t u8_gs_buzzerState = NOT_INIT;



u8_en_buzzerErrorsType BUZZER_init (st_buzzerConfigType* st_config)
{
	// Check if the pounter is invalid
	if (st_config == ((void*)0))
		return BUZZER_E_NOT_OK;
	
	// Set Buzzer pin as output
	u8_en_dioErrors u8_dioRetVal = DIO_init(st_config->u8_port, st_config->u8_pin, STD_OUTPUT);
	
	// Check if there is an error from dio driver
	if(u8_dioRetVal)
		return u8_dioRetVal;
	
	// Store configuration locally
	st_gs_buzzerConfig.u8_port = st_config->u8_port;
	st_gs_buzzerConfig.u8_pin = st_config->u8_pin;
	
	// Change buzzer state
	u8_gs_buzzerState = INIT;
	
	return BUZZER_E_OK;
}
u8_en_buzzerErrorsType BUZZER_start(void)
{
	// Check if the module is not init before
	if(u8_gs_buzzerState == NOT_INIT)
		return BUZZER_E_NOT_OK;
	
	// Turn the buzzer on
	DIO_writePIN(st_gs_buzzerConfig.u8_port,st_gs_buzzerConfig.u8_pin, STD_HIGH);
	
	return BUZZER_E_OK;
}
u8_en_buzzerErrorsType BUZZER_stop(void)
{
	// Check if the module is not init before
	if(u8_gs_buzzerState == NOT_INIT)
		return BUZZER_E_NOT_OK;
	
	// Turn the buzzer off
	DIO_writePIN(st_gs_buzzerConfig.u8_port,st_gs_buzzerConfig.u8_pin, STD_LOW);
	
	return BUZZER_E_OK;
}