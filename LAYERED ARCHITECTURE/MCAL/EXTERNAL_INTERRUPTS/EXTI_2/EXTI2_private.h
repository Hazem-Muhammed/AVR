/****************************************************************/
/*   Author             :    Lord				                */
/*	 Date 				:    3/2/2023 11:00:36 AM			    */
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:    contain the Memory mapped of		*/	
/*							 [MCUCR,MCUCSR,GICR,GIFR] Registers */
/****************************************************************/


/****************************************************************/
/* Description   : Guard to protect this File from include more */
/*                 than one time .                              */
/****************************************************************/

#ifndef _EXT2_PRIV_H
#define _EXT2_PRIV_H

#include "dio.h"
/****************************************************************/	
/** !comment : From Data Sheet :  Memory mapped of MCUCR    	*/
/**			   Register	is  0X55						    	*/
/****************************************************************/
/**			   MCUCR : MCU Control Register contains control	*/
/** 		   bits for interrupt sense control and general 	*/
/**            MCU functions.							    	*/
/****************************************************************/

#define MCUCR		*((volatile u8 * ) (0X55))

/****************************************************************/	
/** !comment : From Data Sheet :  Memory mapped of MCUCSR   	*/
/**			   Register	is  0X54.								*/
/****************************************************************/
/**			   MCUCSR : MCU Control and Status Register			*/
/****************************************************************/

#define MCUCSR      *((volatile u8 * ) (0X54))

/****************************************************************/	
/** !comment : From Data Sheet :  Memory mapped of GICR     	*/
/**			   Register	is  0X5B.								*/
/****************************************************************/
/**			   GICR : General Interrupt Control Register		*/
/****************************************************************/

#define GICR        *((volatile u8 * ) (0X5B))


/****************************************************************/	
/** !comment : From Data Sheet :  Memory mapped of GIFR     	*/
/**			   Register	is  0X5A.						    	*/
/****************************************************************/
/**			   GIFR : General Interrupt Flag Register			*/
/****************************************************************/

#define GIFR        *((volatile u8 * ) (0X5A))


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


/****************************************************************/
/** !comment : Defining each pin related to interrupt 						*/
/** 		   BIT : PIE0 (Peripheral Interrupt Enable of INT0)								*/
/*					  In GICR 					*/

/****************************************************************/

#define PIE0_BIT 6


/****************************************************************/
/** !comment : Defining each pin related to interrupt 						*/
/** 		   BIT : PIE1 (Peripheral Interrupt Enable of INT1)								*/
/*					  In GICR 					*/

/****************************************************************/

#define PIE1_BIT 7


/****************************************************************/
/** !comment : Defining each pin related to interrupt 						*/
/** 		   BIT : PIE2 (Peripheral Interrupt Enable of INT2)								*/
/*					  In GICR 					*/

/****************************************************************/

#define PIE2_BIT 5


/****************************************************************/
/** !comment : Defining each pin related to interrupt 						*/
/** 		   BIT : PIF0 (Peripheral Interrupt Flag of INT0)								*/
/*					  In GICR 					*/

/****************************************************************/

#define PIF0_BIT 6


/****************************************************************/
/** !comment : Defining each pin related to interrupt 						*/
/** 		   BIT : PIF1 (Peripheral Interrupt Flag of INT1)								*/
/*					  In GICR 					*/

/****************************************************************/

#define PIF1_BIT 7


/****************************************************************/
/** !comment : Defining each pin related to interrupt 						*/
/** 		   BIT : PIF2 (Peripheral Interrupt Flag of INT2)								*/
/*					  In GICR 					*/

/****************************************************************/

#define PIF2_BIT 5


/****************************************************************/
/** !comment : Defining each pin related to interrupt 						*/
/** 		   BITS : ISC00, ISC01 (Interrupt sense control of INT0)								*/
/*					  In MCUCR 					*/

/****************************************************************/

#define ISC00_BIT 0
#define ISC01_BIT 1


/****************************************************************/
/** !comment : Defining each pin related to interrupt 						*/
/** 		   BITS : ISC10, ISC11 (Interrupt sense control of INT1)								*/
/*					  In MCUCR 					*/

/****************************************************************/

#define ISC10_BIT 2
#define ISC11_BIT 3

/****************************************************************/
/** !comment : Defining each pin related to interrupt 						*/
/** 		   BIT : ISC2 (Interrupt sense control of INT2)								*/
/*					  In MCUCSR 					*/

/****************************************************************/

#define ISC2_BIT 6



/****************************************************************/
/** !comment : Sense Mode Definition					   		*/
/****************************************************************/

#define IOC			1
#define FALLING		4
#define RISING		7
#define LOW_LEVEL	10




/** Linker Problem solved */
void __vector_3(void) __attribute__(( signal , used ));


#endif	/**!comment : End of the guard [_EXT0_PRIV_H]		   **/