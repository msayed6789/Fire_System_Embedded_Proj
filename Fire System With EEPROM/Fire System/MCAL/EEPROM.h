/*
 * EEPROM.h
 *
 * Created: 1/1/2023 4:41:20 PM
 *  Author: M.Sayed
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_

#include "MEMMAP.h"
#include "Standard_Type.h"
#include "Utlise.h"

typedef enum 
{
  Done,
  Empty,
  Filed	
}EEPROM_STATUS;


void EEPROM_Write (u16 address, u8 pdata);
u8 EEPROM_Read  (u16 address);

void EEPROM_EnableInterrupt(void);
void EEPROM_DisableInterrupt(void);
void EEPROM_SetCallBack(void (*fp)(void));





#endif /* EEPROM_H_ */