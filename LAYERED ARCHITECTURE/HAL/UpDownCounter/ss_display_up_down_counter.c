#include "ss_display_up_down_counter.h"
#include "button.h"
#define  F_CPU 8000000UL
#include "util/delay.h"




#define MAX_NUMBER_TO_DISPLAY (u16)9999
#define DISPLAY_RATE 100
#define  DISPLAY_REFRESH_RATE 5

u16 current_screen_value = 0,new_value=0,temp ;

/***********************************************************************************************************/
/***********************************************************************************************************/
//static void increment_first_digit(void);
/*static void increment_first_digit()
{
	dio_vidWriteChannel(SS1_DISPLAY_SELECTOR_PORT,SS1_DISPLAY_SELECTOR_PIN,STD_LOW);
	if( dio_dioLevelReadChannel(SS_DISPLAY_DECODER_INPUT_PORT,SS_DISPLAY_DECODER_INPUT_PIN3) == STD_LOW &&                //0
		dio_dioLevelReadChannel(SS_DISPLAY_DECODER_INPUT_PORT,SS_DISPLAY_DECODER_INPUT_PIN2) == STD_LOW &&
		dio_dioLevelReadChannel(SS_DISPLAY_DECODER_INPUT_PORT,SS_DISPLAY_DECODER_INPUT_PIN1) == STD_LOW &&
		dio_dioLevelReadChannel(SS_DISPLAY_DECODER_INPUT_PORT,SS_DISPLAY_DECODER_INPUT_PIN0) == STD_LOW )
	{
		dio_vidWriteChannel(SS_DISPLAY_DECODER_INPUT_PORT , SS_DISPLAY_DECODER_INPUT_PIN0,STD_HIGH);
		dio_vidWriteChannel(SS_DISPLAY_DECODER_INPUT_PORT , SS_DISPLAY_DECODER_INPUT_PIN1,STD_LOW);
		dio_vidWriteChannel(SS_DISPLAY_DECODER_INPUT_PORT , SS_DISPLAY_DECODER_INPUT_PIN2,STD_LOW);
		dio_vidWriteChannel(SS_DISPLAY_DECODER_INPUT_PORT , SS_DISPLAY_DECODER_INPUT_PIN3,STD_LOW);
	}
	else if( dio_dioLevelReadChannel(SS_DISPLAY_DECODER_INPUT_PORT,SS_DISPLAY_DECODER_INPUT_PIN3) == STD_LOW &&            //1
			 dio_dioLevelReadChannel(SS_DISPLAY_DECODER_INPUT_PORT,SS_DISPLAY_DECODER_INPUT_PIN2) == STD_LOW &&
			 dio_dioLevelReadChannel(SS_DISPLAY_DECODER_INPUT_PORT,SS_DISPLAY_DECODER_INPUT_PIN1) == STD_LOW &&
			 dio_dioLevelReadChannel(SS_DISPLAY_DECODER_INPUT_PORT,SS_DISPLAY_DECODER_INPUT_PIN0) == STD_HIGH )
	{
		dio_vidWriteChannel(SS_DISPLAY_DECODER_INPUT_PORT , SS_DISPLAY_DECODER_INPUT_PIN0,STD_LOW);
		dio_vidWriteChannel(SS_DISPLAY_DECODER_INPUT_PORT , SS_DISPLAY_DECODER_INPUT_PIN1,STD_HIGH);
		dio_vidWriteChannel(SS_DISPLAY_DECODER_INPUT_PORT , SS_DISPLAY_DECODER_INPUT_PIN2,STD_LOW);
		dio_vidWriteChannel(SS_DISPLAY_DECODER_INPUT_PORT , SS_DISPLAY_DECODER_INPUT_PIN3,STD_LOW);
	}
	else if( dio_dioLevelReadChannel(SS_DISPLAY_DECODER_INPUT_PORT,SS_DISPLAY_DECODER_INPUT_PIN3) == STD_LOW &&           //2
			 dio_dioLevelReadChannel(SS_DISPLAY_DECODER_INPUT_PORT,SS_DISPLAY_DECODER_INPUT_PIN2) == STD_LOW &&
			 dio_dioLevelReadChannel(SS_DISPLAY_DECODER_INPUT_PORT,SS_DISPLAY_DECODER_INPUT_PIN1) == STD_HIGH &&
			 dio_dioLevelReadChannel(SS_DISPLAY_DECODER_INPUT_PORT,SS_DISPLAY_DECODER_INPUT_PIN0) == STD_LOW )
	{
		dio_vidWriteChannel(SS_DISPLAY_DECODER_INPUT_PORT , SS_DISPLAY_DECODER_INPUT_PIN0,STD_HIGH);
		dio_vidWriteChannel(SS_DISPLAY_DECODER_INPUT_PORT , SS_DISPLAY_DECODER_INPUT_PIN1,STD_HIGH);
		dio_vidWriteChannel(SS_DISPLAY_DECODER_INPUT_PORT , SS_DISPLAY_DECODER_INPUT_PIN2,STD_LOW);
		dio_vidWriteChannel(SS_DISPLAY_DECODER_INPUT_PORT , SS_DISPLAY_DECODER_INPUT_PIN3,STD_LOW);
	}
	else if( dio_dioLevelReadChannel(SS_DISPLAY_DECODER_INPUT_PORT,SS_DISPLAY_DECODER_INPUT_PIN3) == STD_LOW &&          //3
			 dio_dioLevelReadChannel(SS_DISPLAY_DECODER_INPUT_PORT,SS_DISPLAY_DECODER_INPUT_PIN2) == STD_LOW &&
			 dio_dioLevelReadChannel(SS_DISPLAY_DECODER_INPUT_PORT,SS_DISPLAY_DECODER_INPUT_PIN1) == STD_HIGH &&
			 dio_dioLevelReadChannel(SS_DISPLAY_DECODER_INPUT_PORT,SS_DISPLAY_DECODER_INPUT_PIN0) == STD_HIGH )
	{
		dio_vidWriteChannel(SS_DISPLAY_DECODER_INPUT_PORT , SS_DISPLAY_DECODER_INPUT_PIN0,STD_LOW);
		dio_vidWriteChannel(SS_DISPLAY_DECODER_INPUT_PORT , SS_DISPLAY_DECODER_INPUT_PIN1,STD_LOW);
		dio_vidWriteChannel(SS_DISPLAY_DECODER_INPUT_PORT , SS_DISPLAY_DECODER_INPUT_PIN2,STD_HIGH);
		dio_vidWriteChannel(SS_DISPLAY_DECODER_INPUT_PORT , SS_DISPLAY_DECODER_INPUT_PIN3,STD_LOW);
	}
	else if( dio_dioLevelReadChannel(SS_DISPLAY_DECODER_INPUT_PORT,SS_DISPLAY_DECODER_INPUT_PIN3) == STD_LOW &&         //4
			 dio_dioLevelReadChannel(SS_DISPLAY_DECODER_INPUT_PORT,SS_DISPLAY_DECODER_INPUT_PIN2) == STD_HIGH &&
			 dio_dioLevelReadChannel(SS_DISPLAY_DECODER_INPUT_PORT,SS_DISPLAY_DECODER_INPUT_PIN1) == STD_LOW &&
			 dio_dioLevelReadChannel(SS_DISPLAY_DECODER_INPUT_PORT,SS_DISPLAY_DECODER_INPUT_PIN0) == STD_LOW )
	{
		dio_vidWriteChannel(SS_DISPLAY_DECODER_INPUT_PORT , SS_DISPLAY_DECODER_INPUT_PIN0,STD_HIGH);
		dio_vidWriteChannel(SS_DISPLAY_DECODER_INPUT_PORT , SS_DISPLAY_DECODER_INPUT_PIN1,STD_LOW);
		dio_vidWriteChannel(SS_DISPLAY_DECODER_INPUT_PORT , SS_DISPLAY_DECODER_INPUT_PIN2,STD_HIGH);
		dio_vidWriteChannel(SS_DISPLAY_DECODER_INPUT_PORT , SS_DISPLAY_DECODER_INPUT_PIN3,STD_LOW);
	}
	else if( dio_dioLevelReadChannel(SS_DISPLAY_DECODER_INPUT_PORT,SS_DISPLAY_DECODER_INPUT_PIN3) == STD_LOW &&			//5
			 dio_dioLevelReadChannel(SS_DISPLAY_DECODER_INPUT_PORT,SS_DISPLAY_DECODER_INPUT_PIN2) == STD_HIGH &&
			 dio_dioLevelReadChannel(SS_DISPLAY_DECODER_INPUT_PORT,SS_DISPLAY_DECODER_INPUT_PIN1) == STD_LOW &&
			 dio_dioLevelReadChannel(SS_DISPLAY_DECODER_INPUT_PORT,SS_DISPLAY_DECODER_INPUT_PIN0) == STD_HIGH )
	{
		dio_vidWriteChannel(SS_DISPLAY_DECODER_INPUT_PORT , SS_DISPLAY_DECODER_INPUT_PIN0,STD_LOW);
		dio_vidWriteChannel(SS_DISPLAY_DECODER_INPUT_PORT , SS_DISPLAY_DECODER_INPUT_PIN1,STD_HIGH);
		dio_vidWriteChannel(SS_DISPLAY_DECODER_INPUT_PORT , SS_DISPLAY_DECODER_INPUT_PIN2,STD_HIGH);
		dio_vidWriteChannel(SS_DISPLAY_DECODER_INPUT_PORT , SS_DISPLAY_DECODER_INPUT_PIN3,STD_LOW);
	}
	else if( dio_dioLevelReadChannel(SS_DISPLAY_DECODER_INPUT_PORT,SS_DISPLAY_DECODER_INPUT_PIN3) == STD_LOW &&			//6
			 dio_dioLevelReadChannel(SS_DISPLAY_DECODER_INPUT_PORT,SS_DISPLAY_DECODER_INPUT_PIN2) == STD_HIGH &&
			 dio_dioLevelReadChannel(SS_DISPLAY_DECODER_INPUT_PORT,SS_DISPLAY_DECODER_INPUT_PIN1) == STD_HIGH &&
			 dio_dioLevelReadChannel(SS_DISPLAY_DECODER_INPUT_PORT,SS_DISPLAY_DECODER_INPUT_PIN0) == STD_LOW )
	{
		dio_vidWriteChannel(SS_DISPLAY_DECODER_INPUT_PORT , SS_DISPLAY_DECODER_INPUT_PIN0,STD_HIGH);
		dio_vidWriteChannel(SS_DISPLAY_DECODER_INPUT_PORT , SS_DISPLAY_DECODER_INPUT_PIN1,STD_HIGH);
		dio_vidWriteChannel(SS_DISPLAY_DECODER_INPUT_PORT , SS_DISPLAY_DECODER_INPUT_PIN2,STD_HIGH);
		dio_vidWriteChannel(SS_DISPLAY_DECODER_INPUT_PORT , SS_DISPLAY_DECODER_INPUT_PIN3,STD_LOW);
	}
	else if( dio_dioLevelReadChannel(SS_DISPLAY_DECODER_INPUT_PORT,SS_DISPLAY_DECODER_INPUT_PIN3) == STD_LOW &&			//7
			 dio_dioLevelReadChannel(SS_DISPLAY_DECODER_INPUT_PORT,SS_DISPLAY_DECODER_INPUT_PIN2) == STD_HIGH &&
			 dio_dioLevelReadChannel(SS_DISPLAY_DECODER_INPUT_PORT,SS_DISPLAY_DECODER_INPUT_PIN1) == STD_HIGH &&
			 dio_dioLevelReadChannel(SS_DISPLAY_DECODER_INPUT_PORT,SS_DISPLAY_DECODER_INPUT_PIN0) == STD_HIGH )
	{
		dio_vidWriteChannel(SS_DISPLAY_DECODER_INPUT_PORT , SS_DISPLAY_DECODER_INPUT_PIN0,STD_LOW);
		dio_vidWriteChannel(SS_DISPLAY_DECODER_INPUT_PORT , SS_DISPLAY_DECODER_INPUT_PIN1,STD_LOW);
		dio_vidWriteChannel(SS_DISPLAY_DECODER_INPUT_PORT , SS_DISPLAY_DECODER_INPUT_PIN2,STD_LOW);
		dio_vidWriteChannel(SS_DISPLAY_DECODER_INPUT_PORT , SS_DISPLAY_DECODER_INPUT_PIN3,STD_HIGH);
	}
	else if( dio_dioLevelReadChannel(SS_DISPLAY_DECODER_INPUT_PORT,SS_DISPLAY_DECODER_INPUT_PIN3) == STD_HIGH &&       //8
			 dio_dioLevelReadChannel(SS_DISPLAY_DECODER_INPUT_PORT,SS_DISPLAY_DECODER_INPUT_PIN2) == STD_LOW &&
			 dio_dioLevelReadChannel(SS_DISPLAY_DECODER_INPUT_PORT,SS_DISPLAY_DECODER_INPUT_PIN1) == STD_LOW &&
			 dio_dioLevelReadChannel(SS_DISPLAY_DECODER_INPUT_PORT,SS_DISPLAY_DECODER_INPUT_PIN0) == STD_LOW )
	{
		dio_vidWriteChannel(SS_DISPLAY_DECODER_INPUT_PORT , SS_DISPLAY_DECODER_INPUT_PIN0,STD_HIGH);
		dio_vidWriteChannel(SS_DISPLAY_DECODER_INPUT_PORT , SS_DISPLAY_DECODER_INPUT_PIN1,STD_LOW);
		dio_vidWriteChannel(SS_DISPLAY_DECODER_INPUT_PORT , SS_DISPLAY_DECODER_INPUT_PIN2,STD_LOW);
		dio_vidWriteChannel(SS_DISPLAY_DECODER_INPUT_PORT , SS_DISPLAY_DECODER_INPUT_PIN3,STD_HIGH);
	}
	else if( dio_dioLevelReadChannel(SS_DISPLAY_DECODER_INPUT_PORT,SS_DISPLAY_DECODER_INPUT_PIN3) == STD_HIGH &&       //9
			 dio_dioLevelReadChannel(SS_DISPLAY_DECODER_INPUT_PORT,SS_DISPLAY_DECODER_INPUT_PIN2) == STD_LOW &&
			 dio_dioLevelReadChannel(SS_DISPLAY_DECODER_INPUT_PORT,SS_DISPLAY_DECODER_INPUT_PIN1) == STD_LOW &&
			 dio_dioLevelReadChannel(SS_DISPLAY_DECODER_INPUT_PORT,SS_DISPLAY_DECODER_INPUT_PIN0) == STD_HIGH )
	{
		dio_vidWriteChannel(SS_DISPLAY_DECODER_INPUT_PORT , SS_DISPLAY_DECODER_INPUT_PIN0,STD_LOW);
		dio_vidWriteChannel(SS_DISPLAY_DECODER_INPUT_PORT , SS_DISPLAY_DECODER_INPUT_PIN1,STD_LOW);
		dio_vidWriteChannel(SS_DISPLAY_DECODER_INPUT_PORT , SS_DISPLAY_DECODER_INPUT_PIN2,STD_LOW);
		dio_vidWriteChannel(SS_DISPLAY_DECODER_INPUT_PORT , SS_DISPLAY_DECODER_INPUT_PIN3,STD_LOW);
	}
}*/
/*void increment_second_digit()
{
	dio_vidWriteChannel(SS1_DISPLAY_SELECTOR_PORT,SS1_DISPLAY_SELECTOR_PIN,STD_LOW);
	second_digit_counter ++;
	if()
}*/


