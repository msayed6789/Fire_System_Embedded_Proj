
#ifndef UTILS_H_
#define UTILS_H_


#define F_CPU  8000000
#include <util/delay.h>
#include "Standard_Type.h"


#define Read_Bit(reg,bit)         ((reg>>bit) & 1)
#define Set_Bit(reg,bit)          (reg|=1<<bit)
#define CLR_Bit(reg,bit)          (reg&=~(1<<bit))
#define TOG_BIT(reg,bit)          (reg=reg^(1<<bit))
#define WRITE_BIT(reg,bit,val)    (reg=(reg&(~(1<<bit))) | (val<<bit))


void segment_BCD (u8 n);
void segment_MUX (u8 n,u8 count);


#endif /* UTILS_H_ */