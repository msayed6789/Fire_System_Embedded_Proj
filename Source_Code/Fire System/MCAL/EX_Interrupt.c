/*
 * EX_Interrupt.c
 *
 * Created: 12/14/2022 7:54:22 PM
 *  Author: M.Sayed
 */ 


#include "EX_Interrupt.h"

/***************************Pointer to function for ISr************/
static void (*pf_INT0)(void)=NULLPTR;
static void (*pf_INT1)(void)=NULLPTR;
static void (*pf_INT2)(void)=NULLPTR;

/************************************Call back Function***********/
void EXI_SetCallBack(ExInterruptSource_type Interrupt,void(*pf)(void))
{
	switch (Interrupt)
	{
		case EX_INT0: 
		pf_INT0 =pf;
		break;
		case EX_INT1:
		pf_INT1 =pf;
		break;
		case EX_INT2:
		pf_INT2 =pf;
		break;
	}
}



/*****************Enable/Disable/Trigger Interrupt Functions*******/

void EXI_Enable (ExInterruptSource_type Interrupt)
{
	switch (Interrupt)
	{
		case EX_INT0:
		Set_Bit(GICR,INT0);
		break;
		case EX_INT1:
		Set_Bit(GICR,INT1);
		break;
		case EX_INT2:
		Set_Bit(GICR,INT2);
		break;
	}
}
void EXI_Disable (ExInterruptSource_type Interrupt)
{
	switch (Interrupt)
	{
		case EX_INT0:
		CLR_Bit(GICR,INT0);
		break;
		case EX_INT1:
		CLR_Bit(GICR,INT1);
		break;
		case EX_INT2:
		CLR_Bit(GICR,INT2);
		break;
	}
}
void EXI_Trigger(ExInterruptSource_type Interrupt,TriggerEdge_type trigger)
{
	if (Interrupt!=INT2)
	{
		switch(trigger)
		{
			case LOW_LEVEL:
			if (Interrupt==INT0)
			{
				CLR_Bit (MCUCR,ISC00);
				CLR_Bit (MCUCR,ISC01);
			}
			else if (Interrupt==EX_INT1)
			{
				CLR_Bit (MCUCR,ISC10);
				CLR_Bit (MCUCR,ISC11);
			}
			break;
			case ANY_LOGIC_CHANGE:
			if (Interrupt==INT1)
			{
				CLR_Bit (MCUCR,ISC11);
				Set_Bit (MCUCR,ISC10);
			}
			else if (Interrupt==INT0)
			{
				CLR_Bit (MCUCR,ISC01);
				Set_Bit (MCUCR,ISC00);
			}
			break;
			case FALLING_EDGE:
			if (Interrupt==INT1)
			{
				Set_Bit (MCUCR,ISC11);
				CLR_Bit (MCUCR,ISC10);
			}
			else if (Interrupt==INT0)
			{
				Set_Bit (MCUCR,ISC01);
				CLR_Bit (MCUCR,ISC00);
			}
			break;
			case RISING_EDGE:
			if (Interrupt==INT1)
			{
				Set_Bit (MCUCR,ISC11);
				Set_Bit (MCUCR,ISC10);
			}
			else if (Interrupt==INT0)
			{
				Set_Bit (MCUCR,ISC01);
				Set_Bit (MCUCR,ISC00);
			}
			break;
		}
	}
	else 
	{
		switch(trigger)
		{
			case FALLING_EDGE:
			CLR_Bit (MCUCSR,ISC2);
			break;
			case RISING_EDGE:
			Set_Bit (MCUCSR,ISC2);
			break;
			default:
			CLR_Bit (MCUCSR,ISC2);
		}
		
	}	
}

ISR (INT0_vect)
{
	if (pf_INT0!=NULLPTR)
	{
		pf_INT0();
	}
}

ISR (INT1_vect)
{
	if (pf_INT0!=NULLPTR)
	{
		pf_INT1();
	}
}

ISR (INT2_vect)
{
	if (pf_INT0!=NULLPTR)
	{
		pf_INT2();
	}
}