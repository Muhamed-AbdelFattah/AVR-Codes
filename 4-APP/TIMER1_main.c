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

void main(void){
	DIO_SetPinDirection(PORT_D,PIN_6,PIN_INPUT);
	DIO_SetPinValue(PORT_D,PIN_6,PIN_LOW);
	TIM1_voidInitialize();
	ICU_voidInit();

	ADC_Init();

	u16 Local_u16Reading=0;
	u16 Local_u16Maping=0;
	while(1)
	{
			Local_u16Reading=ADC_Read(Channel_A0);
			Local_u16Maping=750+Local_u16Reading*((2500-750)/255);
			TIM1_A_voidSetCompareVal(Local_u16Maping);

	}
}