/************************************************************************************************/
/************************************************************************************************/

void ss_display_vinit_counter()
{
	ss_display_vinit();
}

/************************************************************************************************/
/************************************************************************************************/

void ss_display_vcount_up()
{
	if (new_value > MAX_NUMBER_TO_DISPLAY)
	{
		new_value = 0;
		dio_vidWriteChannel(SS1_DISPLAY_SELECTOR_PORT,SS1_DISPLAY_SELECTOR_PIN,STD_LOW);
		dio_vidWriteChannel(SS2_DISPLAY_SELECTOR_PORT,SS2_DISPLAY_SELECTOR_PIN,STD_LOW);//
		dio_vidWriteChannel(SS3_DISPLAY_SELECTOR_PORT,SS4_DISPLAY_SELECTOR_PIN,STD_LOW);//
		dio_vidWriteChannel(SS1_DISPLAY_SELECTOR_PORT,SS3_DISPLAY_SELECTOR_PIN,STD_LOW);
		ss_display_vwrite_num(new_value);
	}
	else
	{
		new_value ++;
		for(int i =0 ; i<DISPLAY_RATE ; i++)
		{
			current_screen_value = new_value;
			
			temp = current_screen_value/1000 ;
			current_screen_value %= 1000 ;
			dio_vidWriteChannel(SS1_DISPLAY_SELECTOR_PORT,SS1_DISPLAY_SELECTOR_PIN,STD_HIGH);
			dio_vidWriteChannel(SS2_DISPLAY_SELECTOR_PORT,SS2_DISPLAY_SELECTOR_PIN,STD_HIGH);//
			dio_vidWriteChannel(SS3_DISPLAY_SELECTOR_PORT,SS3_DISPLAY_SELECTOR_PIN,STD_HIGH);//
			dio_vidWriteChannel(SS4_DISPLAY_SELECTOR_PORT,SS4_DISPLAY_SELECTOR_PIN,STD_LOW);
			ss_display_vwrite_num(temp);
			_delay_ms(1);
			
			temp = current_screen_value/100 ;
			current_screen_value %= 100 ;
			dio_vidWriteChannel(SS1_DISPLAY_SELECTOR_PORT,SS1_DISPLAY_SELECTOR_PIN,STD_HIGH);
			dio_vidWriteChannel(SS2_DISPLAY_SELECTOR_PORT,SS2_DISPLAY_SELECTOR_PIN,STD_HIGH);//
			dio_vidWriteChannel(SS4_DISPLAY_SELECTOR_PORT,SS4_DISPLAY_SELECTOR_PIN,STD_HIGH);//
			dio_vidWriteChannel(SS3_DISPLAY_SELECTOR_PORT,SS3_DISPLAY_SELECTOR_PIN,STD_LOW);
			ss_display_vwrite_num(temp);
			_delay_ms(1);
			
			temp = current_screen_value/10 ;
			current_screen_value %= 10 ;
			dio_vidWriteChannel(SS1_DISPLAY_SELECTOR_PORT,SS1_DISPLAY_SELECTOR_PIN,STD_HIGH);
			dio_vidWriteChannel(SS3_DISPLAY_SELECTOR_PORT,SS3_DISPLAY_SELECTOR_PIN,STD_HIGH);//
			dio_vidWriteChannel(SS4_DISPLAY_SELECTOR_PORT,SS4_DISPLAY_SELECTOR_PIN,STD_HIGH);//
			dio_vidWriteChannel(SS2_DISPLAY_SELECTOR_PORT,SS2_DISPLAY_SELECTOR_PIN,STD_LOW);
			ss_display_vwrite_num(temp);
			_delay_ms(1);
			
			temp = current_screen_value;
			dio_vidWriteChannel(SS4_DISPLAY_SELECTOR_PORT,SS4_DISPLAY_SELECTOR_PIN,STD_HIGH);
			dio_vidWriteChannel(SS2_DISPLAY_SELECTOR_PORT,SS2_DISPLAY_SELECTOR_PIN,STD_HIGH);//
			dio_vidWriteChannel(SS3_DISPLAY_SELECTOR_PORT,SS3_DISPLAY_SELECTOR_PIN,STD_HIGH);//
			dio_vidWriteChannel(SS1_DISPLAY_SELECTOR_PORT,SS1_DISPLAY_SELECTOR_PIN,STD_LOW);
			ss_display_vwrite_num(temp);
			_delay_ms(1);
			
		}
	}
}

