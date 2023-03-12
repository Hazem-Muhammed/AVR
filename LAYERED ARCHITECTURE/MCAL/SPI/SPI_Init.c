/*
 * SPI_Init.c
 *
 * Created: 3/4/2023 4:20:49 PM
 *  Author: Lord
 */ 


#include "SPI_Init.h"

void SPI_Master_VInit()
{
	SPI_Vconfig();
	SET_BIT(SPCR,SPIE_BIT);
	dio_vidConfigChannel(MOSI_PORT,MOSI_PIN,OUTPUT); //MOSI
	dio_vidConfigChannel(MISO_PORT,MISO_PIN,INPUT);  //MISO
	dio_vidConfigChannel(SCK_PORT,SCK_PIN,OUTPUT);   //CLK
	dio_vidConfigChannel(SS_PORT,SS_PIN,OUTPUT);     //SS
	dio_vidWriteChannel(SS_PORT,SS_PIN,STD_HIGH);
	SET_BIT(SPCR,MSTR_BIT);
	SET_BIT(SPCR,SPE_BIT);
}
/****************************************************/

void SPI_Slave_VInit ()
{
	SPI_Vconfig();
	SET_BIT(SPCR,SPIE_BIT);
	dio_vidConfigChannel(MOSI_PORT,MOSI_PIN,INPUT);   //MOSI
	dio_vidConfigChannel(MISO_PORT,MISO_PIN,OUTPUT);  //MISO
	dio_vidConfigChannel(SCK_PORT,SCK_PIN,INPUT);     //CLK
	dio_vidConfigChannel(SS_PORT,SS_PIN,INPUT);      //SS
	CLEAR_BIT(SPCR,MSTR_BIT);
	SET_BIT(SPCR,SPE_BIT);
}
/****************************************************/
void SPI_Master_VTransmit_Byte(u8 byte)
{
	dio_vidWriteChannel(SS_PORT,SS_PIN,STD_LOW);
	SPDR = byte ;
	while( !( CHECK_BIT(SPSR,SPIF_BIT) )  );
}
/****************************************************/
u8 SPI_Master_u8Trancieve_Byte(u8 byte)
{
	SPDR = byte ;
	u8 buffer =0;
	while( !( CHECK_BIT(SPSR,SPIF_BIT) )  );
	buffer = SPDR ;
	SET_BIT(SPCR,SPIF_BIT);
	return buffer ;
}
/****************************************************/
u8 SPI_Slave_u8Recieve_Byte()
{
	u8 temp=0;
	while( !( CHECK_BIT(SPSR,SPIF_BIT) )  );
	temp = SPDR ;
	SET_BIT(SPCR,SPIF_BIT);
	return temp;
}
/****************************************************/
void SPI_Slave_VTransmit_Byte(u8 byte)
{
	SPDR = byte;
	while( !(CHECK_BIT(SPSR,SPIF_BIT))  );
}
/****************************************************/
void Enable_GIE(void)
{
	SET_BIT(SREG,GIE_BIT);
}

/****************************************************/