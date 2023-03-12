/****************************************************************/
/*   Author             :    Lord				                */
/*	 Date 				:    3/2/2023 11:00:36 AM			    */
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:    Configure Sense Mode [config.h] 	*/
/****************************************************************/


/****************************************************************/
/* Description   : Guard to protect this File from include more */
/*                 than one time .                              */
/****************************************************************/
#ifndef _EXT0_CONFIG_H
#define _EXT0_CONFIG_H

#include "EXTI0_private.h"

/****************************************************************/
/** !comment : Please Enter the Sense Mode						*/
/** 		   SENSE_MODE can be : 								*/
/*					    			FALLING 					*/
/*						    		RISING 						*/
/*							    	LOW_LEVEL					*/
/*								    IOT ( Interrupt On Change ) */
/****************************************************************/

#define EXTI0_SENSE_MODE	FALLING
#define EXTI1_SENSE_MODE	FALLING
#define EXTI2_SENSE_MODE	FALLING


void EXTI0_vconfig(void);
void EXTI1_vconfig(void);
void EXTI2_vconfig(void);

void EXTIall_vconfig(void);



#endif	/**!comment : End of the gaurd [_EXT0_CONFIG_H]		   **/