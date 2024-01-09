/*
 * Motor.h
 *
 * Created: 12/15/2022 8:52:05 AM
 *  Author: M.Sayed
 */ 


#ifndef MOTOR_H_
#define MOTOR_H_
#include "DIO_Interface.h"
#include "ADC.h"

/**************************Pin_config**************************/
#define Motor_IN1  PIND4
#define Motor_IN2  PIND5




void Clock_Wise (void);
void AntiClock_Wise (void);
void Stop (void);


#endif /* MOTOR_H_ */