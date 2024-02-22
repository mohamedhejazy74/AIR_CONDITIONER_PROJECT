/*
 * adc_types.h
 *
 * Created: 4/21/2023 3:22:21 AM
 *  Author:  ARAFA ARAFA
 *	EMAIL : arafa.arafa.prog@gmail.com
 */ 


#ifndef ADC_TYPES_H_
#define ADC_TYPES_H_


#include <stdint.h>

/* addresses of ADC registers*/
#define ACSR_ADD	(*((volatile uint8_t *)0x28))
#define ANALOG_COMPARATOR_DISABLE	7
#define ANALOG_COMPARATOR_INTERRUPT_FLAG	4
#define ANALOG_COMPARATOR_INTERRUPT_ENABLE	3

#define ADMUX_ADD	(*((volatile uint8_t *)0x27))
#define ADC_VREF_SELECT	6
#define ADC_LEFT_ADJUST_RESULT	5


#define ADCSRA_ADD	(*((volatile uint8_t *)0x26))
#define ADC_ENABLE	7
#define ADC_START_CONVERSION	6
#define ADC_INT_FLAG	4
#define ADC_INT_ENABLE	3


#define ADCH_ADD	(*((volatile uint8_t *)0x25))
#define ADCL_ADD	(*((volatile uint8_t *)0x24))

/**return modes of  ADC**/
typedef uint8_t u8_en_adcErrorsType;
#define ADC_E_OK					((u8_en_adcErrorsType)0x00)
#define ADC_E_NOT_OK				((u8_en_adcErrorsType)0x04)

/**vref modes of  ADC**/
typedef uint8_t u8_en_adcChannelId;

#define ADC_CHANNEL_0							((u8_en_adcChannelId)0x00)
#define ADC_CHANNEL_1							((u8_en_adcChannelId)0x01)
#define ADC_CHANNEL_2							((u8_en_adcChannelId)0x02)
#define ADC_CHANNEL_3							((u8_en_adcChannelId)0x03)
#define ADC_CHANNEL_4							((u8_en_adcChannelId)0x04)
#define ADC_CHANNEL_5							((u8_en_adcChannelId)0x05)
#define ADC_CHANNEL_6							((u8_en_adcChannelId)0x06)
#define ADC_CHANNEL_7							((u8_en_adcChannelId)0x07)
#define ADC_INVALID_CHANNEL						((u8_en_adcChannelId)0x08)

#define ADC_CHANNEL_0				((u8_en_adcChannelId)0x00)
#define ADC_CHANNEL_1				((u8_en_adcChannelId)0x01)
#define ADC_CHANNEL_2				((u8_en_adcChannelId)0x02)
#define ADC_CHANNEL_3				((u8_en_adcChannelId)0x03)
#define ADC_CHANNEL_4				((u8_en_adcChannelId)0x04)
#define ADC_CHANNEL_5				((u8_en_adcChannelId)0x05)
#define ADC_CHANNEL_6				((u8_en_adcChannelId)0x06)
#define ADC_CHANNEL_7				((u8_en_adcChannelId)0x07)
#define ADC_INVALID_CHANNEL			((u8_en_adcChannelId)0x08)




/**vref modes of  ADC**/
typedef uint8_t u8_en_adcRefType;
#define ADC_AREF_INTERNAL_VREF_OFF				((u8_en_adcRefType)0x00)
#define ADC_AVCC								((u8_en_adcRefType)0x01)
#define ADC_RESERVED							((u8_en_adcRefType)0x02)
#define ADC_INTERNAL_2_56V_REF					((u8_en_adcRefType)0x03)


/**precaller modes of  ADC**/
typedef uint8_t u8_en_adcPrescalerType;
#define ADC_PRESCALER_2_0					((u8_en_adcPrescalerType)0x00)
#define ADC_PRESCALER_2						((u8_en_adcPrescalerType)0x01)
#define ADC_PRESCALER_4						((u8_en_adcPrescalerType)0x02)
#define ADC_PRESCALER_8						((u8_en_adcPrescalerType)0x03)
#define ADC_PRESCALER_16					((u8_en_adcPrescalerType)0x04)
#define ADC_PRESCALER_32					((u8_en_adcPrescalerType)0x05)
#define ADC_PRESCALER_64					((u8_en_adcPrescalerType)0x06)
#define ADC_PRESCALER_128					((u8_en_adcPrescalerType)0x07)
#define ADC_INVALID_PRESCALER				((u8_en_adcPrescalerType)0x08)



/**configuration of  ADC**/

typedef struct
{
	u8_en_adcRefType u8_ref_selection;
	u8_en_adcPrescalerType u8_prescaler_selection;
}st_adcConfigType;




#endif /* ADC_TYPES_H_ */