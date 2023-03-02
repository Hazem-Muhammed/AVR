/*
 * SS_Display.c
 *
 * Created: 2/23/2023 4:05:02 PM
 * Author : Lord
 */ 

#include <avr/io.h>
#include "led.h"
#include "buzzer.h"
#include "password.h"
#include "ss_display_up_down_counter.h"


int main(void)
{
    led_init();
	button_vidInit();
	buzzer_init();
	password_init();
	ss_display_vinit_counter();
    while (1) 
    {
		ss_display_vcount_up_down();
		/*//ss_display_vcount_up();
		if(Button_GetStatus(BUTTON0) == PRESSED)
		{
			ss_display_vcount_up();
			//buzzer_entry_tune();
		}
		else if (Button_GetStatus(BUTTON1) == PRESSED)
		{
			ss_display_vcount_down();
			//buzzer_entry_tune();
		}
		else
		{
			ss_display_vrefresh_display();
		}*/
    }
}

