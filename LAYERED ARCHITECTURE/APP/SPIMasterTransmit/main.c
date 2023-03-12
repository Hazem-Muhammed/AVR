/*
 * SPI.c
 *
 * Created: 3/4/2023 1:31:59 PM
 * Author : Lord
 */ 

//#include <avr/io.h>
#define F_CPU 8000000UL
#include "SPI_Init.h"
#include "util/delay.h"
int main(void)
{
	SPI_Master_VInit();
	Enable_GIE();
    /* Replace with your application code */
    while (1) 
    {
		SPI_Master_VTransmit_Byte(0b11110000);
		_delay_ms(200);
		
    }
}

