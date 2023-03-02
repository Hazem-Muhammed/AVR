/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  FileName.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "lcd.h"
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/
		
/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)        
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : parameterName   Parameter Describtion                                                                         
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
void lcd_sendCmd(lcd_Cmd_Type cmd){
		//Initializing LCD Data Port to Zero
		dio_vidWriteChannel(DataPort,D4PIN,STD_LOW);
		dio_vidWriteChannel(DataPort,D5PIN,STD_LOW);
		dio_vidWriteChannel(DataPort,D6PIN,STD_LOW);
		dio_vidWriteChannel(DataPort,D7PIN,STD_LOW);
		//Setting LCD to Command Mode
		dio_vidWriteChannel(CommandPort,RSPIN,STD_LOW);
		//Sending Higher nibble to Data Port
		dio_vidWriteChannel(DataPort,D4PIN,(CHECK_BIT(cmd,4)));
		dio_vidWriteChannel(DataPort,D5PIN,(CHECK_BIT(cmd,5)));
		dio_vidWriteChannel(DataPort,D6PIN,(CHECK_BIT(cmd,6)));
		dio_vidWriteChannel(DataPort,D7PIN,(CHECK_BIT(cmd,7)));
		dio_vidWriteChannel(CommandPort,EPIN,STD_HIGH);
		_delay_us(1);
		dio_vidWriteChannel(CommandPort,EPIN,STD_LOW);
		//Sending Lower nibble to Data Port
		dio_vidWriteChannel(DataPort,D4PIN,(CHECK_BIT(cmd,0)));
		dio_vidWriteChannel(DataPort,D5PIN,(CHECK_BIT(cmd,1)));
		dio_vidWriteChannel(DataPort,D6PIN,(CHECK_BIT(cmd,2)));
		dio_vidWriteChannel(DataPort,D7PIN,(CHECK_BIT(cmd,3)));
		dio_vidWriteChannel(CommandPort,EPIN,STD_HIGH);
		_delay_us(1);
		dio_vidWriteChannel(CommandPort,EPIN,STD_LOW);
		//Busy wait to allow LCD to process the command
		_delay_ms(2);	
}
void lcd_sendData(u8 data){
		//Initializing LCD Data Port to Zero
		dio_vidWriteChannel(DataPort,D4PIN,STD_LOW);
		dio_vidWriteChannel(DataPort,D5PIN,STD_LOW);
		dio_vidWriteChannel(DataPort,D6PIN,STD_LOW);
		dio_vidWriteChannel(DataPort,D7PIN,STD_LOW);
		//Setting to LCD to data mode
		dio_vidWriteChannel(CommandPort,RSPIN,STD_HIGH);
		//Sending Higher nibble to Data Port
		dio_vidWriteChannel(DataPort,D4PIN,(CHECK_BIT(data,4)));
		dio_vidWriteChannel(DataPort,D5PIN,(CHECK_BIT(data,5)));
		dio_vidWriteChannel(DataPort,D6PIN,(CHECK_BIT(data,6)));
		dio_vidWriteChannel(DataPort,D7PIN,(CHECK_BIT(data,7)));
		dio_vidWriteChannel(CommandPort,EPIN,STD_HIGH);
		_delay_us(1);
		dio_vidWriteChannel(CommandPort,EPIN,STD_LOW);
		//Sending Lower nibble to Data Port
		dio_vidWriteChannel(DataPort,D4PIN,(CHECK_BIT(data,0)));
		dio_vidWriteChannel(DataPort,D5PIN,(CHECK_BIT(data,1)));
		dio_vidWriteChannel(DataPort,D6PIN,(CHECK_BIT(data,2)));
		dio_vidWriteChannel(DataPort,D7PIN,(CHECK_BIT(data,3)));
		dio_vidWriteChannel(CommandPort,EPIN,STD_HIGH);
		_delay_us(1);
		dio_vidWriteChannel(CommandPort,EPIN,STD_LOW);
		//Busy wait to allow LCD to process the command
		_delay_ms(2);
}
void lcd_displyChar(u8 chr){
	lcd_sendData(chr);
}
void lcd_displyStr(u8* str){
	while((*str))
		lcd_displyChar(*str++);	
}
void lcd_gotoRowColumn(u8 row, u8 column){
	u8 CursorPosition=0x80;
	switch(row){
		case 0:CursorPosition=0x80;CursorPosition+=column;lcd_sendCmd(CursorPosition);break;
		case 1:CursorPosition=0xC0;CursorPosition+=column;lcd_sendCmd(CursorPosition);break;
		case 2:CursorPosition=0x94;CursorPosition+=column;lcd_sendCmd(CursorPosition);break;
		case 3:CursorPosition=0xD4;CursorPosition+=column;lcd_sendCmd(CursorPosition);break;
	}
}
void lcd_init(void){
	//Setting Command Port Channels as OUTPUT
	dio_vidConfigChannel(CommandPort,RSPIN,OUTPUT);
	dio_vidConfigChannel(CommandPort,EPIN,OUTPUT);
	//Setting Data Port Channels as OUTPUT
	dio_vidConfigChannel(DataPort,D4PIN,OUTPUT);
	dio_vidConfigChannel(DataPort,D5PIN,OUTPUT);
	dio_vidConfigChannel(DataPort,D6PIN,OUTPUT);
	dio_vidConfigChannel(DataPort,D7PIN,OUTPUT);
	//Returns Cursor To Home Position
	lcd_sendCmd(HomeReturn);
	//Starting LCD 4-bit 5*8 Matrix 2-line Mode
	lcd_sendCmd(MatrixFiveByTen);
	//Hiding Cursor
	lcd_sendCmd(HideCursor);
	//Clearing LCD
	lcd_sendCmd(ClearLCD);
}


void lcd_vidDisplyNum(u16 num)
{
	u8 num_to_char_array[100], iterator = 0;
	while(num != 0)
	{
		num_to_char_array[iterator] = (u8)(num % 10);
		num /= 10;
		iterator++;
	}
	for(;iterator > 0; iterator--)
	{
		lcd_sendData('0' + (num_to_char_array[iterator-1]));
	}
}

/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
