#ifndef BUZZER_H

#include "dio.h"

#define BUZZER_PORT DIO_PORTC
#define BUZZER_PIN  DIO_PIN6

#define SOURCE 1
#define SINK   0
	
	
#define BUZZER_HW_CONNECTION SOURCE


void buzzer_init(void);
void buzzer_on(void);
void buzzer_off(void);
void buzzer_start_tune(void);
void buzzer_correct_password_tune(void);
void buzzer_wrong_password_tune(void);
void buzzer_entry_tune(void);


#endif