/*
 * KeyPad.c
 *
 * Created: 12/11/2022 8:40:32 PM
 *  Author: M.Sayed
 */ 
#include "KeyPad.h"


u8 KEYPAD_GetKey(void)
{
	u8 key=NO_KEY,r,c;
	DIO_WRitePin(FIRST_OUTPUt+0,HIGH);
	DIO_WRitePin(FIRST_OUTPUt+1,HIGH);
	DIO_WRitePin(FIRST_OUTPUt+2,HIGH);
	DIO_WRitePin(FIRST_OUTPUt+3,HIGH);
	for (r=0;r<ROW;r++)
	{
		DIO_WRitePin(FIRST_OUTPUt+r,LOW);
		for (c=0;c<COL;c++)
		{
			if (DIO_ReadPin(FIRST_INPUT+c)==LOW)
			{
				key = KeysArray[r][c];
				while(DIO_ReadPin(FIRST_INPUT+c)==LOW);
			}
		}
		DIO_WRitePin(FIRST_OUTPUt+r,HIGH);
	}	
	return key;
}