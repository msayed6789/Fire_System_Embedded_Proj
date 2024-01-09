/*
 * EEPROM_Services.c
 *
 * Created: 1/2/2023 10:07:16 AM
 *  Author: M.Sayed
 */ 

#include "EEPROM_Services.h"

void EEPROM_WritePassword_4Number(u16 address,u16 pass)
{
	u8 q=0;
	for (u8 i=4;i>0;i--)
	{
		q=pass%10;
		pass=pass/10;
		EEPROM_Write(address+i,q);
		//_delay_ms(5);

	}
}
u16 EEPROM_ReadPassword_4Number(u16 address)
{
	u16 pass=0,mul=1000;
	u8 w=0;
	for (u8 i=1;i<=4;i++)
	{
		w=EEPROM_Read(address+i);
		pass=pass+w*mul;
		mul=mul/10;
	}
	return pass;
}