/*
 * adc_config.h
 *
 * Created: 2/25/2023 11:14:57 AM
 *  Author: Lord
 */ 


#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_

#include "adc_regs.h"
/****************************************************************/
/** !comment : Please Enter the Voltage Reference				*/
/** 		   VOLTAGE_REFERENCE can be : 						*/
/*					    					AREF 				*/
/*						    				AVCC 				*/
/*							    			INTERNAL			*/
/****************************************************************/
#define AREF 0
#define AVCC 1
#define INTERNAL 2
 
#define VOLTAGE_REFERENCE_CFG		AVCC



/****************************************************************/
/** !comment : Please Enter the ADJUSTMENT						*/
/** 		   ADJUSTMENT can be : 								*/
/*					    					RIGHT_ADJUSTMENT	*/
/*							    			LEFT_ADJUSTMENT		*/
/****************************************************************/
/****************************************************************/
/** NOTE	 : The preferred adjustment for a 8 bits Resolution	*/
/*				is LEFT_ADJUSTMENT and for a 10 bits Resolution	*/
/*				is RIGHT_ADJUSTMENT								*/
/****************************************************************/
#define RIGHT_ADJUSTMENT 0
#define LEFT_ADJUSTMENT 1

#define ADJUSTMENT_CFG  	LEFT_ADJUSTMENT


/****************************************************************/
/** !comment : Please Enter the Analog_Input_Pin				*/
/** 		   Analog_Input_Pin can be : 						*/
/*					    					DIO_U8_PIN_0 				*/
/*						    				....... 				*/
/*							    			DIO_U8_PIN_7			*/
/****************************************************************/

#define DIO_U8_PIN_0    0
#define DIO_U8_PIN_1    1
#define DIO_U8_PIN_2    2
#define DIO_U8_PIN_3    3
#define DIO_U8_PIN_4    4
#define DIO_U8_PIN_5    5
#define DIO_U8_PIN_6    6
#define DIO_U8_PIN_7    7

#define ADC_ANALOG_INPUT_CHANNEL_CFG	DIO_U8_PIN_1

/****************************************************************/
/** !comment : Please Enter the Running Mode				*/
/** 		   Running Mode can be : 						*/
/*					    					AVCC 				*/
/*						    				AREF 				*/
/*							    			INTERNAL			*/
/****************************************************************/

#define FREE_RUNNING_MODE 0
#define ANALOG_COMPARATOR_MODE 1
#define EXTERNAL_INTERRUPT_REQUEST_0_MODE 2
#define TMR0_CTR0_COMPARE_MODE 3
#define TMR0_CTR0_OVERFLOW_MODE 4
#define TMR1_CTR1_COMPARE_MATCH_B_MODE 5
#define TMR1_CTR1_OVERFLOW_MODE 6
#define TMR1_CTR1_CAPTURE_EVENT_MODE 7

#define RUNNING_MODE_CFG FREE_RUNNING_MODE
		

/****************************************************************/
/** !comment : Please Enter the Voltage Reference				*/
/** 		   VOLTAGE_REFERENCE can be : 						*/
/*					    					AVCC 				*/
/*						    				AREF 				*/
/*							    			INTERNAL			*/
/****************************************************************/
#define ADC_PRESCALLER_02 2
#define ADC_PRESCALLER_2 2
#define ADC_PRESCALLER_4 4
#define ADC_PRESCALLER_8 8
#define ADC_PRESCALLER_16 16
#define ADC_PRESCALLER_32 32
#define ADC_PRESCALLER_64 64
#define ADC_PRESCALLER_128 128

#define ADC_PRESCALLER_CFG		ADC_PRESCALLER_64





void adc_vconfig (void);


#endif /* ADC_CONFIG_H_ */