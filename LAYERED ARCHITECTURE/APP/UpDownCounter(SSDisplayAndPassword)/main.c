/*
 * Project1-1.c
 *
 * Created: 2/23/2023 12:22:46 AM
 * Author : Lord
 */ 
#include "buzzer.h"
#include <avr/io.h>
#include "button.h"
#include "led.h"
#include "password.h"

int main(void)
{
	button_vidInit();
	buzzer_init();
	led_init();
	password_init();
    while (1) 
    {
		led_on(LED_BLUE);
		led_on(LED_GREEN);
		led_on(LED_RED);
		led_on(LED_YELLOW);
    }
}

