/*
 * EX_Interrupt.h
 *
 * Created: 12/14/2022 7:54:42 PM
 *  Author: M.Sayed
 */ 


#ifndef EX_INTERRUPT_H_
#define EX_INTERRUPT_H_
#include "Utlise.h"
#include "MEMMAP.h"
#include "Standard_Type.h"

typedef enum {
	LOW_LEVEL=0,
	ANY_LOGIC_CHANGE,
	FALLING_EDGE,
	RISING_EDGE
}TriggerEdge_type;

typedef enum{
	EX_INT0,
	EX_INT1,
	EX_INT2,
}ExInterruptSource_type;

void EXI_Enable (ExInterruptSource_type Interrupt);
void EXI_Disable (ExInterruptSource_type Interrupt);
void EXI_Trigger(ExInterruptSource_type Interrupt,TriggerEdge_type trigger);
void EXI_SetCallBack(ExInterruptSource_type Interrupt,void(*pf)(void));





#endif /* EX_INTERRUPT_H_ */