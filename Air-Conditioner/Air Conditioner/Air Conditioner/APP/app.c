/*
 * app.c
 *
 * Created: 4/21/2023 12:27:22 AM
 *  Author: Mahmoud Sarhan
 *	EMAIL : Eng.mahmoud.adel94@gmail.com
 */ 

#include "app.h"
#include <avr/io.h>

static st_timerConfigType st_gs_timer_1_config;
static st_tempSensorConfigType st_gs_tempSensorConfig;
st_lcdConfigType st_gs_lcdConfig;
 st_keypadConfigType st_gs_keypadConfig;
static st_buzzerConfigType st_gs_buzzerConfig;
static u8_programStateType u8_en_gs_programState = APP_WELCOME;
static uint8_t u8_delay = 0;
const uint8_t u8_gc_defaultTemp = 20;
static float f32_gs_curTemp = 20.0;
static uint8_t u8_gs_programTemp = 0;


void APP_init(void);
void APP_welcome(void);
void APP_set(void);
void APP_working(void);
void APP_timer0OvfHandeler(void);
void APP_printString(float f32_temp);


void APP_start(void)
{
	//DDRD = 0xff;
	APP_init();
	sei();													// Enable global interrupt 
	TIMER_Manager_start(&st_gs_timer_1_config);
	
	while(1)
	{
		while(u8_en_gs_programState == APP_WELCOME)
		{
			APP_welcome();
		}
		while(u8_en_gs_programState == APP_SET_TEMP)
		{
			APP_set();
		}
		while(u8_en_gs_programState == APP_WORKING)
		{
			APP_working();
		}
	}
}


void APP_init(void)
{
	// Initialize timer 0 in Normal mode with OVF interrupt enabled and interrupt period every 0.5 ms
	st_gs_timer_1_config.u8_timerNum = TIMER_1;
	st_gs_timer_1_config.u8_timer_ovf_int_enable = TIMER_INTERRUPT_FEATURE_ENABLE;
	st_gs_timer_1_config.u16_timer_InitialValue = APP_TIMER_1_INIT_VALUE;
	st_gs_timer_1_config.callBackFunction =  APP_timer0OvfHandeler;
	st_gs_timer_1_config.u8_timerClock = TIMER_F_CPU_1024;
	TIMER_Manager_init(&st_gs_timer_1_config);
	
	
	// Initialize The Temp. sensor 
	st_gs_tempSensorConfig.u8_channel = ADC_CHANNEL_7;
	st_gs_tempSensorConfig.u8_ref_selection = ADC_AVCC;
	st_gs_tempSensorConfig.u8_prescaler_selection = ADC_PRESCALER_2;
	TEMP_SENSOR_init(&st_gs_tempSensorConfig);
	
	
	
	
	// Initialize the LCD
	st_gs_lcdConfig.u8_mode = LCD_4_BIT_MODE;
	
	st_gs_lcdConfig.u8_d4Pin[APP_PORT]	 = porta;
	st_gs_lcdConfig.u8_d4Pin[APP_PIN]	 = pin0;
	
	st_gs_lcdConfig.u8_d5Pin[APP_PORT]	 = porta;
	st_gs_lcdConfig.u8_d5Pin[APP_PIN]	 = pin1;
	
	st_gs_lcdConfig.u8_d6Pin[APP_PORT]	 = porta;
	st_gs_lcdConfig.u8_d6Pin[APP_PIN]	 = pin2;
	
	st_gs_lcdConfig.u8_d7Pin[APP_PORT]	 = porta;
	st_gs_lcdConfig.u8_d7Pin[APP_PIN]	 = pin3;
	
	st_gs_lcdConfig.u8_RSpin[APP_PORT]	 = porta;
	st_gs_lcdConfig.u8_RSpin[APP_PIN]	 = pin4;
	
	st_gs_lcdConfig.u8_RWpin[APP_PORT]	 = porta;
	st_gs_lcdConfig.u8_RWpin[APP_PIN]	 = pin5;
	
	st_gs_lcdConfig.u8_Epin[APP_PORT]	 = porta;
	st_gs_lcdConfig.u8_Epin[APP_PIN]	 = pin6;
	
	LCD_init(&st_gs_lcdConfig);
	
	
	
	
	
	// Initialize the keypad
	st_gs_keypadConfig.u8_col1Pin[APP_PORT]	 = portc;
	st_gs_keypadConfig.u8_col1Pin[APP_PIN]	 = pin3;
	
	st_gs_keypadConfig.u8_col2Pin[APP_PORT]	 = portc;
	st_gs_keypadConfig.u8_col2Pin[APP_PIN]	 = pin4;
	
	st_gs_keypadConfig.u8_col3Pin[APP_PORT]  = portc;
	st_gs_keypadConfig.u8_col3Pin[APP_PIN]	 = pin5;
	
	st_gs_keypadConfig.u8_col4Pin[APP_PORT]	 = portc;
	st_gs_keypadConfig.u8_col4Pin[APP_PIN]	 = pin6;
	
	st_gs_keypadConfig.u8_row1Pin[APP_PORT]	 = portc;
	st_gs_keypadConfig.u8_row1Pin[APP_PIN]	 = pin0 ;
	
	st_gs_keypadConfig.u8_row2Pin[APP_PORT]  = portc;
	st_gs_keypadConfig.u8_row2Pin[APP_PIN]	 = pin1 ;
	
	st_gs_keypadConfig.u8_row3Pin[APP_PORT]	 = portc;
	st_gs_keypadConfig.u8_row3Pin[APP_PIN]	 = pin2 ;
	
	KEYPAD_init(&st_gs_keypadConfig);
	
	
	// Initialize Buzzer
	st_gs_buzzerConfig.u8_port = portb;
	st_gs_buzzerConfig.u8_pin = pin0;
	BUZZER_init(&st_gs_buzzerConfig);
}


