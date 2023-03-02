/*
 * EXTI1.c
 *
 * Created: 2/25/2023 9:37:02 AM
 * Author : Lord
 */ 

#include "led.h"
#include "button.h"
#include "EXTI1_init.h"

#define F_CPU 8000000UL
#include "util/delay.h"


void ISR (void);

int main(void)
{
 	EXT1_voidCallBack(ISR);
 	led_init();
 	button_vidInit();
 	EXT1_voidInit();
 	EXT1_voidEnable();
 	/* Replace with your application code */
 	
 	while (1)
 	{
 	}
}

void ISR ()
{
	led_toggle(LED_GREEN);
	_delay_ms(500);
}
