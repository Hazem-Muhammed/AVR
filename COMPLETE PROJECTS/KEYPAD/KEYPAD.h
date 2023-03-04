#ifndef KEYPAD_H_
#define KEYPAD_H_

/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/

/* Keypad configurations for number of rows and columns */
#include "dio.h"

#define N_col 4
#define N_row 4

/* Keypad Port Config */

#define KEYPAD_PORT1_IN DIO_PORTB 
#define KEYPAD_PORT2_OUT DIO_PORTD

#define B4  DIO_PIN4
#define B5  DIO_PIN5
#define B6  DIO_PIN6
#define B7  DIO_PIN7
#define D2  DIO_PIN2
#define D3  DIO_PIN3
#define D4  DIO_PIN4
#define D5  DIO_PIN5

u8 KEYPAD_u8get_PressedKey(void);
void KEYPAD_voidInit(void);

#endif /* KEYPAD_H_ */