/*
 * EEPROM.c
 *
 * Created: 1/1/2023 4:40:40 PM
 *  Author: M.Sayed
 */ 

#include "EEPROM.h"

volatile void (*fptr)(void)=NULLPTR;

u8 c =0;

void EEPROM_Write (u16 address, u8 pdata)
{
	while(Read_Bit(EECR,EEWE));
	EEAR=address;
	EEDR=pdata;
	Set_Bit(EECR,EEMWE);
	Set_Bit(EECR,EEWE);
	_delay_ms(5);
}
u8 EEPROM_Read(u16 address)
{
	while(Read_Bit(EECR,EEWE));
	EEAR=address;
	Set_Bit(EECR,EERE);
	return EEDR;
}

void EEPROM_EnableInterrupt(void)
{
	Set_Bit(EECR,EERIE);
}
void EEPROM_DisableInterrupt(void)
{
	CLR_Bit(EECR,EERIE);
}
void EEPROM_SetCallBack(void (*fp)(void))
{
	fptr=fp;
}

ISR(EE_RDY_vect)
{
	if (fptr!=NULLPTR)
	{
		fptr();
	}
}
