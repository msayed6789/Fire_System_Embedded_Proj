#define   F_CPU 8000000
#include <util/delay.h>


#include "MemMap.h"
#include "Standard_Type.h"
#include "Utlise.h"




int arr[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
void segment_BCD (u8 n)
{
	//PORTD =n%10;
	PORTA = n;
}

void segment_MUX (u8 n, u8 count)
{
	u8 x,y,m=0;
	
	
		
		x=n%10;
		y=n/10;
		Set_Bit(PORTD,0);
		CLR_Bit (PORTD,1);
		PORTC = arr[y];
		
		_delay_ms(1);
		Set_Bit (PORTD,1);
		CLR_Bit(PORTD,0);
		PORTC = arr[x];
		_delay_ms(1);

	
	
}