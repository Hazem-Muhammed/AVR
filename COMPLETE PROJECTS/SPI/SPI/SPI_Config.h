/*
 * SPI_Config.h
 *
 * Created: 3/4/2023 2:05:47 PM
 *  Author: Lord
 */ 


#ifndef SPI_CONFIG_H_
#define SPI_CONFIG_H_

#include "SPI_regs.h"
#include "dio.h"

void SPI_Vconfig(void);

/*Config data order  (DORD in SPCR)*/
#define DATA_FROM_LSB_FIRST 1
#define DATA_FROM_MSB_FIRST 0

#define DATA_ORDER_CONFIG DATA_FROM_MSB_FIRST


/*Config MATSER/SLAVE Select  (MSTR in SPCR)*/
#define MASTER_MODE 1
#define SLAVE_MODE  0

#define CURRENT_CONFIG_M_OR_S MASTER_MODE


/*Config Clock polarity  (CPOL in SPCR)*/
#define CLK_POLARITY_RISING  0
#define CLK_POLARITY_FALLING 1  

#define CURRENT_CLK_POLARITY  CLK_POLARITY_FALLING



/*Config Clock Phase (CPHA in SPCR)*/
#define CLK_POLARITY_PHASE_SAMPLE_LEAD  0
#define CLK_POLARITY_PHASE_SETUP_LEAD   1

#define CURRENT_CLK_PHASE CLK_POLARITY_PHASE_SAMPLE_LEAD


/*Config Clock Rate  (SPR0/1/SPI2X in SPCR)*/
#define CLK_RATE_OVER_4      4
#define CLK_RATE_OVER_16     16
#define CLK_RATE_OVER_32     32
#define CLK_RATE_OVER_64     64
#define CLK_RATE_OVER_128    128
#define CLK_RATE_OVER_2      2
#define CLK_RATE_OVER_8		 8
#define CLK_RATE_OVER_32_2   32
#define CLK_RATE_OVER_64_2   64

#define CURRENT_CLK_RATE     CLK_RATE_OVER_32

/*defining inputs and outputs ports to the SPI */
#define MISO_PORT DIO_PORTB
#define MOSI_PORT DIO_PORTB
#define SCK_PORT  DIO_PORTB
#define SS_PORT   DIO_PORTB

#define MISO_PIN DIO_PIN6
#define MOSI_PIN DIO_PIN5
#define SCK_PIN  DIO_PIN7
#define SS_PIN   DIO_PIN4


 



#endif /* SPI_CONFIG_H_ */