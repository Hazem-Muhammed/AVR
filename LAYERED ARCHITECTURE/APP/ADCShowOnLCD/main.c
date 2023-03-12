/*
 * ADC.c
 *
 * Created: 2/25/2023 9:53:36 AM
 * Author : Lord
 */ 


#include "adc_init.h"
#include "led.h"
#include "lcd.h"


int main(void)
{
    led_init();
	ADC_voidInit();
	ADC_voidEnable();
	SET_GIE();
	lcd_init();
	lcd_sendCmd(DisplayCursor);
	u8 * welcome = (u8 *)"ADC VALUE IS:";
	lcd_displyStr(welcome);
	
    while (1) 
    {
		ADC_voidStartConversion();
		u16 x = 0;
		lcd_gotoRowColumn(0,0);
		lcd_displyStr(welcome);
		x= ADC_u16ReadADCInMV();
		lcd_vidDisplyNum(x);
		_delay_ms(1000);
		lcd_sendCmd(ClearLCD);
		if(x == 0)
			led_off(LED_GREEN);
		else
			led_on(LED_GREEN);
		lcd_gotoRowColumn(0,13);
    }
}

