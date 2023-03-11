/*
 * SPI_Init.h
 *
 * Created: 3/4/2023 3:47:59 PM
 *  Author: Lord
 */ 


#ifndef SPI_INIT_H_
#define SPI_INIT_H_

#include "SPI_Config.h"

#define MAX_NUM_OF_SLAVES 5
#define CURRENT_SLAVES_NUM 1

void SPI_Master_VInit(void);
void SPI_Slave_VInit (void);

void SPI_Master_VTransmit_Byte(u8 byte);
u8 SPI_Master_u8Trancieve_Byte(u8 byte);

u8 SPI_Slave_u8Recieve_Byte(void);
void SPI_Slave_VTransmit_Byte(u8 Byte);

void Enable_GIE(void);






#endif /* SPI_INIT_H_ */