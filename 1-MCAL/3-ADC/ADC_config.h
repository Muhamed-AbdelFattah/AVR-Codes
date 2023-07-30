/**************************************************************/
/**************************************************************/
/*************    Author: Muhamed AbdelFattah    **************/
/*************    Layer: MCAL                    **************/
/*************    SWC: ADC                       **************/
/**************************************************************/
/**************************************************************/

#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_

#define  AVCC                   1
#define  AREF                   2
#define  INTERNAL_VOLT          3

#define  TRIG_MASK                0b00011111
#define  MUX_MASK                    0xE0

#define Mode_2                  1
#define Mode_4                  2
#define Mode_8                  3
#define Mode_16                 4
#define Mode_32                 5
#define Mode_64                 6
#define Mode_128                7

#define  SINGLE_CONVERSION       1
#define  AUTO_TRIGGER            2

#define FREE_RUNNING                0
#define Analog_Comparator			1
#define External_Interrupt			2
#define Timer_Counter0_Compare		3
#define Timer_Counter0_Overflow		4
#define Timer_Counter_Compare_B		5
#define Timer_Counter1_Overflow		6
#define Timer_Counter_1				7



#define ADC_VOLT               AVCC
/*
 * Options
 * AVCC
 * AREF
 * INTERNAL_VOLT */

#define ADC_Prescaler          Mode_128
/*
 *Options
 *Mode_2
 *Mode_4
 *Mode_8
 *Mode_16
 *Mode_32
 *Mode_64
 *Mode_128
 **/

#define ADC_NUMBER_BITS          10
/* Options
 * 8  //BITS
 * 10 //BITS */

#define ADC_CONVERSION        AUTO_TRIGGER
/*Options
 * SINGLE_CONVERSION
 * AUTO_TRIGGER
 * */
#define ADC_TRIGG               FREE_RUNNING


/*Options
 *FREE_RUNNING
 *Analog_Comparator
 *External_Interrupt
 *Timer_Counter0_Compare
 *Timer_Counter0_Overflow
 *Timer_Counter_Compare_B
 *Timer_Counter1_Overflow
 *Timer_Counter_1
 * */

#endif /* ADC_CONFIG_H_ */
