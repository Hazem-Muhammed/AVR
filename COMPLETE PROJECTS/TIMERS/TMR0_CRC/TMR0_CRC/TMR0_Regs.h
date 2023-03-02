/*
 * TMR0_Regs.h
 *
 * Created: 2/26/2023 11:07:16 AM
 *  Author: Lord
 */ 


#ifndef TMR0_REGS_H_
#define TMR0_REGS_H_


#define TIMSK	 (*(volatile u8 * )0x59)
#define OCR0 	 (*(volatile u8 * )0x5C)
#define TCCR0	 (*(volatile u8 * )0x53)
#define TCNT0	 (*(volatile u8 * )0x52)
#define TIFR	 (*(volatile u8 * )0x58)

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





#endif /* TMR0_REGS_H_ */