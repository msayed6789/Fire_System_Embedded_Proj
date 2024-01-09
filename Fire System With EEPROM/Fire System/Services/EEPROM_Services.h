/*
 * EEPROM_Services.h
 *
 * Created: 1/2/2023 10:07:28 AM
 *  Author: M.Sayed
 */ 


#ifndef EEPROM_SERVICES_H_
#define EEPROM_SERVICES_H_

#include "EEPROM.h"

void EEPROM_WritePassword_4Number(u16 address,u16 pass);
u16 EEPROM_ReadPassword_4Number(u16 address);



#endif /* EEPROM_SERVICES_H_ */