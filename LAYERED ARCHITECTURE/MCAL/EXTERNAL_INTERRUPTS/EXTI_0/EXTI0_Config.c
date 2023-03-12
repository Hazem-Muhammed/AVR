/****************************************************************/
/*   Author             :    Lord				                */
/*	 Date 				:    3/2/2023 11:00:36 AM			    */
/*	 Version 			:    1.0V 							 	*/

#include "EXTI0_Config.h"

void EXTI0_vconfig()
{
	dio_vidConfigChannel(DIO_PORTD,DIO_PIN2,INPUT);
			
	#if (EXTI0_SENSE_MODE == FALLING)
		dio_vidWriteChannel(MCUCR,ISC00_BIT,STD_LOW);
		dio_vidWriteChannel(MCUCR,ISC01_BIT,STD_HIGH);
	#elif (EXTI0_SENSE_MODE == RISING)
		dio_vidWriteChannel(MCUCR,ISC00_BIT,STD_HIGH);
		dio_vidWriteChannel(MCUCR,ISC01_BIT,STD_HIGH);
	#elif (EXTI0_SENSE_MODE == LOW_LEVEL)
		dio_vidWriteChannel(MCUCR,ISC00_BIT,STD_LOW);
		dio_vidWriteChannel(MCUCR,ISC01_BIT,STD_LOW);
	#elif (EXTI0_SENSE_MODE == IOC)
		dio_vidWriteChannel(MCUCR,ISC00_BIT,STD_HIGH);
		dio_vidWriteChannel(MCUCR,ISC01_BIT,STD_LOW);
	#endif
}


void EXTI1_vconfig()
{
	dio_vidConfigChannel(DIO_PORTD,DIO_PIN3,INPUT);
	
	#if (EXTI1_SENSE_MODE == FALLING)
		dio_vidWriteChannel(MCUCR,ISC10_BIT,STD_LOW);
		dio_vidWriteChannel(MCUCR,ISC11_BIT,STD_HIGH);
	#elif (EXTI1_SENSE_MODE == RISING)
		dio_vidWriteChannel(MCUCR,ISC10_BIT,STD_HIGH);
		dio_vidWriteChannel(MCUCR,ISC11_BIT,STD_HIGH);
	#elif (EXTI1_SENSE_MODE == LOW_LEVEL)
		dio_vidWriteChannel(MCUCR,ISC10_BIT,STD_LOW);
		dio_vidWriteChannel(MCUCR,ISC11_BIT,STD_LOW);
	#elif (EXTI1_SENSE_MODE == IOC)
		dio_vidWriteChannel(MCUCR,ISC10_BIT,STD_HIGH);
		dio_vidWriteChannel(MCUCR,ISC11_BIT,STD_LOW);
	#endif
}


void EXTI2_vconfig()
{
	dio_vidConfigChannel(DIO_PORTB,DIO_PIN2,INPUT);
	
	#if (EXTI1_SENSE_MODE == FALLING)
		dio_vidWriteChannel(MCUCR,ISC10_BIT,STD_LOW);
	#elif (EXTI1_SENSE_MODE == RISING)
		dio_vidWriteChannel(MCUCR,ISC10_BIT,STD_HIGH);
	#endif
}


void EXTIall_vconfig()
{
	EXTI0_vconfig();
	EXTI1_vconfig();
	EXTI2_vconfig();
}