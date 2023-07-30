/*********************************************
 * Author:				AbdelFattah
 * Creation Data:		15 May, 2023
 * Version:				v1.0
 * Compiler:			GNU AVR-GCC
 * Controller:			ATmega32 (8-bit Architecture)
 * Layer:				HAL
 ********************************************/

#ifndef LM35_INTERFACE_H_
#define LM35_INTERFACE_H_

void LM35_voidInit(u8 Copy_u8LM35Pin);
u16 LM35_u16LM35Reading(u8 Copy_u8LM35Channel);




#endif