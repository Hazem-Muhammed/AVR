#ifndef SS_DISPLAY_CFG_H

#define SS_DISPLAY_CFG_H
#include "dio.h"

// Defining the HW connections of the decoder inputs from mcu

#define  SS_DISPLAY_DECODER_INPUT_PORT DIO_PORTB	

#define  SS_DISPLAY_DECODER_INPUT_PIN0 DIO_PIN0
#define  SS_DISPLAY_DECODER_INPUT_PIN1 DIO_PIN1
#define  SS_DISPLAY_DECODER_INPUT_PIN2 DIO_PIN2
#define  SS_DISPLAY_DECODER_INPUT_PIN3 DIO_PIN4

// Defining the HW connections of the first ss selector from mcu
#define SS1_DISPLAY_SELECTOR_PORT DIO_PORTA
#define SS1_DISPLAY_SELECTOR_PIN  DIO_PIN3

// Defining the HW connections of the second ss selector from mcu
#define SS2_DISPLAY_SELECTOR_PORT DIO_PORTA
#define SS2_DISPLAY_SELECTOR_PIN  DIO_PIN2

// Defining the HW connections of the third ss selector from mcu
#define SS3_DISPLAY_SELECTOR_PORT DIO_PORTB
#define SS3_DISPLAY_SELECTOR_PIN  DIO_PIN5

// Defining the HW connections of the forth ss selector from mcu
#define SS4_DISPLAY_SELECTOR_PORT DIO_PORTB
#define SS4_DISPLAY_SELECTOR_PIN  DIO_PIN6

//defining the HW configurations of the ss

#define COMMON_ANODE_CONFIGURATION 0
#define COMMON_CATHODE_CONFIGURATION 1

#define  SS1_HW_CONNECTION COMMON_ANODE_CONFIGURATION
#define  SS2_HW_CONNECTION COMMON_ANODE_CONFIGURATION
#define  SS3_HW_CONNECTION COMMON_ANODE_CONFIGURATION
#define  SS4_HW_CONNECTION COMMON_ANODE_CONFIGURATION
// the BCD controls the signals before reach the 7 segment


#endif