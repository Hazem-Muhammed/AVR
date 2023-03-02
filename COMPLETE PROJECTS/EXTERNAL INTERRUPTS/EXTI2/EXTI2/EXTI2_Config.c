/****************************************************************/
/*   Author             :    Lord				                */
/*	 Date 				:    3/2/2023 11:00:36 AM			    */
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:   public Accessing mechanism prototype*/

#include "EXTI2_Config.h"

void EXTI0_vconfig()
{
	dio_vidConfigChannel(DIO_PORTD,DIO_PIN2,INPUT);
	
	#if (EXTI0_SENSE_MODE == FALLING)
		CLEAR_BIT(MCUCR,ISC00_BIT);
		SET_BIT(MCUCR,ISC01_BIT);
	#elif (EXTI0_SENSE_MODE == RISING)
		SET_BIT(MCUCR,ISC00_BIT);
		SET_BIT(MCUCR,ISC01_BIT);
	#elif (EXTI0_SENSE_MODE == LOW_LEVEL)
		CLEAR_BIT(MCUCR,ISC00_BIT);
		CLEAR_BIT(MCUCR,ISC01_BIT);
	#elif (EXTI0_SENSE_MODE == IOC)
		SET_BIT(MCUCR,ISC00_BIT);
		CLEAR_BIT(MCUCR,ISC01_BIT);
	#endif
}


void EXTI1_vconfig()
{
	dio_vidConfigChannel(DIO_PORTD,DIO_PIN3,INPUT);
	
	#if (EXTI1_SENSE_MODE == FALLING)
		CLEAR_BIT(MCUCR,ISC10_BIT);
		SET_BIT(MCUCR,ISC11_BIT);
	#elif (EXTI1_SENSE_MODE == RISING)
		SET_BIT(MCUCR,ISC10_BIT);
		SET_BIT(MCUCR,ISC11_BIT);
	#elif (EXTI1_SENSE_MODE == LOW_LEVEL)
		CLEAR_BIT(MCUCR,ISC10_BIT);
		CLEAR_BIT(MCUCR,ISC11_BIT);
	#elif (EXTI1_SENSE_MODE == IOC)
		SET_BIT(MCUCR,ISC10_BIT);
		CLEAR_BIT(MCUCR,ISC11_BIT);
	#endif
}


void EXTI2_vconfig()
{
	dio_vidConfigChannel(DIO_PORTB,DIO_PIN2,INPUT);
	
	#if (EXTI1_SENSE_MODE == FALLING)
		CLEAR_BIT(MCUCR,ISC10_BIT);
	#elif (EXTI1_SENSE_MODE == RISING)
		SET_BIT(MCUCR,ISC10_BIT);
	#endif
}


void EXTIall_vconfig()
{
	EXTI0_vconfig();
	EXTI1_vconfig();
	EXTI2_vconfig();
}