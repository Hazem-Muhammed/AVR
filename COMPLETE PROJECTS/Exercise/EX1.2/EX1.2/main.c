/*
 * EX1.2.c
 *
 * Created: 2/19/2023 8:55:24 PM
 * Author : Lord
 */ 

#define F_CPU 8000000
#include <avr/io.h>
#include "util/delay.h"

#include "led.h"


int main(void)
{
    led_init();
	
    while (1) 
    {
		led_toggle(LED_YELLOW);
		_delay_ms(500);
		led_toggle(LED_BLUE);
		_delay_ms(500);
		led_toggle(LED_GREEN);
		_delay_ms(500);
		led_toggle(LED_RED);
		_delay_ms(500);
		led_toggle(LED_RED);
		_delay_ms(500);
		led_toggle(LED_GREEN);
		_delay_ms(500);
		led_toggle(LED_BLUE);
		_delay_ms(500);
		led_toggle(LED_YELLOW);
		_delay_ms(500);
    }
}

