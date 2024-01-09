

#ifndef ADC_H_
#define ADC_H_

#include "Standard_Type.h"
#include "Utlise.h"
#include "MEMMAP.h"

typedef enum {
	ADC_AREF,
	ADC_VCC,
	ADC_V256
	} ADC_Vref_type;
	
	
typedef enum{
	ADC_SCAler_2=0,
	ADC_SCAler_4=2,
	ADC_SCAler_8,
	ADC_SCAler_16,
	ADC_SCAler_32,
    ADC_SCAler_64,
	ADC_SCAler_128,
	
	} ADC_Scaler_type;

typedef enum{
	ch_0=0,
	ch_1,
	ch_2,
	ch_3,
	ch_4,
	ch_5,
	ch_6,
	ch_7,
	}ADC_Channel_type;


 void ADC_init (ADC_Vref_type Vref,ADC_Scaler_type Scaler);
  
  
 u16 ADC_Read (ADC_Channel_type ch);

u16 ADC_Read_Volt (ADC_Channel_type ch);










#endif /* ADC_H_ */