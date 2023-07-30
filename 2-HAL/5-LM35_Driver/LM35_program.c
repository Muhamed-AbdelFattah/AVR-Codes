/*********************************************
 * Author:				AbdelFattah
 * Creation Data:		15 May, 2023
 * Version:				v1.0
 * Compiler:			GNU AVR-GCC
 * Controller:			ATmega32 (8-bit Architecture)
 * Layer:				HAL
 ********************************************/
#include "../../3-LIB/BIT_MATH.h"
#include "../../3-LIB/STD_TYPES.h"
#include "LM35_interface.h"
#include "LM35_config.h"
#include "../../1-MCAL/1-DIO/DIO_interface.h"

void LM35_voidInit(u8 Copy_u8LM35Pin)
{
    DIO_SetPinValue(LM35_PORT, Copy_u8LM35Pin, PIN_INPUT);
}
u16 LM35_u16LM35Reading(u8 Copy_u8LM35Channel)
{
    u16 LM35_u16Reading = 0;
    u16 LM35_u16Volt = 0;
    u16 LM35_u16TempData = 0;
    LM35_u16Reading = ADC_u16Startsynch(Copy_u8LM35Channel);
    LM35_u16Volt = (u16)(((u32)LM35_u16Reading * 5000UL) / 1024UL);
    LM35_u16TempData = LM35_u16Volt / 10;

    return (LM35_u16TempData);
}
