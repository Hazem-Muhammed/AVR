#ifndef EEPROM_REGS_H
#define  EEPROM_REGS_H



#define EEARH   *( (volatile u8 *)  0x3F   )
#define EEARL   *( (volatile u16 *)  0x3E   )
//#define EEARL   *( (volatile u8 *)  0x3E   )

#define EEDR    *( (volatile u8 *)  0x3D   )


#define EECR    *( (volatile u8 *)  0x3C   )

#define EERE_BIT  0
#define EEWE_BIT  1
#define EEMWE_BIT 2
#define EERIE_BIT 3

#define SPMCR   *( (volatile u8 *)  0x57   )

#define SPMEN_BIT 0






#endif //EEPROM_REGS_H