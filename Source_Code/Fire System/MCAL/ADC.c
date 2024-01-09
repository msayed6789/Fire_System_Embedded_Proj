#include "ADC.h"

#define F_CPU 8000000000
#include <util/delay.h>

void ADC_init (ADC_Vref_type Vref,ADC_Scaler_type Scaler)
{
	// Vref
	switch (Vref)
	{
		case ADC_AREF:
		CLR_Bit (ADMUX,REFS0);
		CLR_Bit (ADMUX,REFS1);
		break;
		case ADC_VCC:
		Set_Bit (ADMUX,REFS0);
		CLR_Bit (ADMUX,REFS1);
		break;
		case ADC_V256:
		Set_Bit (ADMUX,REFS0);
		Set_Bit (ADMUX,REFS1);
		break;
		
	}
	// prescaler
	ADCSRA =ADCSRA&0xf8;    //11111000
	Scaler=Scaler&0x07;
	ADCSRA=ADCSRA|Scaler;
		

	//adjust read to the right
	CLR_Bit (ADMUX, ADLAR);
	
	// ADC_Enable 
	Set_Bit(ADCSRA,ADEN);	
}


u16 ADC_Read (ADC_Channel_type ch)
{
	// Read Channel
	ADMUX&=0xe0; 
	ADMUX|=ch;
	//start conversion
	Set_Bit(ADCSRA,ADSC);
	/*_delay_ms(300);*/
	//w8 until conversion end 
	//while (Read_Bit(ADCSRA,ADSC));  //busy wait
	
	_delay_ms(100);
	//ADC Read
	return ADC;
}

u16 ADC_Read_Volt (ADC_Channel_type ch)
{
	u16 adc =ADC_Read (ch);
	u16 volt = ((u32)adc*5000)/1024;
	return volt;
}