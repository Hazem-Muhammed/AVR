/*
 * USART_polling.c
 *
 * Created: 3/3/2023 10:55:22 AM
 * Author : Lord
 */ 

#include <avr/io.h>
#include "uart.h"

int main(void)
{
	UART_Init(UART_BAUDRATE_9600);
    /* Replace with your application code */
    while (1) 
    {
		UART_TransmitChr('4');
		u8 x = UART_ReceiveChr();
    }
}

