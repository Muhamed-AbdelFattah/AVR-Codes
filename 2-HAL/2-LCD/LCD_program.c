/**************************************************************/
/**************************************************************/
/*************    Author: Muhamed AbdelFattah    **************/
/*************    Layer: HAL                     **************/
/*************    SWC:LCD                         *************/
/**************************************************************/
/**************************************************************/
#include "../../3-LIB/STD_TYPES.h"
#include "../../3-LIB/BIT_MATH.h"
#include "../../1-MCAL/1-DIO/DIO_interface.h"
#include "LCD_interface.h"

#include "util/delay.h"
#define F_CPU 8000000


void LCD_vidInit(void){
	DIO_SetPortDirection(lcd_DATAPORT,PORT_OUTPUT);

	DIO_SetPinDirection(lcd_CONTROLPORT,lcd_RSPIN,PIN_OUTPUT);
	DIO_SetPinDirection(lcd_CONTROLPORT,lcd_RWPIN,PIN_OUTPUT);
	DIO_SetPinDirection(lcd_CONTROLPORT,lcd_EPIN,PIN_OUTPUT);

	DIO_SetPinValue(lcd_CONTROLPORT,lcd_EPIN,PIN_LOW);

	_delay_ms(30);
	LCD_vidSendCommand(lcd_Home);
	_delay_ms(1);
	LCD_vidSendCommand(lcd_FunctionSet8bit);
	_delay_ms(1);
	LCD_vidSendCommand(lcd_DisplayOn);
	_delay_ms(1);
	LCD_vidSendCommand(lcd_Clear);
	_delay_ms(1);
	LCD_vidSendCommand(lcd_EntryMode);
	_delay_ms(1);
}
void LCD_vidSendCommand(u8 u8CmdCpy){
	DIO_SetPinValue(lcd_CONTROLPORT,lcd_RSPIN,PIN_LOW);
	DIO_SetPinValue(lcd_CONTROLPORT,lcd_RWPIN,PIN_LOW);
	DIO_SetPinValue(lcd_CONTROLPORT,lcd_EPIN,PIN_LOW);

	DIO_SetPortValue(lcd_DATAPORT,u8CmdCpy);
	DIO_SetPinValue(lcd_CONTROLPORT,lcd_EPIN,PIN_HIGH);
	_delay_ms(5);
	DIO_SetPinValue(lcd_CONTROLPORT,lcd_EPIN,PIN_LOW);
}
void LCD_vidWriteCharctr(u8 u8DataCpy){
	DIO_SetPinValue(lcd_CONTROLPORT,lcd_RSPIN,PIN_HIGH);
	DIO_SetPinValue(lcd_CONTROLPORT,lcd_RWPIN,PIN_LOW);
	DIO_SetPinValue(lcd_CONTROLPORT,lcd_EPIN,PIN_LOW);

	DIO_SetPortValue(lcd_DATAPORT,u8DataCpy);
	DIO_SetPinValue(lcd_CONTROLPORT,lcd_EPIN,PIN_HIGH);
	_delay_ms(5);
	DIO_SetPinValue(lcd_CONTROLPORT,lcd_EPIN,PIN_LOW);

}
void LCD_vidWriteString (u8* pu8StringCpy, u8 u8Index){
	u8 i=0;
	for(i=0;i<u8Index;i++)
	{
		LCD_vidWriteCharctr(pu8StringCpy[i]);
		_delay_ms(5);
	}
}
	void LCD_vidWriteString_1 (u8* pu8StringCpy, u8 u8Index,u8 u8Y,u8 u8X){
		u8 i=0,x=0;
		Gotoxy(u8Y,u8X);
		x=u8X;
		for(i=0;i<u8Index;i++)
		{

			if(x==15 ){
				Gotoxy(1,0);
			}
			x++;
			LCD_vidWriteCharctr(pu8StringCpy[i]);
			_delay_ms(5);
		}

	}
	void Gotoxy (u8 u8Y,u8 u8X){

		u8 u8Adress;
		if(u8Y<2 && u8X<=16)
		{
			u8Adress=((u8Y*0x40)+u8X);
			//u8Adress=SET_BIT(u8Adress,7);
			LCD_vidSendCommand(u8Adress+128);

		}

	}
	void LCD_vidWriteExtraChar (u8 u8Y,u8 u8X,u8 *Copy_Pu8Pattern,u8 Copy_u8PatternNumber)
	{
		u8 Local_u8CGRAMAdress=0,Local_u8Iterator=0;

		Local_u8CGRAMAdress=Copy_u8PatternNumber*8;

		LCD_vidSendCommand(Local_u8CGRAMAdress+64);


		for(Local_u8Iterator=0;Local_u8Iterator<8;Local_u8Iterator++){
			LCD_vidWriteCharctr(Copy_Pu8Pattern[Local_u8Iterator]);
		}
		Gotoxy(u8Y,u8X);


		for(Local_u8Iterator=0;Local_u8Iterator<8;Local_u8Iterator++){
			LCD_vidWriteCharctr(Local_u8Iterator);

		}
	}

void LCD_voidwriteNumber(u32 Copy_u32Number)
{
	u8 Local_u8ArrayNumber[10];
	s8 Local_s8Counter=0;      // Signed as to become Negative  BACK to 255
	while(Copy_u32Number != 0)
	{
		Local_u8ArrayNumber[Local_s8Counter]=Copy_u32Number%10;
		Copy_u32Number/=10;
		Local_s8Counter++;
	}
	Local_s8Counter--;
	while(Local_s8Counter >= 0)
	{
		LCD_vidWriteCharctr(Local_u8ArrayNumber[Local_s8Counter]+'0');
		Local_s8Counter--;
	}
}
