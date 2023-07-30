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
#include "Timer_interface.h"
#include "Timer_register.h"
#include "TIMER_config.h"


static void (*OVF_0_callback)(void)=NULL;
static void (*CTC_0_callback)(void)=NULL;

static void (*OVF_2_callback)(void)=NULL;
static void (*CTC_2_callback)(void)=NULL;
/*static void (*CTC_1_callback)(void)=NULL;
 static void (*CTC_1_A_callback)(void)=NULL;
static void (*CTC_1_B_callback)(void)=NULL;*/
static void (*ICU_pvCallBackFunc)(void)=NULL;
void TIM0_voidInitialize(void){
	/* Fast PWM Mode */
	SET_BIT(TCCR0_Register,TCCR0_WGM01);
	SET_BIT(TCCR0_Register,TCCR0_WGM00);

	/* Clear On Compare , Set On Top*/
	SET_BIT(TCCR0_Register,TCCR0_COMP01);
	CLR_BIT(TCCR0_Register,TCCR0_COMP00);
	
	/* Init Prescaler 8 Bit*/
	TIM0_voidSetPrescaler();
}
void TIM0_voidDisablePWM(void)
{
	CLR_BIT(TCCR0_Register,TCCR0_WGM01);

}
void TIM0_voidEnablePWM(void)
{
	SET_BIT(TCCR0_Register,TCCR0_WGM01);

}
void TIM0_voidSetPrescaler(void)
{
#if 	TIMER0_Prescaler==DIV_1
	TCCR0_Register&=PRESCALER_MASKING;
	TCCR0_Register|=DIV_1;
#elif  TIMER0_Prescaler==DIV_8
	TCCR0_Register&=PRESCALER_MASKING;
	TCCR0_Register|=DIV_8;
#elif	TIMER0_Prescaler==DIV_64
	TCCR0_Register&=PRESCALER_MASKING;
	TCCR0_Register|=DIV_64;
#elif	TIMER0_Prescaler==DIV_128
	TCCR0_Register&=PRESCALER_MASKING;
	TCCR0_Register|=DIV_128;
#elif	TIMER0_Prescaler==DIV_256
	TCCR0_Register&=PRESCALER_MASKING;
	TCCR0_Register|=DIV_256;
#elif	TIMER0_Prescaler==DIV_1024
	TCCR0_Register&=PRESCALER_MASKING;
	TCCR0_Register|=DIV_1024;
#else
#endif
}
void TIM0_voidSetTimerReg(u8 Copy_u8Value){
	TCNT0_Register=Copy_u8Value;

}

void TIM0_voidSetCompareVal(u8 Copy_u8Value){
	OCR0_Register=Copy_u8Value;

}

void TIM0_voidEnableOVINT(void){
	SET_BIT(TIMSK_Register,0);
}

void TIM0_voidDisableOVINT(void){
	CLR_BIT(TIMSK_Register,0);
}

void TIM0_voidEnableCTCINT(void){

	SET_BIT(TIMSK_Register,1);
}

void TIM0_voidDisableCTCINT(void){
	CLR_BIT(TIMSK_Register,1);
}

u8 TIM0_u8GETCounter(void){
	return(TCNT0_Register);
}

void TIM0_voidSetOVCallback( void (*callback_Copy_ptr) (void) ){
	OVF_0_callback=callback_Copy_ptr;
}

void TIM0_voidSetCTCCallback( void (*callback_Copy_ptr) (void) ){
	CTC_0_callback=callback_Copy_ptr;
}


void __vector_10(void) __attribute__ ((signal,used, externally_visible)) ; \
void __vector_10 (void){
	if(OVF_0_callback !=NULL)
	{
		OVF_0_callback();
	}
	else
	{
		/*No thing*/
	}
}
void __vector_11(void) __attribute__ ((signal,used, externally_visible)) ; \
void __vector_11 (void){
	if(CTC_0_callback !=NULL)
	{
		CTC_0_callback();
	}
	else
	{
		/*No thing*/
	}
}
////
void TIM1_voidInitialize(void){

	/*Setting Compare Match Fast PWM , Mode 14*/
	CLR_BIT(TCCR1A_Register,TCCR1A_WGM10);
	CLR_BIT(TCCR1A_Register,TCCR1A_WGM11);
	CLR_BIT(TCCR1B_Register,TCCR1B_WGM12);
	CLR_BIT(TCCR1B_Register,TCCR1B_WGM13);

	/*Setting Compare Match Fast PWM */
		SET_BIT(TCCR1A_Register,TCCR1A_COMP1A1);
		CLR_BIT(TCCR1A_Register,TCCR1A_COMP1A0);


	/*Setting of Prescaler */
	TCCR1B_Register&=PRESCALER_MASKING;
	TCCR1B_Register|=DIV_8;

	/*init Normal Mode at Prescaler 8*/
	/*CLR_BIT(TCCR1B_Register,TCCR1B_CS10);
	SET_BIT(TCCR1B_Register,TCCR1B_CS11);
	CLR_BIT(TCCR1B_Register,TCCR1B_CS12);*/
}
void Timer1_voidSetTimerValue(u16 Copy_u16Value)
{
	TCNT1_Register=Copy_u16Value;
}
u16 Timer1_u16ReadingTimerValue(void)
{
	return TCNT1_Register;
}

void TIM1_voidSetTimerICR(u16 Copy_u16Value){
	ICR1_Register=Copy_u16Value;
}
void TIM1_A_voidSetCompareVal(u16 Copy_u16Value){
	OCR1A_Register=Copy_u16Value;
}

