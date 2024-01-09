/*
 * Sensors.c
 *
 * Created: 12/13/2022 7:35:05 PM
 *  Author: M.Sayed
 */ 

#include "Sensors.h"


u16 LM35_GetTemp(void)
{
	u16 temp;
	u16 adc=ADC_Read(LM35_CH);
	temp=((u32)adc*1500)/308;
	return temp;	
}

u8 POT_GetPerc(void)
{
	u8 result;
	u16 adc=ADC_Read(POT);
	result =((u32)100*adc)/1023;
	return result;
	
}


u16 Smoke_GetRate(void)
{
	u16 result;
	u16 adc=ADC_Read(Smoke_CH);
	result=(((u32)(adc-55)*1000)/921)+150;
	return result ;
}
