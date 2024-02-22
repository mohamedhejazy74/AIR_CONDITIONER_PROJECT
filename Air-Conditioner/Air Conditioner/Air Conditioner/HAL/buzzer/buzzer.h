/*
 * buzzer.h
 *
 * Created: 4/20/2023 5:49:45 AM
 *  Author: Mahmoud Sarhan
 *	EMAIL : Eng.mahmoud.adel94@gmail.com
 */ 


#ifndef BUZZER_H_
#define BUZZER_H_

#include "../../MCAL/dio/dio_types.h"

typedef struct
{
	uint8_t u8_pin;
	uint8_t u8_port;
}st_buzzerConfigType;


typedef uint8_t  u8_en_buzzerErrorsType;
#define	BUZZER_E_OK						((u8_en_buzzerErrorsType)0x00)
#define BUZZER_E_NOT_OK					((u8_en_buzzerErrorsType)0x06)



u8_en_buzzerErrorsType BUZZER_init (st_buzzerConfigType* st_config);
u8_en_buzzerErrorsType BUZZER_start(void);
u8_en_buzzerErrorsType BUZZER_stop(void);
#endif /* BUZZER_H_ */