#include "buzzer.h"
#define F_CPU 8000000
#include "util/delay.h"

void buzzer_init()
{
	dio_vidConfigChannel(BUZZER_PORT,BUZZER_PIN,OUTPUT);
	dio_vidWriteChannel(BUZZER_PORT,BUZZER_PIN,STD_LOW);
	buzzer_start_tune();
}

void buzzer_on()
{
	#if (BUZZER_HW_CONNECTION == SOURCE)
	{
		dio_vidWriteChannel(BUZZER_PORT,BUZZER_PIN,STD_HIGH);
	}
	#else
	{
		dio_vidWriteChannel(BUZZER_PORT,BUZZER_PIN,STD_LOW);
	}
	#endif
}


void buzzer_off()
{
	#if (BUZZER_HW_CONNECTION == SOURCE)
	{
		dio_vidWriteChannel(BUZZER_PORT,BUZZER_PIN,STD_LOW);
	}
	#elif
	{
		dio_vidWriteChannel(BUZZER_PORT,BUZZER_PIN,STD_LOW);
	}
	#endif
}

void buzzer_start_tune()
{
	dio_vidWriteChannel(BUZZER_PORT,BUZZER_PIN,STD_HIGH);
	_delay_ms(700);
	dio_vidWriteChannel(BUZZER_PORT,BUZZER_PIN,STD_LOW);
}

void buzzer_correct_password_tune()
{
	_delay_ms(700);
	dio_vidWriteChannel(BUZZER_PORT,BUZZER_PIN,STD_HIGH);
	_delay_ms(700);
	dio_vidWriteChannel(BUZZER_PORT,BUZZER_PIN,STD_LOW);
	_delay_ms(700);
	dio_vidWriteChannel(BUZZER_PORT,BUZZER_PIN,STD_HIGH);
	_delay_ms(700);
	dio_vidWriteChannel(BUZZER_PORT,BUZZER_PIN,STD_LOW);
}


void buzzer_wrong_password_tune()
{
	for(int i=0 ; i<10 ; i++)
	{
			_delay_ms(300);
			dio_vidWriteChannel(BUZZER_PORT,BUZZER_PIN,STD_HIGH);
			_delay_ms(300);
			dio_vidWriteChannel(BUZZER_PORT,BUZZER_PIN,STD_LOW);
			_delay_ms(300);
	}
}
