/*
 * TMR0_INIT.c
 *
 * Created: 2/26/2023 11:10:47 AM
 *  Author: Lord
 */ 

#include "TMR0_INIT.h"

void (*TIMER0_OV_CallBack) (void) ;
void (*TIMER0_CTC_CallBack) (void) ;

void TIMER0_void_Init(void)
{
	TIMER0_void_Config();
	
	
	/*Disable Interrupts*/
	CLEAR_BIT(TIMSK , 0);
	CLEAR_BIT(TIMSK , 1);
	RST_GIE();
	
	/*CLEAR FLAGS*/
	SET_BIT(TIFR , 0);
	SET_BIT(TIFR , 1);
	/*Clear register*/
	TCNT0 = 0 ;
	OCR0 = 0 ;
	
	
}

void TIMER0_void_SetTimerReg(u8 Copy_uint8Val)
{
	TCNT0 = Copy_uint8Val ;
}

void TIMER0_void_SetCompareVal(u8 Copy_uint8Val)
{
	OCR0 = Copy_uint8Val ;
}

void TIMER0_void_EnableOVInt(void)
{
	SET_BIT(TIMSK , 0);
}

void TIMER0_void_DisableOVInt(void)
{
	CLEAR_BIT(TIMSK , 0);
}

void TIMER0_void_EnableCTCInt(void)
{
	SET_BIT(TIMSK , 1);
}

void TIMER0_void_DisableCTCInt(void)
{
	CLEAR_BIT(TIMSK , 1);
}

void TIMER0_void_SetOVCallBack(void (*Copy_ptr) (void) )
{
	TIMER0_OV_CallBack = Copy_ptr ;
}

void TIMER0_void_SetCTCCallBack(void (*Copy_ptr) (void) )
{
	TIMER0_CTC_CallBack = Copy_ptr ;
	
}

void __vector_11(void) __attribute__((signal , used));
void __vector_11(void)
{
	
	TIMER0_OV_CallBack();
}

void __vector_10(void) __attribute__((signal , used));
void __vector_10(void)
{
	
	TIMER0_CTC_CallBack();
}










/***************************************************/
void SET_GIE (void)
{
	SET_BIT(SREG,7);
}
void RST_GIE (void)
{
	CLEAR_BIT(SREG,7);
}









