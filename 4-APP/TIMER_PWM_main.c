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
#include "Global_Interrupt_interface.h"
#include "Timer_interface.h"
#include "WDG_interface.h"
#define F_CPU 8000000
void PWM(void);


void main(void){
	DIO_SetPinDirection(PORT_A,PIN_0,PIN_OUTPUT);
	DIO_SetPinValue(PORT_A,PIN_0,PIN_HIGH);
	Global_Interrupt_Enable();
	TIM0_voidInitialize();
	TIM0_voidSetCompareVal(125);
	TIM0_voidSetOVCallback(&PWM);
	while(1)
	{

	}
}
void PWM(void)
{
	static u8 Local_u8Counter=0;
	Local_u8Counter++;
	if(Local_u8Counter==5)
	{
		DIO_SetPinValue(PORT_A,PIN_0,PIN_LOW);

	}
	else if(Local_u8Counter==20)
	{
		DIO_SetPinValue(PORT_A,PIN_0,PIN_HIGH);
		Local_u8Counter=0;
	}
}


