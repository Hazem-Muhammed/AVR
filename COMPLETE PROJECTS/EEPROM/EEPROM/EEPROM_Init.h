/*
 * EEPROM_Init.h
 *
 * Created: 3/11/2023 10:42:40 AM
 *  Author: Lord
 */ 


#ifndef EEPROM_INIT_H_
#define EEPROM_INIT_H_

#include "EEPROM_REGS.h"
#include "Std_Types.h"
#include "Bit_Math.h"


u8 EEPROM_VRead_Byte(u16 Adress);
void EEPROM_VWrite_Byte(u8 Data , u16 Adress);



#endif /* EEPROM_INIT_H_ */