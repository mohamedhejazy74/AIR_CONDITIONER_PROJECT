/*
 * app.h
 *
 * Created: 4/21/2023 12:27:22 AM
 *  Author: Mahmoud Sarhan
 *	EMAIL : Eng.mahmoud.adel94@gmail.com
 */ 


#ifndef APP_H_
#define APP_H_
#define F_CPU 8000000UL
#include <util/delay.h>
#include <stdlib.h>

#include "../HAL/buzzer/buzzer.h"
#include "../HAL/keypad/keypad.h"
#include "../HAL/lcd/lcd.h"
#include "../HAL/temp_sensor/temp_sensor.h"
#include "../HAL/timer_manager/timer_manager.h"
#include "../interrupt.h"
//#include <avr/interrupt.h>


#define APP_TIMER_1_INIT_VALUE		61448
#define APP_RESET_BTN				'5'
#define APP_ADJUST_BTN				'4'
#define APP_INCREMENT_BTN			'1'
#define APP_DECREMENT_BTN			'2'
#define APP_SET_BTN					'3'
#define APP_NO_BTN					78


#define APP_PORT					0
#define APP_PIN						1

typedef uint8_t u8_programStateType;

#define APP_WELCOME				((u8_programStateType)0x00)
#define APP_SET_TEMP			((u8_programStateType)0x01)
#define APP_WORKING				((u8_programStateType)0x02)

void APP_start(void);


#endif /* APP_H	*/