/*********************************************
 * Author:				AbdelFattah
 * Creation Data:		16 May, 2023
 * Version:				v1.0
 * Compiler:			GNU AVR-GCC
 * Controller:			ATmega32 (8-bit Architecture)
 * Layer:				MCAL
 ********************************************/

#ifndef TIMER_REGISTER_H_
#define TIMER_REGISTER_H_


#define TIFR_Register  *((volatile u8*)0x58)
#define TIFR_TOV0    0   /*Timer 0 Overflow Flag*/
#define TIFR_OCF0    1  /*Output Compare Flag timer 0*/
#define TIFR_TOV1    2  /*Timer 1 Overflow Flag*/
#define TIFR_OCF1B   3  /*Output Compare Flag timer 1 B*/
#define TIFR_OCF1F   4	/*Output Compare Flag timer 1 A*/
#define TIFR_ICF1    5  /*ICU Flag*/
#define TIFR_TOV2    6	/*Timer 2 Overflow Flag*/
#define TIFR_OCF2    7  /*Output Compare Flag timer 2*/

#define TIMSK_Register  *((volatile u8*)0x59)
#define TCNT0_Register  *((volatile u8*)0x52)

#define TCCR1A_Register  *((volatile u8*)0x4F)
#define TCCR1B_Register  *((volatile u8*)0x4E)
#define TCNT1_Register  *((volatile u16*)0x4C)
#define OCR1A_Register  *((volatile u16*)0x4A)
#define OCR1B_Register  *((volatile u16*)0x48)
#define ICR1_Register  *((volatile u16*)0x46)

/*Waveform Generation Mode Chanel A*/
#define TCCR1A_WGM10    0
#define TCCR1A_WGM11    1

/*Compare Match For Channel A*/
#define TCCR1A_COMP1A0    6
#define TCCR1A_COMP1A1    7

/*Compare Match For Channel B*/
#define TCCR1A_COMP1B0    4
#define TCCR1A_COMP1B1    5

/* Setting Prescaller*/
#define TCCR1B_CS10       0
#define TCCR1B_CS11       1
#define TCCR1B_CS12       2

/*Input Capture edge select  */
#define TCCR1B_ICES1      6


/*Waveform Generation Mode Chanel B*/
#define TCCR1B_WGM12    3
#define TCCR1B_WGM13    4

#define PRESCALER_MASKING 0b11111000

/*Input Capture interrupt Enable*/
#define TIMSK_TICIE1       5

#define OCR2_Register  *((volatile u8*)0x43)
#define TCCR2_Register  *((volatile u8*)0x45)
/* Setting Prescaller TIMER 2*/
#define TCCR2_CS20       0
#define TCCR2_CS21       1
#define TCCR2_CS22       2
/*Waveform Generation TIMER 2 */
#define TCCR2_WGM20    6
#define TCCR2_WGM21    3

/*Compare Match TIMER 2*/
#define TCCR2_COMP20   4
#define TCCR2_COMP21   5

/*Clock Select Prescaler*/
#define NO_CLOCK    0
#define DIV_1       1
#define DIV_8		2
#define DIV_32		3
#define DIV_64		4
#define DIV_128		5
#define DIV_256		6
#define DIV_1024	7

#define TCCR0_Register  *((volatile u8*)0x53)
#define OCR0_Register  *((volatile u8*)0x5C)

/* Setting Prescaller TIMER 0*/
#define TCCR0_CS00       0
#define TCCR0_CS01       1
#define TCCR0_CS02       2
/*Waveform Generation TIMER 0 */
#define TCCR0_WGM00    6
#define TCCR0_WGM01    3

/*Compare Match For TIMER 0*/
#define TCCR0_COMP00   4
#define TCCR0_COMP01   5


#endif /* TIMER_REGISTER_H_ */
