/*
 * Motor.c
 *
 * Created: 12/15/2022 8:51:29 AM
 *  Author: M.Sayed
 */ 
 #include "Motor.h"
 
 
 void Clock_Wise (void)
 {
	 DIO_WRitePin(Motor_IN1,HIGH);
	 DIO_WRitePin(Motor_IN2,LOW);
 }
 
 void AntiClock_Wise (void)
 {
	  DIO_WRitePin(Motor_IN1,LOW);
	  DIO_WRitePin(Motor_IN2,HIGH);
 }
 
 void Stop (void)
 {
	 DIO_WRitePin(Motor_IN1,LOW);
	 DIO_WRitePin(Motor_IN2,LOW);
 }
