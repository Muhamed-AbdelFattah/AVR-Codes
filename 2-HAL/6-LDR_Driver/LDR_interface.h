/*********************************************
 * Author:				AbdelFattah
 * Creation Data:		15 May, 2023
 * Version:				v1.0
 * Compiler:			GNU AVR-GCC
 * Controller:			ATmega32 (8-bit Architecture)
 * Layer:				HAL
 ********************************************/
#ifndef LDR_INTERCE_H_
#define LDR_INTERCE_H_

void LDR_voitInit(u8 Copy_u8LDRPin);
u16 LDR_u16LDRReading(u8 Copy_u8LDRChannel);


#endif