void APP_welcome(void)
{
	LCD_clear();
	LCD_setCursor(1,1);
	u8_delay = 0;
	LCD_writeString((uint8_t*)"Welcome");
	//u8_delay = 0 ;
	while(u8_delay <= 2);
	//_delay_ms(1000);
	LCD_clear();
	LCD_setCursor(1,1);
	LCD_writeString((uint8_t*)"default Temp is");
	LCD_setCursor(2,1);
	u8_delay = 0;
	LCD_writeString((uint8_t*)"20");
	//u8_delay = 0;
	while(u8_delay <= 2);
	//_delay_ms(1000);
	
	u8_gs_programTemp = u8_gc_defaultTemp;
	u8_en_gs_programState = APP_SET_TEMP;
}




void APP_set(void)
{
	uint8_t u8_loadingChar[] = "|";
	uint8_t u8_emptyChar[] = " ";
	uint8_t u8_keypadData = 0;
	char ch_arrs_curTempToString[2];
	//u8_delay = 0;
	LCD_clear();
	LCD_setCursor(1,1);
	u8_delay = 0;
	LCD_writeString((uint8_t*)"Set Initial Temp");
	while(u8_delay <= 1);
	//_delay_ms(500);
	LCD_clear();
	LCD_setCursor(1,1);
	LCD_writeString((uint8_t*)"Min=18");
	//LCD_setCursor(1,8);
	//LCD_writeString((uint8_t*)ch_arrs_curTempToString);
	LCD_setCursor(1,11);
	LCD_writeString((uint8_t*)"Max=35");
	for (uint8_t u8_index = 19 ; u8_index <= u8_gs_programTemp ;u8_index++)
	{
		LCD_setCursor(2,u8_index-18);
		LCD_writeString((uint8_t*)u8_loadingChar);
	}
	while(1)
	{
		itoa(u8_gs_programTemp,ch_arrs_curTempToString,10);
		LCD_setCursor(1,8);
		LCD_writeString((uint8_t*)ch_arrs_curTempToString);
		/*for (uint8_t u8_index = 1 ; u8_index <= 16 ;u8_index++)
		{
			LCD_setCursor(2,u8_index);
			LCD_writeString(" ");
		}*/
		
		KEYPAD_read(&u8_keypadData);
		
		if (u8_keypadData == APP_INCREMENT_BTN)
		{
		
			// Increment
			if (u8_gs_programTemp < 35)
			{
				u8_gs_programTemp++;
				LCD_setCursor(2,u8_gs_programTemp-18);
				LCD_writeString((uint8_t*)u8_loadingChar);
			}
		}
		else if (u8_keypadData == APP_DECREMENT_BTN)
		{
			// Decrement
			if (u8_gs_programTemp >18)
			{
				u8_gs_programTemp--;
				LCD_setCursor(2,u8_gs_programTemp-17);
				LCD_writeString((uint8_t*)u8_emptyChar);
			}
		}
		else if (u8_keypadData == APP_SET_BTN)
		{
			// Set
			u8_en_gs_programState = APP_WORKING;
			break;
		}
		else{
			// do nothing
		}
	}
	
}



