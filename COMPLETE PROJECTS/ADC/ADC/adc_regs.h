/****************************************************************/
/*   Author             :    LORD 				    */
/*	 Date 				:    25 FEB 2023 						*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:    contain the Memory mapped of		*/
/*							 [MCUCR,MCUCSR,GICR,GIFR] Registers */
/****************************************************************/


/****************************************************************/
/* Description   : Guard to protect this File from include more */
/*                 than one time .                              */
/****************************************************************/

#ifndef _ADC_REG_H
#define _ADC_REG_H

#include "dio.h"


/****************************************************************/
/** !comment : From Data Sheet :  Memory mapped of ADMUX    	*/
/**			   Register	is  0X27						    	*/
/****************************************************************/
/**			   ADMUX : Multiplexer Selection Register 							    	*/
/****************************************************************/

#define ADMUX		*((volatile u8 * ) (0X27))

/****************************************************************/
/** !comment : From Data Sheet :  Memory mapped of ADCSRA    	*/
/**			   Register	is  0X26						    	*/
/****************************************************************/
/**			   ADCSRA : ADC Control and Status Register 							    	*/
/****************************************************************/

#define ADCSRA		*((volatile u8 * ) (0X26))

/****************************************************************/
/** !comment : From Data Sheet :  Memory mapped of ADCH    	*/
/**			   Register	is  0X25						    	*/
/****************************************************************/
/**			   ADCH : Save Data High Register							    	*/
/****************************************************************/

#define ADCH		*((volatile u8 * ) (0X25))

/****************************************************************/
/** !comment : From Data Sheet :  Memory mapped of SFIOR    	*/
/**			   Register	is  0X50						    	*/
/****************************************************************/
/**			   SFIOR : Save Data High Register							    	*/
/****************************************************************/

#define SFIOR		*((volatile u8 * ) (0X50))

/****************************************************************/
/** !comment : From Data Sheet :  Memory mapped of ADCL    	*/
/**			   Register	is  0X24						    	*/
/****************************************************************/
/**			   ADCL : Save Data LOWER Register							    	*/
/****************************************************************/

#define ADCL		*((volatile u8 * ) (0X24))







/********************************************************************************************/
/********* Defining Important Pins *********/
/********************************************************************************************/
//ADMUX BITS
#define REFS0_BIT 6
#define REFS1_BIT 7
#define  ADLAR_BIT 5
#define  MUX0_BIT 0
#define  MUX1_BIT 1
#define  MUX2_BIT 2
#define  MUX3_BIT 3
#define  MUX4_BIT 4

//ADCSRA BITS
#define  ADEN_BIT 7
#define  ADSC_BIT 6
#define  ADATE_BIT 5
#define  ADIF_BIT 4
#define  ADIE_BIT 3
#define  ADPS2_BIT 2
#define  ADPS1_BIT 1
#define  ADPS0_BIT 0

//SFIOR BITS
#define ADTS2_BIT 7
#define ADTS1_BIT 6
#define ADTS0_BIT 5



/****************************************************************/
/** !comment : From Data Sheet :  Memory mapped of SREG     	*/
/**			   Register	is  0X5F.						    	*/
/****************************************************************/
/**			   SREG : Status Register			                */
/****************************************************************/

#define SREG        *((volatile u8 * ) (0X5F))



/****************************************************************/
/** !comment : Defining each pin related to interrupt 						*/
/** 		   BIT : GIE (Global Interrupt Enable)								*/
/*					  In SREG 					*/

/****************************************************************/

#define GIE_BIT 7




#endif