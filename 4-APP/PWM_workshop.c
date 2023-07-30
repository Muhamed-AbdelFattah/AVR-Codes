/*********************************************
 * Author:				AbdelFattah
 * Creation Data:		15 May, 2023
 * Version:				v1.0
 * Compiler:			GNU AVR-GCC
 * Controller:			ATmega32 (8-bit Architecture)
 * Layer:				APP
 ********************************************/
#include "../3-LIB/BIT_MATH.h"
#include "../3-LIB/STD_TYPES.h"
#include "../2-HAL/2-LCD/LCD_interface.h"
#include "../2-HAL/3-KeyPad/KPD_interface.h"
#include "../2-HAL/5-LM35_Driver/LM35_interface.h"
#include "../2-HAL/6-LDR_Driver/LDR_interface.h"
#include "../2-HAL/7-Servo_Driver/Servo_interface.h"
#include "../1-MCAL/1-DIO/DIO_interface.h"
#include "../1-MCAL/3-ADC/ADC_interface.h"
#include "../1-MCAL/6-Timers/Timer_interface.h"
#include "../1-MCAL/2-Exti_Interrupt/EXTI_interface.h"
#include "../1-MCAL/5-GLOBAL_interrupt/Global_Interrupt_interface.h"

u8 Local_u8Counter = 0;
u8 Local_u8Password;
u16 Local_u8LDReading = 0;
u16 Local_u8LM35Reading = 0;
void main(void)
{

    /*OCO to make PWM Signal*/
    DIO_SetPinDirection(PORT_B, PIN_3, PIN_OUTPUT);
    /*TIMER 0 initialize at Fast PWM Signal*/
    TIM0_voidInitialize();
    ADC_voidInit();
    LM35_voidInit(PIN_1);
    LDR_voitInit(PIN_0);
    LCD_vidInit();
    LCD_vidSendCommand(lcd_Clear);

    while (1)
    {
        /* Reading From LM35*/
        Local_u8LM35Reading = LM35_u16LM35Reading(Channel_A1);
        Gotoxy(0, 0);
        LCD_vidWriteString("Temp:", 4);
        Gotoxy(0, 5);
        LCD_voidwriteNumber(Local_u8LM35Reading);
        if (Local_u8LM35Reading >= 30)
        {
            /*Generate ON Time 20 usec*/
            TIM0_voidSetCompareVal(20);
        }
        else if (Local_u8LM35Reading < 30)
        {
            /*Generate ON Time 50 usec*/
            TIM0_voidSetCompareVal(50);
        }

        /*Reading From LDR*/
        Local_u8LDReading = LDR_u16LDRReading(Channel_A0);
        if (Local_u8LDReading == 0)
        {
            /*Generate ON Time 100 usec*/
            TIM0_voidSetCompareVal(100);
        }
		else if((Local_u8LDReading>1000) && (Local_u8LDReading<1700))
		{
            /*Generate ON Time 120 usec*/
            TIM0_voidSetCompareVal(120);
			
		}
		else if((Local_u8LDReading>1700)&&(Local_u8LDReading<2600))
		{
			/*Generate ON Time 140 usec*/
            TIM0_voidSetCompareVal(140);

		}
		else if((Local_u8LDReading>2600)&&(Local_u8LDReading<3400))
		{
			/*Generate ON Time 160 usec*/
            TIM0_voidSetCompareVal(160);

		}
		else if((Local_u8LDReading>3400)&&(Local_u8LDReading<4200))
		{
			/*Generate ON Time 180 usec*/
            TIM0_voidSetCompareVal(180);
		}
		else if((Local_u8LDReading>4200)&&(Local_u8LDReading<4600))
		{
			/*Generate ON Time 200 usec*/
            TIM0_voidSetCompareVal(200);
		}
		else if((Local_u8LDReading>4600))
		{
			/*Generate ON Time 220 usec*/
            TIM0_voidSetCompareVal(220);
		}
    }
}
