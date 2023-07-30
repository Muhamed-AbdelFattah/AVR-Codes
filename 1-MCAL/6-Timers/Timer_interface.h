/*********************************************
 * Author:				AbdelFattah
 * Creation Data:		16 May, 2023
 * Version:				v1.0
 * Compiler:			GNU AVR-GCC
 * Controller:			ATmega32 (8-bit Architecture)
 * Layer:				MCAL
 ********************************************/

#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

#define ICU_FALLING_EDGE 0
#define ICU_RISING_EDGE 1

#define Sec    	    1
#define MilliSec    2
#define MicroSec	3



/*Clock Select Prescaler*/
#define NO_CLOCK    0
#define DIV_1       1
#define DIV_8		2
#define DIV_32		3
#define DIV_64		4
#define DIV_128		5
#define DIV_256		6
#define DIV_1024	7

void TIM0_voidInitialize(void);

void TIM0_voidSetTimerReg(u8 Copy_u8Value);

void TIM0_voidSetCompareVal(u8 Copy_u8Value);


void TIM0_voidEnableOVINT(void);

void TIM0_voidDisableOVINT(void);

void TIM0_voidEnableCTCINT(void);

void TIM0_voidDisableCTCINT(void);
void TIM0_voidDisablePWM(void);
void TIM0_voidEnablePWM(void);
/*
void TIM1_voidEnableCTCAINT(void);

void TIM1_voidDisableCTCAINT(void);

void TIM1_voidEnableCTCBINT(void);

void TIM1_voidDisableCTCBINT(void);

void TIM1_voidEnableICUINT(void);

void TIM1_voidDisableICUINT(void);
*/
u8 TIM0_u8GETCounter(void);

void TIM0_voidSetOVCallback( void (*callback_Copy_ptr) (void) );

void TIM0_voidSetCTCCallback( void (*callback_Copy_ptr) (void) );

void TIM1_voidInitialize(void);

void Timer1_voidSetTimerValue(u16 Copy_u16Value);

u16 Timer1_u16ReadingTimerValue(void);

void TIM1_voidSetTimerICR(u16 Copy_u16Value);

void TIM1_A_voidSetCompareVal(u16 Copy_u16Value);

void TIM1_B_voidSetCompareVal(u16 Copy_u16Value);
/*
void TIM1_voidEnableOVINT(void);

void TIM1_voidDisableOVINT(void);

void TIM1_voidEnableCTCINT(void);

void TIM1_voidDisableCTCINT(void);

u16 TIM1_u16GETCounter(void);

u16 TIM1_u16GETICUValue(void);

void TIM1_voidSetICUEdge(u16 Copy_u8edge);
*/
void TIM1_voidSetOVCallback( void (*callback_Copy_ptr) (void) );

void TIM1_voidSetCTCACallback( void (*callback_Copy_ptr) (void) );

void TIM1_voidSetCTCBCallback( void (*callback_Copy_ptr) (void) );

void ICU_voidInit(void);

u8 ICU_u8SetTriggerEdge(u8 Copy_u8Edge);

void ICU_voidEnableInterrupt(void);

void ICU_voidDisableInterrupt(void);

u16 ICU_u16ReadInputCapture(void);

u8 ICU_u8SetCallBack(void (*Copy_pvCallBackFunc)(void));

void TIM2_VoidSetBusyWait(u32 Copy_u32Delay,u8 Copy_u8Unit);

void TIM2_voidSetCompareVal(u8 Copy_u8Value);

void TIM2_voidSetPrescaler(void);

void TIM2_voidInit(void);

void TIM2_voidSetOVCallback( void (*callback_Copy_ptr) (void) );

void TIM2_voidSetCTCCallback( void (*callback_Copy_ptr) (void) );



#endif /* TIMER_INTERFACE_H_ */
