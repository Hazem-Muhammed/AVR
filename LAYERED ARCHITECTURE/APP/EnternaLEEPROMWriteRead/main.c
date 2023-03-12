/*
 * EEPROM.c
 *
 * Created: 3/11/2023 10:07:15 AM
 * Author : Lord
 */ 

//#include <avr/io.h>

#include "EEPROM_Init.h"
#include "lcd.h"

int main(void)
{
    /* Replace with your application code */
	u8 x = 'A' ;
	u16 adress = 0X0101 ;
	EEPROM_VWrite_Byte(x,adress);
	u8 read_value = EEPROM_VRead_Byte(adress);
	lcd_init();
	lcd_sendCmd(DisplayCursor);
	lcd_displyStr((u8 *)"Char is:");
    while (1) 
    {
		DIO_DDRA_REG = 1<<4 ;
		if(read_value == 65)
		{
			DIO_PORTA_REG = 1<<4 ;
			_delay_ms(100);
			lcd_displyChar(read_value);
		}
			
    }
}



/*
PREBUILD --> #DEFINE
LINK TIME --> ARRAY OF STRUCT
POSTBUILD --> EEPROM SAVES THE CONFIGURATION
*/

//External EEPROM at home
