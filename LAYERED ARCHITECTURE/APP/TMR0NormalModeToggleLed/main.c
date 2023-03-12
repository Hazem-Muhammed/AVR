/*
 * TMR0_NormalMode.c
 *
 * Created: 2/26/2023 11:05:29 AM
 * Author : Lord
 */ 
#include "led.h"
#include "TMR0_INIT.h"
#define F_CPU 16000000UL

void toggle_led_void_TMR0_overflow (void);

u8 counter = 0;
int main(void)
{
	led_init();
	TIMER0_void_Init();
	SET_GIE();
	TIMER0_void_SetOVCallBack(toggle_led_void_TMR0_overflow);
	TIMER0_void_EnableOVInt();
    /* Replace with your application code */
    while (1) 
    {
    }
}

void toggle_led_void_TMR0_overflow (void)
{
	
	if(counter == 3)
	{
		led_toggle(LED_GREEN);
		counter ==0 ;
	}
	counter ++;
}
