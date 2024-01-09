/*
 * Sensors.h
 *
 * Created: 12/13/2022 7:35:25 PM
 *  Author: M.Sayed
 */ 


#ifndef SENSORS_H_
#define SENSORS_H_

#include "DIO_Interface.h"
#include "ADC.h"


/***************config**************/
#define LM35_CH    ch_0
#define POT        ch_7
#define Smoke_CH   ch_5

u16 LM35_GetTemp(void);
u8 POT_GetPerc(void);
u16 Smoke_GetRate(void);


#endif /* SENSORS_H_ */