/************************************************************************************************/
/************************************************************************************************/

void ss_display_vcount_down()
{
	if (new_value == 0)
	{
		new_value = 9999;
		dio_vidWriteChannel(SS1_DISPLAY_SELECTOR_PORT,SS1_DISPLAY_SELECTOR_PIN,STD_LOW);
		dio_vidWriteChannel(SS2_DISPLAY_SELECTOR_PORT,SS2_DISPLAY_SELECTOR_PIN,STD_LOW);//
		dio_vidWriteChannel(SS3_DISPLAY_SELECTOR_PORT,SS4_DISPLAY_SELECTOR_PIN,STD_LOW);//
		dio_vidWriteChannel(SS1_DISPLAY_SELECTOR_PORT,SS3_DISPLAY_SELECTOR_PIN,STD_LOW);
		ss_display_vwrite_num(9);
		_delay_ms(10);
	}
	else
	{
		new_value --;
		for(int i =0 ; i<DISPLAY_RATE ; i++)
		{
			current_screen_value = new_value;
			
			temp = current_screen_value/1000 ;
			current_screen_value %= 1000 ;
			dio_vidWriteChannel(SS1_DISPLAY_SELECTOR_PORT,SS1_DISPLAY_SELECTOR_PIN,STD_HIGH);
			dio_vidWriteChannel(SS2_DISPLAY_SELECTOR_PORT,SS2_DISPLAY_SELECTOR_PIN,STD_HIGH);//
			dio_vidWriteChannel(SS3_DISPLAY_SELECTOR_PORT,SS3_DISPLAY_SELECTOR_PIN,STD_HIGH);//
			dio_vidWriteChannel(SS4_DISPLAY_SELECTOR_PORT,SS4_DISPLAY_SELECTOR_PIN,STD_LOW);
			ss_display_vwrite_num(temp);
			_delay_ms(1);
			
			temp = current_screen_value/100 ;
			current_screen_value %= 100 ;
			dio_vidWriteChannel(SS1_DISPLAY_SELECTOR_PORT,SS1_DISPLAY_SELECTOR_PIN,STD_HIGH);
			dio_vidWriteChannel(SS2_DISPLAY_SELECTOR_PORT,SS2_DISPLAY_SELECTOR_PIN,STD_HIGH);//
			dio_vidWriteChannel(SS4_DISPLAY_SELECTOR_PORT,SS4_DISPLAY_SELECTOR_PIN,STD_HIGH);//
			dio_vidWriteChannel(SS3_DISPLAY_SELECTOR_PORT,SS3_DISPLAY_SELECTOR_PIN,STD_LOW);
			ss_display_vwrite_num(temp);
			_delay_ms(1);
			
			temp = current_screen_value/10 ;
			current_screen_value %= 10 ;
			dio_vidWriteChannel(SS1_DISPLAY_SELECTOR_PORT,SS1_DISPLAY_SELECTOR_PIN,STD_HIGH);
			dio_vidWriteChannel(SS3_DISPLAY_SELECTOR_PORT,SS3_DISPLAY_SELECTOR_PIN,STD_HIGH);//
			dio_vidWriteChannel(SS4_DISPLAY_SELECTOR_PORT,SS4_DISPLAY_SELECTOR_PIN,STD_HIGH);//
			dio_vidWriteChannel(SS2_DISPLAY_SELECTOR_PORT,SS2_DISPLAY_SELECTOR_PIN,STD_LOW);
			ss_display_vwrite_num(temp);
			_delay_ms(1);
			
			temp = current_screen_value;
			dio_vidWriteChannel(SS4_DISPLAY_SELECTOR_PORT,SS4_DISPLAY_SELECTOR_PIN,STD_HIGH);
			dio_vidWriteChannel(SS2_DISPLAY_SELECTOR_PORT,SS2_DISPLAY_SELECTOR_PIN,STD_HIGH);//
			dio_vidWriteChannel(SS3_DISPLAY_SELECTOR_PORT,SS3_DISPLAY_SELECTOR_PIN,STD_HIGH);//
			dio_vidWriteChannel(SS1_DISPLAY_SELECTOR_PORT,SS1_DISPLAY_SELECTOR_PIN,STD_LOW);
			ss_display_vwrite_num(temp);
			_delay_ms(1);
			
		}
	}
}

