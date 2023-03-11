/*
 * SPI_Slave.c
 *
 * Created: 3/5/2023 11:53:21 AM
 * Author : Lord
 */ 
#include "SPI_Init.h"
int main(void)
{
	SPI_Slave_VInit();
    /* Replace with your application code */
    while (1) 
    {
		u8 x = SPI_Slave_u8Recieve_Byte();
		if (x == 0b11110000)
		{
			dio_vidConfigChannel(DIO_PORTA,DIO_PIN0,OUTPUT);
			dio_vidWriteChannel(DIO_PORTA,DIO_PIN0,STD_HIGH);
		}
    }
}

