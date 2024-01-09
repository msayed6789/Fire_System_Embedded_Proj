#include "DIO_Interface.h"
#include "DIO_private.h"


void DIO_InitPin (PIn_name pin ,PIN_Status status)
{
 
 switch(status)
 {
	 case OUTPUT:
	 if(pin/8 == 0)
	 {
		 Set_Bit(DDRA,pin%8);
		 CLR_Bit(PORTA,pin%8);
	 }
	 else if(pin/8 == 1)
	 {
		 Set_Bit(DDRB,pin%8);
		 CLR_Bit(PORTB,pin%8);
	 }
	 else if(pin/8 == 2)
	 {
		 Set_Bit(DDRC,pin%8);
		 CLR_Bit(PORTC,pin%8);
	 }
	 else if(pin/8 == 3)
	 {
		 Set_Bit(DDRD,pin%8);
		 CLR_Bit(PORTD,pin%8);
	 }
	 break;
	 case INFREE:
	 if(pin/8 == 0)
	 {
		 CLR_Bit(DDRA,pin%8);
		 CLR_Bit(PORTA,pin%8);
	 }
	 else if(pin/8 == 1)
	 {
		 CLR_Bit(DDRB,pin%8);
		 CLR_Bit(PORTB,pin%8);
	 }
	 else if(pin/8 == 2)
	 {
		 CLR_Bit(DDRC,pin%8);
		 CLR_Bit(PORTC,pin%8);
	 }
	 else if(pin/8 == 3)
	 {
		 CLR_Bit(DDRD,pin%8);
		 CLR_Bit(PORTD,pin%8);
	 }
	 break;
	 case INPUT:
	 if(pin/8 == 0)
	 {
		 CLR_Bit(DDRA,pin%8);
		 Set_Bit(PORTA,pin%8);
	 }
	 else if(pin/8 == 1)
	 {
		 CLR_Bit(DDRB,pin%8);
		 Set_Bit(PORTB,pin%8);
	 }
	 else if(pin/8 == 2)
	 {
		 CLR_Bit(DDRC,pin%8);
		 Set_Bit(PORTC,pin%8);
	 }
	 else if(pin/8 == 3)
	 {
		 CLR_Bit(DDRD,pin%8);
		 Set_Bit(PORTD,pin%8);
	 }
	 break;
 }
}



void DIO_init (void)
{
	PIn_name p;
	for (p=PINA0;p<PINs_Total;p++)
	{
		DIO_InitPin (p ,Pin_StatusArray[p]);
	}
}



