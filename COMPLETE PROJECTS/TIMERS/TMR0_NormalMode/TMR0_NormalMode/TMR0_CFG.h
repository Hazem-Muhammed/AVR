/*
 * TMR0_CFG.h
 *
 * Created: 2/26/2023 11:07:46 AM
 *  Author: Lord
 */ 


#ifndef TMR0_CFG_H_
#define TMR0_CFG_H_

#include "dio.h"
#include "TMR0_Regs.h"


/**************************************************************************************/
/* DEFINING ALL MODES OF OPERATIONS  */
#define TIMER0_NORMAL 		1
#define TIMER0_CTC 			2
#define TIMER0_FAST_PWM 	3
#define TIMER0_PHASE_PWM 	4

#define TIMER0_MODE 	TIMER0_NORMAL

/**************************************************************************************/
/* DEFINING ALL PRESCALARS  */
#define TIMER0_DIV_BY_1			1
#define TIMER0_DIV_BY_8			5
#define TIMER0_DIV_BY_64		8
#define TIMER0_DIV_BY_256		10
#define TIMER0_DIV_BY_1024		15

#define TIMER0_PRESCALER  	TIMER0_DIV_BY_1024

/**************************************************************************************/
/* DEFINING OC0 IN COMPARE MATCH CCRT_REG */
#define TIMER0_NO_ACTION	100
#define TIMER0_TOGGLE		12
#define TIMER0_SET			20
#define TIMER0_CLEAR		25

#define TIMER0_COM_EVENT   TIMER0_NO_ACTION


void TIMER0_void_Config(void);


#endif /* TMR0_CFG_H_ */