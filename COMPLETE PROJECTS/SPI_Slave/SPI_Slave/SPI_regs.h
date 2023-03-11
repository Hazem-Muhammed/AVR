/*
 * SPI_regs.h
 *
 * Created: 3/4/2023 1:34:37 PM
 *  Author: Lord
 */ 


#ifndef SPI_REGS_H_
#define SPI_REGS_H_

#include "std_types.h"
#include "bit_math.h"

/* Defining SPI Registers adresses on the MCU */

#define SPCR    (*(volatile u8 *)(0X2D))
#define SPSR    (*(volatile u8 *)(0X2E))
#define SPDR    (*(volatile u8 *)(0X2F))
#define SREG    (*(volatile u8 *)(0X5F))

/* Defining the bits associated in each SFR */

#define SPIE_BIT   7     //INT ENABLE
#define SPE_BIT    6     //SPI ENABLE
#define DORD_BIT   5     //DATA ORDER
#define MSTR_BIT   4     //MASTER/SLAVE SELECT
#define CPOL_BIT   3     //CLK POLARITY (RISING OR FALLING)
#define CPHA_BIT   2     //CLK PHASE (SAMPLE OR SETUP)
#define SPR_1_BIT  1     //SPI CLK RATE SELECT
#define SPR_0_BIT  0     //SPI CLK RATE SELECT



#define SPIF_BIT   7    //SPI INT FLAG
#define WCOL_BIT   6    //WRITE COLllsion FLAG
#define SPI2X_BIT  0    //Double SPI Speed Bit


#define  GIE_BIT  7    //GLOBAL INT ENABLE




#endif /* SPI_REGS_H_ */