/*
 * LCD.c
 *
 * Created: 12/4/2022 4:52:37 PM
 *  Author: M.Sayed
 */ 

#include "LCD.h"
#if LCD_Mode ==_8_Bit 
static void LCD_WriteCommand(u8 command)
{
	DIO_WRitePin(RS,LOW);
	DIO_WritePort(LCD_PORT,command);
	DIO_WRitePin(EN,HIGH);
	_delay_ms(1);
	DIO_WRitePin(EN,LOW);
	_delay_ms(1);
}

static void LCD_WriteData(u8 data)
{
	DIO_WRitePin(RS,HIGH);
	DIO_WritePort(LCD_PORT,data);
	DIO_WRitePin(EN,HIGH);
	_delay_ms(1);
	DIO_WRitePin(EN,LOW);
	_delay_ms(1);
}

void LCD_init(void)
{
	_delay_ms(50);
	LCD_WriteCommand(0x38); // 2 line,5*7;
	LCD_WriteCommand(0x0e); // cursor , 0x0f , 0x0e;
	LCD_WriteCommand(0x01); // clear screen;
	_delay_ms(1);
	LCD_WriteCommand(0x06); // increase DDRAM address & No shift;
}

#elif LCD_Mode == _4_Bit
static void LCD_WriteCommand(u8 command)
{
	DIO_WRitePin(RS,LOW);
	DIO_WRitePin(D7,Read_Bit(command,7));
	DIO_WRitePin(D6,Read_Bit(command,6));
	DIO_WRitePin(D5,Read_Bit(command,5));
	DIO_WRitePin(D4,Read_Bit(command,4));
	DIO_WRitePin(EN,HIGH);
	_delay_ms(1);
	DIO_WRitePin(EN,LOW);
	_delay_ms(1);
	DIO_WRitePin(D7,Read_Bit(command,3));
	DIO_WRitePin(D6,Read_Bit(command,2));
	DIO_WRitePin(D5,Read_Bit(command,1));
	DIO_WRitePin(D4,Read_Bit(command,0));
	DIO_WRitePin(EN,HIGH);
	_delay_ms(1);
	DIO_WRitePin(EN,LOW);
	_delay_ms(1);
}

static void LCD_WriteData(u8 data)
{
	DIO_WRitePin(RS,HIGH);
	DIO_WRitePin(D7,Read_Bit(data,7));
	DIO_WRitePin(D6,Read_Bit(data,6));
	DIO_WRitePin(D5,Read_Bit(data,5));
	DIO_WRitePin(D4,Read_Bit(data,4));
	DIO_WRitePin(EN,HIGH);
	_delay_ms(1);
	DIO_WRitePin(EN,LOW);
	_delay_ms(1);
	DIO_WRitePin(D7,Read_Bit(data,3));
	DIO_WRitePin(D6,Read_Bit(data,2));
	DIO_WRitePin(D5,Read_Bit(data,1));
	DIO_WRitePin(D4,Read_Bit(data,0));
	DIO_WRitePin(EN,HIGH);
	_delay_ms(1);
	DIO_WRitePin(EN,LOW);
	_delay_ms(1);
}

void LCD_init(void)
{
	_delay_ms(50);
	LCD_WriteCommand(0x02);
	LCD_WriteCommand(0x28); // 2 line,5*7;
	LCD_WriteCommand(0x0c); // cursor , 0x0f , 0x0e;
	LCD_WriteCommand(0x01); // clear screen;
	_delay_ms(1);
	LCD_WriteCommand(0x06); // increase DDRAM address & No shift;
}
#endif


/*************************************************************/

void LCD_WriteChar(u8 ch)
{
	LCD_WriteData(ch);
}

void LCD_WriteString (u8* str)
{
	u8 i;
	for (i=0;str[i]!='\0';i++)
	{
		LCD_WriteData(str[i]);
	}
}

void LCD_WriteNumber(s32 num)
{
   u8 i=0;
   u8 rem=0;
   u8 str[20]={0};
   if (num==0)
   {
	  LCD_WriteChar('0'); 
	  return;
   }
   if (num<0)
   {
	   num=num*(-1);
	   LCD_WriteChar('-');
   }
   while (num>0)
   {
	rem = num %10;
	str[i]=rem+'0';
	num=num/10;
	i=i+1;
   }
   str[i]='\0';
	LCD_ReverseString(str);
	LCD_WriteString(str);	
}


void LCD_WriteBinary(u8 num)
{
	s8 i=0;
	u8 flag=0;
	for (i=7;i>=0;i--)
	{
		if ((num>>i)&1)
		{
			LCD_WriteChar('1');
			flag=1;
		}
		else 
		{
			if (flag==1)
			{
				LCD_WriteChar('0');
			}
			
		}
	}
}

   void LCD_ReverseString(u8* str)
{
	u8 i=0;
	u8 j=0;
	u8 temp;
	u8 length=0;
	while (str[length]!='\0')
	{
		length++;
	}
	j=length-1;
	while (i!=length/2)
	{
		temp=str[i];
		str[i]=str[j];
		str[j]=temp;
		i++;
		j--;	
	}	
}