void APP_working(void)
{
	uint8_t u8_keypadData = 0;
	//char ch_arrs_curTempToString[2];
	
	
	
	// print current temp
	LCD_clear();
	LCD_setCursor(1,1);
	LCD_writeString((uint8_t*)"Current Temp = ");
	
	
	while(u8_en_gs_programState == APP_WORKING)
	{
		// read the temp from the sensor
		TEMP_SENSOR_read(&st_gs_tempSensorConfig,&f32_gs_curTemp);
		
		f32_gs_curTemp /= 4.0 ;
		
		// convert int to string
		//itoa((uint8_t)f32_gs_curTemp,ch_arrs_curTempToString,10);
		//APP_printString(f32_gs_curTemp);
		
		
		LCD_setCursor(2,2);
		APP_printString(f32_gs_curTemp);
		//LCD_writeString((uint8_t*)ch_arrs_curTempToString);
		if (f32_gs_curTemp > u8_gs_programTemp)
		{
			// print the bell shape 
			//LCD_setCursor(2,3);
			LCD_writeSpChar(LCD_BELL);
			
			
			// start the BUZZER
			BUZZER_start();
		}
		else{
			LCD_setCursor(2,1);
			LCD_writeString((uint8_t*)" ");
		}
		KEYPAD_read(&u8_keypadData);
		switch(u8_keypadData)
		{
			case  APP_NO_BTN :
				break;
			case  APP_RESET_BTN :
				// reset
				// Stop the BUZZER
				BUZZER_stop();
				
				// Set the program temp with the default temp
				u8_gs_programTemp = u8_gc_defaultTemp;
				
				// clear LCD and print Temp value is resettled to 20
				LCD_clear();
				LCD_setCursor(1,1);
				LCD_writeString((uint8_t*)"Temp value is");
				LCD_setCursor(2,1);
				u8_delay = 0;
				LCD_writeString((uint8_t*)"resettled to 20");
				
				// 1s timeout
				while(u8_delay <= 2);
				
				// change the program state
				u8_en_gs_programState = APP_SET_TEMP;
				break;
			
			case APP_ADJUST_BTN : 
				// adjust
				
				// Stop the BUZZER
				BUZZER_stop();
				
				// change the program state
				u8_en_gs_programState = APP_SET_TEMP;
				break;
			default:
				
				// Invalid button
				LCD_clear();
				LCD_setCursor(1,1);
				LCD_writeString((uint8_t*)"the operation is");
				LCD_setCursor(2,1);
				u8_delay = 0;
				LCD_writeString((uint8_t*)"not allowed");
			
				// 1s timeout
				while(u8_delay <= 2);
				
				// print current temp
				LCD_clear();
				LCD_setCursor(1,1);
				LCD_writeString((uint8_t*)"Current Temp = ");
				break;
		}
	}
	
}


void APP_timer0OvfHandeler(void)
{
	u8_delay++;
	//PORTD = ~PORTD;
	TIMER_Manager_reset(&st_gs_timer_1_config);
}



void APP_printString(float f32_temp)
{
	uint8_t ch_arrs_curTempToString[3] = {'0','\0','\0'};
	if (((uint8_t)f32_temp)<10)
	{
		ch_arrs_curTempToString[0] =  ((uint8_t)f32_temp)+48;
		ch_arrs_curTempToString[1] = ' ';
	}
	else if (((uint8_t)f32_temp)>=10 && (((uint8_t)f32_temp)<100))
	{
		ch_arrs_curTempToString[0] =  (((uint8_t)f32_temp)/10)+48;
		//ch_arrs_curTempToString[0] = 'x';
		ch_arrs_curTempToString[1] =  (((uint8_t)f32_temp)%10)+48;
	}
	else{
		// do nothing
	}
	LCD_writeString(ch_arrs_curTempToString);
}