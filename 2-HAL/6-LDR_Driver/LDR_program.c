/*********************************************
 * Author:				AbdelFattah
 * Creation Data:		15 May, 2023
 * Version:				v1.0
 * Compiler:			GNU AVR-GCC
 * Controller:			ATmega32 (8-bit Architecture)
 * Layer:				HAL
 ********************************************/

#include "../../3-LIB/STD_TYPES.h"
#include "../../3-LIB/BIT_MATH.h"
#include "../../1-MCAL/1-DIO/DIO_interface.h"
#include "../../1-MCAL/3-ADC/ADC_interface.h"
#include "LDR_interface.h"

void LDR_voitInit(u8 Copy_u8LDRPin)
{
    DIO_SetPinDirection(PORT_A, Copy_u8LDRPin, PIN_INPUT);
}
u16 LDR_u16LDRReading(u8 Copy_u8LDRChannel)
{
    u16 LDR_u16Reading = 0;
    u16 LDR_u16Volt = 0;
    LDR_u16Reading = ADC_u16Startsynch(Copy_u8LDRChannel);
    LDR_u16Volt = (u16)(((u16)LDR_u16Reading * 5000UL) / 256UL);
    if (LDR_u16Volt < 1000)
    {
        return (0);
    }
    else
    {
        return (LDR_u16Volt);
    }
}
