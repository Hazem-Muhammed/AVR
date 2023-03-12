/*
 * EX1.3.c
 *
 * Created: 2/22/2023 6:52:58 PM
 * Author : Lord
 */ 

#include <avr/io.h>
#include "button.h"
#include "led.h"
#include "buzzer.h"

int main(void)
{
    led_init();
	button_vidInit();
	buzzer_init();

    while (1) 
    {
		button_id_t b0 = BUTTON0 ;
		if(Button_GetStatus(b0) == PRESSED)
			led_toggle(LED_YELLOW);
		button_id_t b3 = BUTTON3 ;
		if(Button_GetStatus(b3) == PRESSED)
		{
			led_on(LED_RED);
			buzzer_on();
		}
		else
		{
			led_off(LED_RED);
			buzzer_off();
		}

    }
}