////
void ICU_voidInit(void)
{
	/*Set Trigger Source to Rising Egde */
	SET_BIT(TCCR1B_Register,TCCR1B_ICES1);
}
u8 ICU_u8SetTriggerEdge(u8 Copy_u8Edge){

	u8 Local_u8ErrorStatus=1;
	if(Copy_u8Edge== ICU_RISING_EDGE)
	{
		SET_BIT(TIMSK_Register,TIMSK_TICIE1);
	}
	else if(Copy_u8Edge==ICU_FALLING_EDGE)
	{
		CLR_BIT(TIMSK_Register,TIMSK_TICIE1);
	}
	else
	{
		Local_u8ErrorStatus=NOK;
	}
	return (Local_u8ErrorStatus);
}
void ICU_voidEnableInterrupt(void)
{
	SET_BIT(TIMSK_Register,TIMSK_TICIE1);
}

void ICU_voidDisableInterrupt(void)
{
	CLR_BIT(TIMSK_Register,TIMSK_TICIE1);
}

u16 ICU_u16ReadInputCapture(void){
	return(ICR1_Register);
}

u8 ICU_u8SetCallBack(void (*Copy_pvCallBackFunc)(void))
{
	u8 Local_u8ErrorState=OK;
	if(Copy_pvCallBackFunc != NULL)
	{
		ICU_pvCallBackFunc=Copy_pvCallBackFunc;
	}
	else
	{
		Local_u8ErrorState=NOK;
	}
	return Local_u8ErrorState;
}

void __vector_6 (void) __attribute__((signal));
void __vector_6 (void)
{
	if(ICU_pvCallBackFunc != NULL)
	{
		ICU_pvCallBackFunc();
	}
}

///
void TIM2_voidInit(void)
{
	/*Waveform Generation Mode CTC*/
	CLR_BIT(TCCR2_Register,TCCR2_WGM20);
	SET_BIT(TCCR2_Register,TCCR2_WGM21);
	/*Prescalaer init div 8 */
	TIM2_voidSetPrescaler();

}
void TIM2_VoidSetBusyWait(u32 Copy_u32Delay,u8 Copy_u8Unit)
{
	u32 Local_u32Counter=0;
	switch(Copy_u8Unit)
	{
	case Sec:
		/*Set Prescaler is 1*/
		TCCR2_Register&=PRESCALER_MASKING;
		TCCR2_Register|=DIV_1;
		/*Put Output Compare Register*/
		OCR2_Register=8;
		while(Local_u32Counter<=Copy_u32Delay)
		{
			while(TIFR_OCF2==0);
			Local_u32Counter++;
			SET_BIT(TIFR_Register,TIFR_OCF2);
		}
		break;
	case MilliSec:
		/*Set Prescaler is 32 */
		TCCR2_Register&=PRESCALER_MASKING;
		TCCR2_Register|=DIV_32;
		/*Put Output Compare Register*/
		OCR2_Register=250;
		while(Local_u32Counter<=Copy_u32Delay)
		{
			while(TIFR_OCF2==0);
			Local_u32Counter++;
			SET_BIT(TIFR_Register,TIFR_OCF2);
		}
		break;
	case MicroSec:

		/*Set Prescaler is 8 */
		TCCR2_Register&=PRESCALER_MASKING;
		TCCR2_Register|=DIV_8;
		/*Put Output Compare Register*/
		OCR2_Register=1;
		while(Local_u32Counter<=Copy_u32Delay)
		{
			while(TIFR_OCF2==0);
			Local_u32Counter++;
			SET_BIT(TIFR_Register,TIFR_OCF2);
		}
		break;
	}
}
void TIM2_voidSetPrescaler(void)
{
#if 	TIMER2_Prescaler==DIV_1
	TCCR2_Register&=PRESCALER_MASKING;
	TCCR2_Register|=DIV_1;
#elif  TIMER2_Prescaler==DIV_8
	TCCR2_Register&=PRESCALER_MASKING;
	TCCR2_Register|=DIV_8;
#elif	TIMER2_Prescaler==DIV_64
	TCCR2_Register&=PRESCALER_MASKING;
	TCCR2_Register|=DIV_64;
#elif	TIMER2_Prescaler==DIV_128
	TCCR2_Register&=PRESCALER_MASKING;
	TCCR2_Register|=DIV_128;
#elif	TIMER2_Prescaler==DIV_256
	TCCR2_Register&=PRESCALER_MASKING;
	TCCR2_Register|=DIV_256;
#elif	TIMER2_Prescaler==DIV_1024
	TCCR2_Register&=PRESCALER_MASKING;
	TCCR2_Register|=DIV_1024;
#else
#endif
}
void TIM2_voidSetCompareVal(u8 Copy_u8Value){
	OCR2_Register=Copy_u8Value;
}
void TIM2_voidSetOVCallback( void (*callback_Copy_ptr) (void) ){
	OVF_2_callback=callback_Copy_ptr;
}

void TIM2_voidSetCTCCallback( void (*callback_Copy_ptr) (void) ){
	CTC_2_callback=callback_Copy_ptr;
}
void __vector_5(void) __attribute__ ((signal,used, externally_visible)) ; \
void __vector_5 (void){
	if(OVF_2_callback !=NULL)
	{
		OVF_2_callback();
	}
	else
	{
		/*No thing*/
	}
}
void __vector_4(void) __attribute__ ((signal,used, externally_visible)) ; \
void __vector_4 (void){
	if(CTC_2_callback !=NULL)
	{
		CTC_2_callback();
	}
	else
	{
		/*No thing*/
	}
}

