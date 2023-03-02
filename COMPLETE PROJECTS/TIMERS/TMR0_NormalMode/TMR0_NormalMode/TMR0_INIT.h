/*
 * TMR0_INIT.h
 *
 * Created: 2/26/2023 11:09:44 AM
 *  Author: Lord
 */ 


#ifndef TMR0_INIT_H_
#define TMR0_INIT_H_

// #include "dio_types.h"
// #include "bit_math.h"
// #include "dio_reg.h"
// #include "std_types.h"
#include "TMR0_CFG.h"

void SET_GIE (void);
void RST_GIE (void);

void TIMER0_void_Init(void);

void TIMER0_void_SetTimerReg(u8 Copy_uint8Val);

void TIMER0_void_SetCompareVal(u8 Copy_uint8Val);

void TIMER0_void_EnableOVInt(void);

void TIMER0_void_DisableOVInt(void);

void TIMER0_void_EnableCTCInt(void);

void TIMER0_void_DisableCTCInt(void);

void TIMER0_void_SetOVCallBack(void (*Copy_ptr) (void) ) ;

void TIMER0_void_SetCTCCallBack(void (*Copy_ptr) (void) ) ;


#endif /* TMR0_INIT_H_ */