void LCD_GoTo (u8 line , u8 cell)
{
	if (line==0)
	{
		LCD_WriteCommand(0x80+cell); // line 2 0 to 0xf
	}
	else if (line==1)
	{
		LCD_WriteCommand(0x80+cell+0x40);  // line 2 0x40 to 0x45
	}
	
}


void LCD_GoToClear (u8 line , u8 cell , u8 numOfCells)
{
	u8 i;
	LCD_GoTo(line,cell);
	for (i=0;i<numOfCells;i++)
	{
		LCD_WriteChar(' ');
	}
	
}
static void Calc_Hex (u8*count,u8 i )
{
	switch (i)
	{
		case 0:
		*count+=1;
		break; 
		case 1:
		*count=*count+2;
		break;
		case 2:
		*count=*count+4;
		break;
		case 3:
		*count=*count+8;
		break;	
	    case 4:
	    *count=*count+1;
	    break;
	    case 5:
	    *count=*count+2;
	    break;
	    case 6:
	    *count=*count+4;
	    break;
	    case 7:
	    *count=*count+8;
	    break;	
		case 8:
		*count=*count+1;
		break;
		case 9:
		*count=*count+2;
		break;
		case 10:
		*count=*count+4;
		break;
		case 11:
		*count=*count+8;
		break;
		case 12:
		*count=*count+1;
		break;
		case 13:
		*count=*count+2;
		break;
		case 14:
		*count=*count+4;
		break;
		case 15:
		*count=*count+8;
		break;
		case 16:
		*count=*count+1;
		break;
		case 17:
		*count=*count+2;
		break;
		case 18:
		*count=*count+4;
		break;
		case 19:
		*count=*count+8;
		break;
		case 20:
		*count=*count+1;
		break;
		case 21:
		*count=*count+2;
		break;
		case 22:
		*count=*count+4;
		break;
		case 23:
		*count=*count+8;
		break;
		case 24:
		*count=*count+1;
		break;
		case 25:
		*count=*count+2;
		break;
		case 26:
		*count=*count+4;
		break;
		case 27:
		*count=*count+8;
		break;
		case 28:
		*count=*count+1;
		break;
		case 29:
		*count=*count+2;
		break;
		case 30:
		*count=*count+4;
		break;
		case 31:
		*count=*count+8;
		break;
		
	}
}
static void Print_Hex (u8 count)
{
	switch(count)
	{
		case 10:
		LCD_WriteChar('A');
		break;
		case 11:
		LCD_WriteChar('B');
		break;
		case 12:
		LCD_WriteChar('C');
		break;
		case 13:
		LCD_WriteChar('D');
		break;
		case 14:
		LCD_WriteChar('E');
		break;
		case 15:
		LCD_WriteChar('F');
		break;
		default:
		LCD_WriteNumber(count);
	}
		
}

void LCD_WeiteHex (u32 num)
{
	u8 count=0,i,sum=0,j=0,str[32]={0};
		for (i=0;i<32;i++)
		{
		   str[i]=(num>>i)&1;
		}
		str[i]='\0';
	for (i=32;i>0;i--)
	{
		if (str[i-1]==1)
		{
			sum=1;
		}
		if (str[i-1]==1)
		{
			Calc_Hex(&count,i-1);
		}
		
		if (sum==1)
		{
			switch(i)
			{
				case 29:
				Print_Hex(count);
				count=0;
				j++;
				break;
				case 25:
				Print_Hex(count);
				count=0;
				j++;
				break;
				case 21:
				Print_Hex(count);
				count=0;
				j++;
				break;
				case 17:
				Print_Hex(count);
				count=0;
				j++;
				break;
				case 13:
				Print_Hex(count);
				count=0;
				j++;
				break;
				case 9:
				Print_Hex(count);
				count=0;
				j++;
				break;
				case 5:
				Print_Hex(count);
				count=0;
				j++;
				break;
				case 1:
				Print_Hex(count);
				count=0;
				j++;
				break;	
			}
		}
		if (j==4)
		{
			LCD_WriteChar(' ');
			j=0;
		}
	} 
	
}
u8 Hex_Rep[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
void LCD_WriteHex_Mod(u8 num)
{
	u8 High_Sig=num>>4;
	u8 Low_Sig=num&0x0f;
	LCD_WriteChar(Hex_Rep[High_Sig]);
	LCD_WriteChar(Hex_Rep[Low_Sig]);	
}

void LCD_WriteHex_Mod1(u16 num)
{
	u8 High_Sig=num>>12;
	u8 Low_Sig=num & 0b0000000000001111;
	u8 Midd_1 =(num>>8) & 0b0000000000001111;
	u8 Midd_2 =(num>>4) & 0b0000000000001111;
	if (High_Sig!=0)
	{
		LCD_WriteChar(Hex_Rep[High_Sig]);
	}
	LCD_WriteChar(Hex_Rep[Midd_1]);
	LCD_WriteChar(Hex_Rep[Midd_2]);
	LCD_WriteChar(Hex_Rep[Low_Sig]);
}

void LCD_Clear()
{
	LCD_WriteCommand(0x01);
}