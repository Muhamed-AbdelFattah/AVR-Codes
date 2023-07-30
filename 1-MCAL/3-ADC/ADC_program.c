/**************************************************************/
/**************************************************************/
/*************    Author: Muhamed AbdelFattah    **************/
/*************    Layer: MCAL                    **************/
/*************    SWC: ADC                       **************/
/**************************************************************/
/**************************************************************/
#include "../../3-LIB/STD_TYPES.h"
#include "../../3-LIB/BIT_MATH.h"
#include "ADC_interface.h"
#include "ADC_register.h"
#include "ADC_config.h"

void (*ADC_CALLBACK_PTR)(void)=NULL;
u16  ADC_u16Data=0;
void ADC_voidInit(void){

	/* ADC Prescaler */
#if(ADC_Prescaler==Mode_2)
	CLR_BIT(ADCSRA_REG,ADPS0);
	CLR_BIT(ADCSRA_REG,ADPS1);
	CLR_BIT(ADCSRA_REG,ADPS2);

#elif ADC_Prescaler==Mode_4
	CLR_BIT(ADCSRA_REG,ADPS0);
	SET_BIT(ADCSRA_REG,ADPS1);
	CLR_BIT(ADCSRA_REG,ADPS2);

#elif ADC_Prescaler==Mode_8
	SET_BIT(ADCSRA_REG,ADPS0);
	SET_BIT(ADCSRA_REG,ADPS1);
	CLR_BIT(ADCSRA_REG,ADPS2);

#elif ADC_Prescaler==Mode_16
	CLR_BIT(ADCSRA_REG,ADPS0);
	CLR_BIT(ADCSRA_REG,ADPS1);
	SET_BIT(ADCSRA_REG,ADPS2);

#elif ADC_Prescaler==Mode_32
	SET_BIT(ADCSRA_REG,ADPS0);
	CLR_BIT(ADCSRA_REG,ADPS1);
	SET_BIT(ADCSRA_REG,ADPS2);

#elif ADC_Prescaler==Mode_64
	CLR_BIT(ADCSRA_REG,ADPS0);
	SET_BIT(ADCSRA_REG,ADPS1);
	SET_BIT(ADCSRA_REG,ADPS2);

#elif ADC_Prescaler==Mode_128
	SET_BIT(ADCSRA_REG,ADPS0);
	SET_BIT(ADCSRA_REG,ADPS1);
	SET_BIT(ADCSRA_REG,ADPS2);
#else
#endif


	/*  Voltage Reference */
#if(ADC_VOLT==AVCC)
	CLR_BIT(ADMUX_REG,REFS1);
	SET_BIT(ADMUX_REG,REFS0);

#elif(ADC_VOLT==AREF)
	CLR_BIT(ADMUX_REG,REFS1);
	CLR_BIT(ADMUX_REG,REFS0);

#elif(ADC_VOLT==INTERNAL_VOLT)
	CLR_BIT(ADMUX_REG,REFS1);
	CLR_BIT(ADMUX_REG,REFS0);
#else "Error Voltage Reference "
#endif


	/*    Resolution        */
#if   ADC_NUMBER_BITS==8
	SET_BIT(ADMUX_REG,ADLAR);
#elif ADC_NUMBER_BITS==10
	CLR_BIT(ADMUX_REG,ADLAR);
#else "Error Resolution"
#endif

	/*Enable ADC*/
	SET_BIT(ADCSRA_REG,ADEN);

#if ADC_CONVERSION== SINGLE_CONVERSION
	SET_BIT(ADCSRA_REG,ADSC);
	CLR_BIT(ADCSRA_REG,ADIF);
	CLR_BIT(ADCSRA_REG,ADATE);
#elif ADC_CONVERSION == AUTO_TRIGGER
	/*Set Auto Trigger */
	SET_BIT(ADCSRA_REG,ADATE);

	/*Enable interrupt*/
	SET_BIT(ADCSRA_REG,ADIF);

	/*Auto Trigger Source */

	SFIOR_REG &= TRIG_MASK;
	SFIOR_REG |= ADC_TRIGG;


	/*Start the first conversion*/
	SET_BIT(ADCSRA_REG,ADSC);
#else
#endif
}

u16 ADC_u16Startsynch (u8 Copy_u8Channel){
	/*  Clear Mux Register  */
	ADMUX_REG&=MUX_MASK;
	/* Set ADMUX */
	ADMUX_REG|=Copy_u8Channel;
	SET_BIT(ADCSRA_REG,ADSC);
	while(!GET_BIT(ADCSRA_REG,ADIF));
	CLR_BIT(ADCSRA_REG,ADIF);
#if ADC_NUMBER_BITS==8
	return ADCH_REG;
#elif ADC_NUMBER_BITS==10
	return ADC_REG;
#else
#endif
}

void ADC_voidStartAsynch(u8 Copy_u8Channel ,u8 * Copy_pu8CallBackFunc)
{

		ADC_CALLBACK_PTR=Copy_pu8CallBackFunc;
		/*  Clear Mux Register  */
		ADMUX_REG&=MUX_MASK;
		/* Set ADMUX */
		ADMUX_REG|=Copy_u8Channel;
		/* Enable interrupt*/
		SET_BIT(ADCSRA_REG,ADIE);
}

void __vector_19 (void) __attribute__ ((signal)) ;
void __vector_19 (void){

		ADC_u16Data=ADC_REG;

		ADC_CALLBACK_PTR();
}


u32 ADC_u32Mapping (u32 Range1_max,u32 Range1_min,u32 Range2_max,u32 Range2_min,u32 Range1_reading){

	return (Range2_max-((Range2_max-Range2_min)*(Range1_max-Range1_reading)/(Range1_max-Range1_min)));
}
