/*
 * LCD.h
 *
 * Created: 12/4/2022 4:52:50 PM
 *  Author: M.Sayed
 */ 


#ifndef LCD_H_
#define LCD_H_

#include "DIO_INTERFACE.h"
#include "Standard_Type.h"
#include "Utlise.h"

#define  _4_Bit  1
#define  _8_Bit  2


/*******************pin config**********************/
#define LCD_Mode    _8_Bit

#define RS          PIND0
#define EN          PIND1

#define D7          PINA7
#define D6          PINA6
#define D5          PINA5
#define D4          PINA4

#define LCD_PORT    PC
/**************************************************/


static void LCD_WriteData(u8 data);

void LCD_init (void);

void LCD_Clear(void); 

void LCD_WriteChar(u8 ch);

void LCD_WriteString (u8* str); 

void LCD_WriteNumber(s32 num);

void LCD_WriteBinary(u8 num);

void LCD_ReverseString(u8* str);

void LCD_GoTo (u8 line , u8 cell);

void LCD_GoToClear (u8 line , u8 cell , u8 numOfCells);

void LCD_WeiteHex (u32 num);

void LCD_WriteHex_Mod(u8 num);

void LCD_WriteHex_Mod1(u16 num);

#endif /* LCD_H_ */