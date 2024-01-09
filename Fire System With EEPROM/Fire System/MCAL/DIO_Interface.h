

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_


#include "MEMMAP.h"
#include "Utlise.h"
#include "Standard_Type.h"

typedef enum {
	PINA0,
	PINA1,
	PINA2,
	PINA3,
	PINA4,
	PINA5,
	PINA6,
	PINA7,
	PINB0,
	PINB1,
	PINB2,
	PINB3,
	PINB4,
	PINB5,
	PINB6,
	PINB7,
	PINC0,
	PINC1,
	PINC2,
	PINC3,
	PINC4,
	PINC5,
	PINC6,
	PINC7,
	PIND0,
	PIND1,
	PIND2,
	PIND3,
	PIND4,
	PIND5,
	PIND6,
	PIND7,
	PINs_Total
}PIn_name;

typedef enum{
	OUTPUT,
	INFREE,
	INPUT
}PIN_Status;

typedef enum {
	PA,
	PB,
	PC,
	PD
	}PORT_Type;

typedef enum {
LOW,
HIGH
}Voltage_type;

void DIO_InitPin (PIn_name pin ,PIN_Status status );

void DIO_init (void);

void DIO_WRitePin (PIn_name pin ,Voltage_type s);

Voltage_type DIO_ReadPin(PIn_name pin);

void DIO_WritePort(PORT_Type l,u8 k);

void DIO_TogglePin(PIn_name pin);



















#endif /* DIO_INTERFACE_H_ */




