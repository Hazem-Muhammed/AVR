/*
 * EXTI0.c
 *
 * Created: 2/24/2023 9:10:51 PM
 * Author : Lord
 */ 

#include "led.h"
#include "button.h"
#include "EXTI0_init.h"

#define F_CPU 8000000UL
#include "util/delay.h"


void ISR (void);

int main(void)
{
	EXT0_voidCallBack(ISR);
	led_init();
	button_vidInit();
	EXT0_voidInit();
	EXT0_voidEnable();
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

