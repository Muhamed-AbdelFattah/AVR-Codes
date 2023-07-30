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
#include "util/delay.h"
#include "Keypad_interface.h"
#include "ADC_interface.h"
#include "EXTI_interface.h"
#include "Global_Interrupt_interface.h"
#include "Timer_interface.h"
#include "WDG_interface.h"
#define F_CPU 8000000

volatile u16 PeriodTicks=0;
volatile u16 OnTicks=0;
volatile u16 PeriodTicks_1=0;
volatile u16 OnTicks_1=0;
void ICU_HW(void);
void ICU_SW(void);

void main(void){
	DIO_SetPinDirection(PORT_B,PIN_3,PIN_OUTPUT);
	DIO_SetPinValue(PORT_B,PIN_3,PIN_LOW);
	DIO_SetPinDirection(PORT_D,PIN_2,PIN_INPUT);
	DIO_SetPinValue(PORT_D,PIN_2,PIN_LOW);
	LCD_vidInit();
	TIM1_voidInitialize();
	TIM0_voidInitialize();
	EXT0_VID_SET_CALL_BACK(&ICU_HW);
	while(1)
	{
		while((PeriodTicks_1 ==0) && (OnTicks_1  == 0));
		Gotoxy(0,0);
		//LCD_vidWriteString("P.T=",4);
		//LCD_voidwriteNumber(PeriodTicks_1);
		Gotoxy(1,0);
		//LCD_vidWriteString("O.T=",15);
		//LCD_voidwriteNumber(OnTicks_1);
	}
}

void ICU_HW(void)
{
	static u16 Reading1,Reading2,Reading3;
	static u8 Local_u8Counter=0;
	Local_u8Counter++;
	if(Local_u8Counter ==1)
	{
		Reading1= ICU_u16ReadInputCapture();

	}
	else if (Local_u8Counter==2)
	{
		Reading2=ICU_u16ReadInputCapture();
		PeriodTicks=Reading2-Reading1;
		ICU_u8SetTriggerEdge(ICU_FALLING_EDGE);
	}
	else if (Local_u8Counter==3)
	{
		Reading3= ICU_u16ReadInputCapture();
		OnTicks=Reading3-Reading2;
		ICU_voidDisableInterrupt();
	}
}
void ICU_SW(void)
{
	static u8 Local_u8Counter1=0;
	Local_u8Counter1++;
	if (Local_u8Counter1 == 1)
	{
		/*First Rising Edge*/
		Timer1_voidSetTimerValue(0);
	}
	else if (Local_u8Counter1 ==2)
	{
		/*Period Ticks on Pos 2*/
		PeriodTicks_1=Timer1_u16ReadingTimerValue();
		EXT_INTERRUPT_VID_SET_MODE(EXT0,FALLING_EDGE);
	}
	else if (Local_u8Counter1 == 3)
	{
		/*Onticks on Pos 3  */
		OnTicks_1=Timer1_u16ReadingTimerValue();
		OnTicks_1=OnTicks_1-PeriodTicks_1;
		EXT_INTERRUPT_VID_DISABLE(EXT0);
	}

}




