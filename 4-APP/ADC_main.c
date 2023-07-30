/**************************************************************/
/**************************************************************/
/*************    Author: Muhamed AbdelFattah    **************/
/*************    Layer: APP                     **************/
/**************************************************************/
/**************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "SEGMENT_interface.h"
#include "LCD_interface.h"
#include "LCD_extra.h"
#include "util/delay.h"
#include "Keypad_interface.h"
#include"ADC_interface.h"
#define F_CPU 8000000
void main(void){

	DIO_SetPinDirection(PORT_B,PIN_0,PIN_OUTPUT);
	//DIO_SetPinValue(PORT_B,PIN_0,PIN_HIGH);

	LCD_vidInit();
	DIO_SetPinDirection(PORT_A,PIN_0,PIN_INPUT);
	ADC_Init();
	u16 reading=0;
	u32 milli_volt=0;
	u32 temp=0;

	while(1)
	{
		reading =ADC_Read(Channel_A0);
		milli_volt=(((u32)reading)*5000/1024);

		if(milli_volt>=2500)
		{
			DIO_SetPinValue(PORT_B,PIN_0,PIN_HIGH);
			LCD_vidSendCommand(lcd_Clear);
			LCD_vidWriteString("High Temp",10);


		}
		else
		{
			DIO_SetPinValue(PORT_B,PIN_0,PIN_LOW);
			LCD_vidSendCommand(lcd_Clear);
			LCD_vidWriteString("Low Temp",15);
		}

		/*temp=milli_volt/10;
		//_delay_ms(1000);
		LCD_vidSendCommand(lcd_Clear);
		LCD_vidWriteString("Temp=",7);
		LCD_vidWriteCharctr((temp/100)+48);
		LCD_vidWriteCharctr(((temp%100)/10)+48);
		LCD_vidWriteCharctr(((temp%10))+48);
		//LCD_vidWriteCharctr(((temp%10)/100)+48);

		_delay_ms(500);*/


	}
}

