#include "password.h"

u8 global_counter = -1;




/************************************************************************************************/
/************************************************************************************************/


void password_init()
{
	const u8 STD_PASSWORD [CURRENT_PASSWORD_SIZE] = CURRENT_PASSWORD;
	boolean press_flag = FALSE;
	boolean global_flag = FALSE ;
	while (global_flag ==FALSE)
	{
		u8 current_entries [MAX_CHARACTERS];
		while (press_flag ==FALSE)
		{
			button_id_t entry = get_entry();
			if(global_counter+1 == MAX_CHARACTERS)
				{
					led_on(LED_RED);
					buzzer_entry_tune();
					buzzer_entry_tune();
					buzzer_entry_tune();
					buzzer_entry_tune();
					led_off(LED_RED);
					led_on(LED_BLUE);
					buzzer_entry_tune();
					led_off(LED_BLUE);
					break;
				}
			if (entry ==BUTTON0 || entry ==BUTTON1 || entry ==BUTTON2)
			add_entry(entry,current_entries);
			else if(entry == BUTTON3)
			{
				press_flag = TRUE;
			}
		}
		
		if(check_password(STD_PASSWORD,current_entries) == TRUE)
		{
			global_flag = TRUE;
			led_on(LED_GREEN);
			buzzer_correct_password_tune();
			led_off(LED_GREEN);
		}
		else
		{
			led_on(LED_RED);
			buzzer_wrong_password_tune();
			led_off(LED_RED);
			press_flag = FALSE;
		}
		global_counter =-1;
	}
	
}

/************************************************************************************************/
/************************************************************************************************/


button_id_t get_entry()
{
	if(Button_GetStatus(BUTTON0) == PRESSED)
		{
			global_counter ++;
			led_on(LED_YELLOW);
			buzzer_entry_tune();
			led_off(LED_YELLOW);
			return BUTTON0 ;
		}
	else if(Button_GetStatus(BUTTON1) == PRESSED)
		{
			global_counter ++;
			led_on(LED_YELLOW);
			buzzer_entry_tune();
			led_off(LED_YELLOW);
			return BUTTON1 ;
		}
	else if(Button_GetStatus(BUTTON2) == PRESSED)
		{
			global_counter ++;
			led_on(LED_YELLOW);
			buzzer_entry_tune();
			led_off(LED_YELLOW);
		return BUTTON2 ;
		}
	else if(Button_GetStatus(BUTTON3) == PRESSED)
		{
			led_on(LED_BLUE);
			buzzer_entry_tune();
			led_off(LED_BLUE);
			return BUTTON3;
		}
	return -1;
}

/************************************************************************************************/
/************************************************************************************************/


void add_entry(button_id_t entry,u8 current_entries [MAX_CHARACTERS])
{
	switch (entry)
	{
		case BUTTON0:
			current_entries[global_counter]= BUTTON0_CHAR ;
			break ;
		
		case BUTTON1:
			current_entries[global_counter]= BUTTON1_CHAR ;
			break ;
		
		case BUTTON2:
			current_entries[global_counter]= BUTTON2_CHAR ;
			break ;
		
		case BUTTON3:
			break ;
	}
}

/************************************************************************************************/
/************************************************************************************************/


boolean check_password(const u8 STD_PASSWORD [CURRENT_PASSWORD_SIZE] ,u8 current_entries [MAX_CHARACTERS])
{
	if(global_counter+1 != CURRENT_PASSWORD_SIZE)
	{
		return FALSE ;
	}
	else
	{
		for(int i=0;i<CURRENT_PASSWORD_SIZE ;i++)
		{
			if(STD_PASSWORD[i] != current_entries[i])
			{
				return FALSE;
			}
		}
	}
	return TRUE;
}

/************************************************************************************************/
/************************************************************************************************/