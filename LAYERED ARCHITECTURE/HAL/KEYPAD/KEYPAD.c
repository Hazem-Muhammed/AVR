
#define F_CPU 16000000
#include "keypad.h"
#include <util/delay.h>

void KEYPAD_voidInit(void)
{
	//rows as inputs ,col as outputs equal ones
	
	dio_vidConfigChannel(KEYPAD_PORT1_IN  , B4 , INPUT);
	dio_vidEnablePullUp(KEYPAD_PORT1_IN  , B4);
	dio_vidConfigChannel(KEYPAD_PORT1_IN  , B5 , INPUT);
	dio_vidEnablePullUp(KEYPAD_PORT1_IN  , B5);
	dio_vidConfigChannel(KEYPAD_PORT1_IN  , B6 , INPUT);
	dio_vidEnablePullUp(KEYPAD_PORT1_IN  , B6);
	dio_vidConfigChannel(KEYPAD_PORT1_IN  , B7 , INPUT);
	dio_vidEnablePullUp(KEYPAD_PORT1_IN  , B7);
	
	dio_vidConfigChannel(KEYPAD_PORT2_OUT , D2 , OUTPUT);
	dio_vidConfigChannel(KEYPAD_PORT2_OUT , D3 , OUTPUT);
	dio_vidConfigChannel(KEYPAD_PORT2_OUT , D4 , OUTPUT);
	dio_vidConfigChannel(KEYPAD_PORT2_OUT , D5 , OUTPUT);
	
    //write 
	dio_vidWriteChannel(KEYPAD_PORT2_OUT , D2 , STD_HIGH);
	dio_vidWriteChannel(KEYPAD_PORT2_OUT , D3 , STD_HIGH);
	dio_vidWriteChannel(KEYPAD_PORT2_OUT , D4 , STD_HIGH);
	dio_vidWriteChannel(KEYPAD_PORT2_OUT , D5 , STD_HIGH);

}
u8 KPD_arr[4][4]={ 
	//arr of ascii characters
	{'1','2','3','+'},
	{'4','5','6','-'},
	{'7','8','9','/'},
	{'.','0','=','*'}
};

u8 KEYPAD_u8get_PressedKey(void){
	u8 u8col,u8row,swval=0xff;
	for(u8col=2;u8col<6;u8col++){ 
		dio_vidWriteChannel(KEYPAD_PORT2_OUT , u8col , STD_LOW); //make col equal zero then loop this zero
		for(u8row=4;u8row<8;u8row++){
			if(dio_dioLevelReadChannel(KEYPAD_PORT1_IN, u8row)== STD_LOW){ //check if any row be equal zero
				swval=KPD_arr[u8row-4][u8col-2]; //get character
				while(dio_dioLevelReadChannel(KEYPAD_PORT1_IN, u8row)== STD_LOW); //what until released
				_delay_ms(150); //for debouncing
			}
		}
		dio_vidWriteChannel(KEYPAD_PORT2_OUT , u8col , STD_HIGH); //return the col equal one
	}
	return swval; //return char ready to send to lcd
}