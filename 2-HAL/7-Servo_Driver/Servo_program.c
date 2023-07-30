/*********************************************
 * Author:				AbdelFattah
 * Creation Data:		16 May, 2023
 * Version:				v1.0
 * Compiler:			GNU AVR-GCC
 * Controller:			ATmega32 (8-bit Architecture)
 * Layer:				MCAL
 ********************************************/
#include "../../3-LIB/BIT_MATH.h"
#include "../../3-LIB/STD_TYPES.h"
#include "Servo_interface.h"
#include "../../1-MCAL/6-Timers/Timer_interface.h"
u16 Local_u16AngleValue=0;
void SERVO_voidRotate(u16 Copy_u16Angle){
Local_u16AngleValue=((u32)Copy_u16Angle*1900UL)/180UL;
TIM1_A_voidSetCompareVal(Local_u16AngleValue);
}

