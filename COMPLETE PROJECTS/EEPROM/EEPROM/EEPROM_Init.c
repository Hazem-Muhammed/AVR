/*
 * EEPROM_Init.c
 *
 * Created: 3/11/2023 10:46:18 AM
 *  Author: Lord
 */ 

#include "EEPROM_Init.h"


u8 EEPROM_VRead_Byte(u16 Adress)
{
	while ( GET_BIT(EECR,EEWE_BIT) ==1  ) ; //WAIT UNTIL WRITE IS COMPLETED
	EEARL = Adress ;
	SET_BIT(EECR,EERE_BIT);
	return EEDR ;
	
}

/***************************************************************/

void EEPROM_VWrite_Byte(u8 Data , u16 Adress)
{
	while ( GET_BIT(EECR,EEWE_BIT) ==1  ) ; //WAIT UNTIL WRITE IS COMPLETED
	while ( GET_BIT(SPMCR,SPMEN_BIT) ==1  ) ; //WAIT UNTIL SPMEN IS ZERO
	EEARL = Adress ;
	EEDR = Data ;
	SET_BIT(EECR,EEWE_BIT) ;
	SET_BIT(EECR,EEMWE_BIT) ;
	CLR_BIT(EECR,EERE_BIT) ;	
}