/************************************************************************************************/
/************************************************************************************************/

void ss_display_vcount_up_down()
{
	count_action_id count_action =-1 ;
	if (Button_GetStatus(BUTTON0) == PRESSED)
	{
		count_action = COUNT_UP;
	}
	else if (Button_GetStatus(BUTTON1) == PRESSED)
	{
		count_action = COUNT_DOWN;
	}
	
	if(count_action == COUNT_UP)
	{
		ss_display_vcount_up();
	}
	else if (count_action == COUNT_DOWN)
	{
		ss_display_vcount_down();
	}
	else
	{
		ss_display_vrefresh_display();
	}
}

/************************************************************************************************/
/************************************************************************************************/

void ss_display_vrefresh_display()
{
	if (new_value == 0)
	{
		dio_vidWriteChannel(SS1_DISPLAY_SELECTOR_PORT,SS1_DISPLAY_SELECTOR_PIN,STD_LOW);
		dio_vidWriteChannel(SS2_DISPLAY_SELECTOR_PORT,SS2_DISPLAY_SELECTOR_PIN,STD_LOW);//
		dio_vidWriteChannel(SS3_DISPLAY_SELECTOR_PORT,SS3_DISPLAY_SELECTOR_PIN,STD_LOW);//
		dio_vidWriteChannel(SS4_DISPLAY_SELECTOR_PORT,SS4_DISPLAY_SELECTOR_PIN,STD_LOW);
		ss_display_vwrite_num(current_screen_value);
	}
	else
	{
		for(int i =0 ; i<DISPLAY_REFRESH_RATE ; i++)
		{
			current_screen_value = new_value;
			temp = current_screen_value/1000 ;
			current_screen_value %= 1000 ;
			dio_vidWriteChannel(SS1_DISPLAY_SELECTOR_PORT,SS1_DISPLAY_SELECTOR_PIN,STD_HIGH);
			dio_vidWriteChannel(SS2_DISPLAY_SELECTOR_PORT,SS2_DISPLAY_SELECTOR_PIN,STD_HIGH);//
			dio_vidWriteChannel(SS3_DISPLAY_SELECTOR_PORT,SS3_DISPLAY_SELECTOR_PIN,STD_HIGH);//
			dio_vidWriteChannel(SS4_DISPLAY_SELECTOR_PORT,SS4_DISPLAY_SELECTOR_PIN,STD_LOW);
			ss_display_vwrite_num(temp);
			_delay_ms(1);
			
			temp = current_screen_value/100 ;
			current_screen_value %= 100 ;
			dio_vidWriteChannel(SS1_DISPLAY_SELECTOR_PORT,SS1_DISPLAY_SELECTOR_PIN,STD_HIGH);
			dio_vidWriteChannel(SS2_DISPLAY_SELECTOR_PORT,SS2_DISPLAY_SELECTOR_PIN,STD_HIGH);//
			dio_vidWriteChannel(SS4_DISPLAY_SELECTOR_PORT,SS4_DISPLAY_SELECTOR_PIN,STD_HIGH);//
			dio_vidWriteChannel(SS3_DISPLAY_SELECTOR_PORT,SS3_DISPLAY_SELECTOR_PIN,STD_LOW);
			ss_display_vwrite_num(temp);
			_delay_ms(1);
			
			temp = current_screen_value/10 ;
			current_screen_value %= 10 ;
			dio_vidWriteChannel(SS1_DISPLAY_SELECTOR_PORT,SS1_DISPLAY_SELECTOR_PIN,STD_HIGH);
			dio_vidWriteChannel(SS3_DISPLAY_SELECTOR_PORT,SS3_DISPLAY_SELECTOR_PIN,STD_HIGH);//
			dio_vidWriteChannel(SS4_DISPLAY_SELECTOR_PORT,SS4_DISPLAY_SELECTOR_PIN,STD_HIGH);//
			dio_vidWriteChannel(SS2_DISPLAY_SELECTOR_PORT,SS2_DISPLAY_SELECTOR_PIN,STD_LOW);
			ss_display_vwrite_num(temp);
			_delay_ms(1);
			
			temp = current_screen_value;
			dio_vidWriteChannel(SS4_DISPLAY_SELECTOR_PORT,SS4_DISPLAY_SELECTOR_PIN,STD_HIGH);
			dio_vidWriteChannel(SS2_DISPLAY_SELECTOR_PORT,SS2_DISPLAY_SELECTOR_PIN,STD_HIGH);//
			dio_vidWriteChannel(SS3_DISPLAY_SELECTOR_PORT,SS3_DISPLAY_SELECTOR_PIN,STD_HIGH);//
			dio_vidWriteChannel(SS1_DISPLAY_SELECTOR_PORT,SS1_DISPLAY_SELECTOR_PIN,STD_LOW);
			ss_display_vwrite_num(temp);
			_delay_ms(1);
			
		}
	}
	
}

/************************************************************************************************/
/************************************************************************************************/

