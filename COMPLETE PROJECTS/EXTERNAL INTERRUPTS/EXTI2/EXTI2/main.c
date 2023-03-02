/*
 * EXTI2.c
 *
 * Created: 3/2/2023 11:00:36 AM
 * Author : Lord
 */ 

#include "led.h"
#include "button.h"
#include "EXTI2_init.h"

#define F_CPU 8000000UL
#include "util/delay.h"


void ISR (void);

int main(void)
{
	EXT2_voidCallBack(ISR);
	led_init();
	button_vidInit();
	EXT2_voidInit();
	EXT2_voidEnable();
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