void DIO_WRitePin (PIn_name pin ,Voltage_type s)
{
	switch (s)
	{
		case HIGH:
		 switch (pin)
		 {
			 case PINA0:
			 Set_Bit (PORTA,0);
			 break;
			 case PINA1:
			 Set_Bit (PORTA,1);
			 
			 break;
			 case PINA2:
			 Set_Bit (PORTA,2);
			
			 break;
			 case PINA3:
			 Set_Bit (PORTA,3);
			
			 break;
			 case PINA4:
			 Set_Bit (PORTA,4);
			
			 break;
			 case PINA5:
			 Set_Bit (PORTA,5);
			 
			 break;
			 case PINA6:
			 Set_Bit (PORTA,6);
			 
			 break;
			 case PINA7:
			 Set_Bit (PORTA,7);
			
			 break;
			 case PINB0:
			 Set_Bit (PORTB,0);
			 
			 break;
			 case PINB1:
			 Set_Bit (PORTB,1);
			
			 break;
			 case PINB2:
			 Set_Bit (PORTB,2);
			 
			 break;
			 case PINB3:
			 Set_Bit (PORTB,3);
			
			 break;
			 case PINB4:
			 Set_Bit (PORTB,4);
			
			 break;
			 case PINB5:
			 Set_Bit (PORTB,5);
			 
			 break;
			 case PINB6:
			 Set_Bit (PORTB,6);
			
			 break;
			 case PINB7:
			 Set_Bit (PORTB,7);
			
			 break;
			 case PINC0:
			 Set_Bit (PORTC,0);
			 
			 break;
			 case PINC1:
			 Set_Bit (PORTC,1);
			
			 break;
			 case PINC2:
			 Set_Bit (PORTC,2);
			
			 break;
			 case PINC3:
			 Set_Bit (PORTC,3);
			 
			 break;
			 case PINC4:
			 Set_Bit (PORTC,4);
			 
			 break;
			 case PINC5:
			 Set_Bit (PORTC,5);
			 
			 break;
			 case PINC6:
			 Set_Bit (PORTC,6);
			
			 break;
			 case PINC7:
			 Set_Bit (DDRC,7);
			 
			 break;
			 case PIND0:
			 Set_Bit (PORTD,0);
			
			 break;
			 case PIND1:
			 Set_Bit (PORTD,1);
			
			 break;
			 case PIND2:
			 Set_Bit (PORTD,2);
			
			 break;
			 case PIND3:
			 Set_Bit (PORTD,3);
			 
			 break;
			 case PIND4:
			 Set_Bit (PORTD,4);
			
			 break;
			 case PIND5:
			 Set_Bit (PORTD,5);
			
			 break;
			 case PIND6:
			 Set_Bit (PORTD,6);
			 
			 break;
			 case PIND7:
			 Set_Bit (PORTD,7);
			 break;
			 
		 }break;
		case LOW:
		 switch (pin)
		 {
			 case PINA0:
			 
			 CLR_Bit (PORTA,0);
			 break;
			 case PINA1:
			 
			 CLR_Bit (PORTA,1);
			 break;
			 case PINA2:
			 
			 CLR_Bit (PORTA,2);
			 break;
			 case PINA3:
			 
			 CLR_Bit (PORTA,3);
			 break;
			 case PINA4:
			 
			 CLR_Bit (PORTA,4);
			 break;
			 case PINA5:
			 
			 CLR_Bit (PORTA,5);
			 break;
			 case PINA6:
			 
			 CLR_Bit (PORTA,6);
			 break;
			 case PINA7:
			
			 CLR_Bit (PORTA,7);
			 break;
			 case PINB0:
			
			 CLR_Bit (PORTB,0);
			 break;
			 case PINB1:
			 
			 CLR_Bit (PORTB,1);
			 break;
			 case PINB2:
			 
			 CLR_Bit (PORTB,2);
			 break;
			 case PINB3:
			
			 CLR_Bit (PORTB,3);
			 break;
			 case PINB4:
			 
			 CLR_Bit (PORTB,4);
			 break;
			 case PINB5:
			
			 CLR_Bit (PORTB,5);
			 break;
			 case PINB6:
			 
			 CLR_Bit (PORTB,6);
			 break;
			 case PINB7:
			
			 CLR_Bit (PORTB,7);
			 break;
			 case PINC0:
			
			 CLR_Bit (PORTC,0);
			 break;
			 case PINC1:
			 
			 CLR_Bit (PORTC,1);
			 break;
			 case PINC2:
			 
			 CLR_Bit (PORTC,2);
			 break;
			 case PINC3:
			 
			 CLR_Bit (PORTC,3);
			 break;
			 case PINC4:
			
			 CLR_Bit (PORTC,4);
			 break;
			 case PINC5:
			 
			 CLR_Bit (PORTC,5);
			 break;
			 case PINC6:
			
			 CLR_Bit (PORTC,6);
			 break;
			 case PINC7:
			 
			 CLR_Bit (PORTC,7);
			 break;
			 case PIND0:
			 
			 CLR_Bit (PORTD,0);
			 break;
			 case PIND1:
			 
			 CLR_Bit (PORTD,1);
			 break;
			 case PIND2:
			
			 CLR_Bit (PORTD,2);
			 break;
			 case PIND3:
			
			 CLR_Bit (PORTD,3);
			 break;
			 case PIND4:
			 
			 CLR_Bit (PORTD,4);
			 break;
			 case PIND5:
			
			 CLR_Bit (PORTD,5);
			 break;
			 case PIND6:
			
			 CLR_Bit (PORTD,6);
			 break;
			 case PIND7:
			 
			 CLR_Bit (PORTD,7);
			 break;
		 }break;
	}
	
}

void DIO_WritePort(PORT_Type l,u8 k)
{
	switch (l)
	{
		case PA:
		PORTA =k;
		break;
		case PB:
		PORTB =k;
		break;
		case PC:
		PORTC =k;
		break;
		case PD:
		PORTD =k;
		break;
		
	}
	
}

Voltage_type DIO_ReadPin(PIn_name pin)
{
	Voltage_type volt=LOW;
	if(pin/8 == 0)
	{
		volt=Read_Bit(PINA,pin%8);
	}
	else if(pin/8 == 1)
	{
		volt=Read_Bit(PINB,pin%8);
	}
	else if(pin/8 == 2)
	{
		volt=Read_Bit(PINC,pin%8);
	}
	else if(pin/8 == 3)
	{
		volt=Read_Bit(PIND,pin%8);
	}
	return volt;
	
}

void DIO_TogglePin(PIn_name pin)
{
	if(pin/8 == 0)
	{
		TOG_BIT(PORTA,pin);
	}
	else if(pin/8 ==1)
	{
		TOG_BIT(PORTB,pin%8);
	}
	else if(pin/8 == 2)
	{
		TOG_BIT(PORTC,pin%8);
	}
	else if(pin/8 == 3)
	{
		TOG_BIT(PORTD,pin%8);
	}
}
