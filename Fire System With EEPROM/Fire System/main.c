
 #include "DIO_Interface.h"
 #include "ADC.h"
 #include "EX_Interrupt.h"
 #include "LCD.h"
 #include "KeyPad.h"
 #include "Sensors.h"
 #include "Motor.h"
 #include "EEPROM.h"
 #include "EEPROM_Services.h"
 #define RED_LED         PIND7
 #define ORANGE_LED      PIND6 
 void print (u16 temp,u16 smoke);
 void Change_Password (void);
 void Show_Password(void);
 u16 password=0,Password_Adress=0,Ubdate_passwordAdress=1000,temp=0,smoke=0,Enter_Password_Flag_Adress=1001,First_Used_Adress=1002;
 u8 Enter_Password_Flag=0,Interrupt_flag=0;
int main(void)
{
	sei();
	DIO_init();
	LCD_init();
	ADC_init(ADC_VCC,ADC_SCAler_64);
	EXI_Enable(EX_INT0);
	EXI_Trigger(EX_INT0,FALLING_EDGE);
	EXI_SetCallBack(EX_INT0,Change_Password);
	u16 num=0,num2=0;
    u8 flag=0,k,count=0,Password_flag=0,o=0,s;
	
	if (EEPROM_Read(First_Used_Adress)==255)
	{
		LCD_GoTo(0,0);
		LCD_WriteString("First Used ");
		LCD_GoTo(1,0);
		LCD_WriteString("Set Password");
		_delay_ms(1000);
		LCD_Clear();
		LCD_WriteString("password");
		LCD_GoTo(1,0);
		while (count<4)
		{
			s=KEYPAD_GetKey();
			if (s!=NO_KEY)
			{
				
				if (s<='9'&& s>='0')
				{
					num2=num2*10+(s-'0');
					LCD_GoTo(1,0+count);
					LCD_WriteChar(s);
					_delay_ms(300);
					LCD_GoTo(1,0+count);
					LCD_WriteChar('*');
					count++;
				}
			}
		}
		password=num2;
		EEPROM_Write(First_Used_Adress,1);
		EEPROM_Write(Ubdate_passwordAdress,0);
		count=0;
		num2=0;
	}
	
	 if (EEPROM_Read(Ubdate_passwordAdress)==0)
	{
		EEPROM_WritePassword_4Number(Password_Adress,password);
		EEPROM_Write(Ubdate_passwordAdress,1);
	}
	else if (EEPROM_Read(Ubdate_passwordAdress)==1)
	{
		password=EEPROM_ReadPassword_4Number(Password_Adress);
	}
	Enter_Password_Flag=EEPROM_Read(Enter_Password_Flag_Adress);
	
    while (1) 
    {
		temp=LM35_GetTemp();
		smoke=Smoke_GetRate();
		 if (temp>400 && temp<450&&Enter_Password_Flag!=0)
		{
			if (o==0)
			LCD_Clear();
			print ( temp, smoke);
			o++;
		}
		else if (temp<=400 && smoke<500 && flag==0 && Enter_Password_Flag!=0)
		{
			print ( temp, smoke);
			LCD_GoTo(1,17);
			LCD_WriteString("Fine");
			Stop ();
			DIO_WRitePin(ORANGE_LED,LOW);
		}
		else if (temp>=450&&smoke<500&&flag==0&&Enter_Password_Flag!=0)
		{
			Clock_Wise();
			DIO_WRitePin(ORANGE_LED,HIGH);
			print ( temp, smoke);
			LCD_GoTo(1,17);
			LCD_WriteString("Heat");
		}
		
		if (smoke>550||flag==1||Enter_Password_Flag==0)
		{
			EEPROM_Write(Enter_Password_Flag_Adress,0);
			cli();
			if (Enter_Password_Flag!=0)
			{
				Clock_Wise();
				DIO_WRitePin(RED_LED,HIGH);
				DIO_WRitePin(ORANGE_LED,LOW);
				flag=1;
				LCD_Clear();
				LCD_GoTo(1,10);
				LCD_WriteString("System is Shut Down");
				_delay_ms(1000);
				print ( temp, smoke);
			}
			else
			{
				LCD_Clear();
				LCD_GoTo(1,10);
				LCD_WriteString("System is Shut Down");
				_delay_ms(1000);
				flag=1;
			}
			while (flag==1)
			{
				temp=LM35_GetTemp();
				smoke=Smoke_GetRate();
				print ( temp, smoke);
				if (smoke<500||Password_flag==1)
				{
					Stop();
					DIO_WRitePin(RED_LED,LOW);
					if (Password_flag==0)
					{
						LCD_Clear();
						LCD_GoTo(0,12);
						LCD_WriteString("**Enter your Passwad**");
						Password_flag=1;	
					}
					if (Interrupt_flag==1)
					{
						password=EEPROM_ReadPassword_4Number(Password_Adress);
						Interrupt_flag=0; 
					}
					while(count<4)
					{
						
						k=KEYPAD_GetKey();
						if (k!=NO_KEY)
						{
							if (k<='9'&&k>='0')
							{
								num=num*10+(k-'0');
								LCD_GoTo(1,13+count);
								LCD_WriteChar(k);
								_delay_ms(300);
								LCD_GoTo(1,13+count);
								LCD_WriteChar('*');
								count++;
							}
							
						}
					}
				}
				if (num==password)
				{
					LCD_Clear();
					flag=0;
					num=0;
					Password_flag=0;
					count=0;
					sei();
					EEPROM_Write(Enter_Password_Flag_Adress,1);
					Enter_Password_Flag=1;
				}
				else if (count==4)
				{
					LCD_Clear();
					LCD_GoTo(0,12);
					LCD_WriteString("Wrong Password");
					_delay_ms(1000);
					count=0;
					Password_flag=0;
					num=0;
				}
			}
		}	
    }
}

 void print (u16 temp,u16 smoke)
 {
	 LCD_GoTo(0,0);
	 LCD_WriteString("Temperature");
	 LCD_GoTo(0,35);
	 LCD_WriteString("Smoke");
	 LCD_GoTo(1,0);
	 LCD_WriteNumber(temp/10);
	 LCD_WriteChar('.');
	 LCD_WriteNumber(temp%10);
	 LCD_GoTo(1,35);
	 LCD_WriteNumber(smoke/10);
	 LCD_WriteChar('.');
	 LCD_WriteNumber(smoke%10);
 }
 
 void Change_Password (void)
 {
	 u8 m,count=0,count2=3,f=0;
	 u16 num=0;
	 LCD_Clear();
	 LCD_GoTo(0,5);
	 LCD_WriteString("Please Write The Old Password");
	LCD_GoTo(1,0);
	LCD_WriteNumber(count2);
	 while (count2>0)
	 {
		 while (count<4)
		 {
			 m=KEYPAD_GetKey();
			 if (m!=NO_KEY)
			 {
				 if (m<='9'&&m>='0')
				 {
					 LCD_GoTo(1,16+count);
					 LCD_WriteChar(m);
					 _delay_ms(300);
					 LCD_GoTo(1,16+count);
					 LCD_WriteChar('*');
					 num=num*10+(m-'0');
					 count++;
				 }
			 }
		  }
		 if (password==num)
		 {
			 f=1;
			 count=0;
			 num=0;
			 break;
		 }
		 else
		 {
			LCD_Clear();
			_delay_ms(500);
			LCD_GoTo(0,12);
			LCD_WriteString("Wrong Password");
			_delay_ms(1000);
			LCD_GoTo(0,5);
			LCD_WriteString("Please Write The Old Password");
			LCD_GoTo(1,0);
			count2--; 
			LCD_WriteNumber(count2);
			count=0;
			num=0;
		 }
	 }
	 if (f==1)
	 {
		 f=0;
		 LCD_Clear();
		 LCD_GoTo(0,5);
		 LCD_WriteString("Please Write The New Password");
		 _delay_ms(500);
		Interrupt_flag=1;
		EEPROM_Write(Ubdate_passwordAdress,1);
		while (count<4)
		{
			m=KEYPAD_GetKey();
			if (m!=NO_KEY)
			{
				
				if (m<='9'&&m>='0')
				{
					LCD_GoTo(1,16+count);
					LCD_WriteChar(m);
					_delay_ms(300);
					LCD_GoTo(1,16+count);
					LCD_WriteChar('*');
					num=num*10+(m-'0');
					count++;
				}
			}
		}
		EEPROM_WritePassword_4Number(Password_Adress,num);
		LCD_Clear();
		print(temp,smoke);
	 } 
	 else 
	 {
	 LCD_Clear();
	 _delay_ms(500);
	 LCD_GoTo(0,5);
	 LCD_WriteString("You Can't Change The Password");
	 _delay_ms(1000);
	 LCD_Clear();
	 print(temp,smoke);
	 }
 }
 