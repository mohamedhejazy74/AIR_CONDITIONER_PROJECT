/*
 * Air Conditioner.c
 *
 * Created: 4/18/2023 11:34:59 PM
 * Author : Mahmoud Sarhan
 *	EMAIL : Eng.mahmoud.adel94@gmail.com
 */ 
#define F_CPU 8000000UL
//#include <avr/interrupt.h>

#include "APP/app.h"
//#include "HAL/timer_manager/timer_manager.h"
/*
st_timerConfigType st_gs_timer0_0_config;
void APP_timer00OvfHandeler(void)
{
	//u8_delay++;
	PORTD = ~PORTD;
	//TCNT1 = 61449;
	TIMER_Manager_reset(&st_gs_timer0_0_config);
}
//ISR()
*/
int main(void)
{
	//DDRD = 0xff;
	//PORTD  = 0x00;
	//st_timerConfigType st_gs_timer0_0_config;
	APP_start();
	/*st_gs_timer0_0_config.u8_timerNum = TIMER_1;
	st_gs_timer0_0_config.u8_timer_ovf_int_enable = TIMER_INTERRUPT_FEATURE_ENABLE;
	st_gs_timer0_0_config.u16_timer_InitialValue = 61449;
	st_gs_timer0_0_config.callBackFunction =  APP_timer00OvfHandeler;
	st_gs_timer0_0_config.u8_timerClock = TIMER_F_CPU_1024;
	TIMER_Manager_init(&st_gs_timer0_0_config);
	TIMER_Manager_start(&st_gs_timer0_0_config);
	//TCNT1 = 0;
	//TIMER_Manager_reset(&st_gs_timer0_0_config);
	sei();
	while(1)
	{
		
	}*/
}

