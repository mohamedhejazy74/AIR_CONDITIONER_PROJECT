/*
 * temp_sensor.h
 *
 * Created: 4/21/2023 12:27:22 AM
 *  Author: Mohamed Abdel-Wahab
 *	EMAIL : mohamedhegay22@gmail.com
 */ 


#ifndef TEMP_SENSOR_H_
#define TEMP_SENSOR_H_

#include "../../MCAL/adc/adc_types.h"

#define ADC_MAX_RESOLUTION		   		 1024
#define  AVCC_VOLTAGE					 5.0
#define  INTERNAL_VOLTAGE				 2.56
#define MAX_TEMPERATURE_SENSOR_VALUE     150
/*max sensor temperature (150)/ max sensor voltage (1.5) */
#define  VOLTAGE_TO_CELSUIS_FACTOR		 100	

typedef struct
{
	uint8_t u8_ref_selection;
	uint8_t u8_prescaler_selection;
	uint8_t u8_channel;
}st_tempSensorConfigType;

typedef uint8_t u8_en_tempSensorErrorsType;

#define TEMP_E_OK				((u8_en_tempSensorErrorsType)0x00)
#define TEMP_E_NOT_OK			((u8_en_tempSensorErrorsType)0x08)


/*
* Description : initialize the sensor & adc channel
* @param A Reference of the Temperature sensor's configuration structure
* @return Std_ReturnType: status of the function
* TEMP_E_OK :the function done successfully
* TEMP_E_NOT_OK :the function has issues performing the function
*/
u8_en_tempSensorErrorsType TEMP_SENSOR_init (st_tempSensorConfigType* st_config);
/*
* Description :Get the Degree in Celsius 
* @param A Reference of return data &  A Reference of the Temperature sensor's configuration structure
* @return Std_ReturnType: status of the function
* TEMP_E_OK :the function done successfully
* TEMP_E_NOT_OK :the function has issues performing the function
*/
u8_en_tempSensorErrorsType TEMP_SENSOR_read (st_tempSensorConfigType* st_config , float * f32_data);

#endif /*	TEMP_SENSOR_H	*/