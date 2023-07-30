/**************************************************************/
/**************************************************************/
/*************    Author: Muhamed AbdelFattah    **************/
/*************    Layer: HAL                     **************/
/*************    SWC:Stepper                     *************/
/**************************************************************/
/**************************************************************/

#include "../../3-LIB/STD_TYPES.h"
#include "../../3-LIB/BIT_MATH.h"
#include "../../1-MCAL/1-DIO/DIO_interface.h"
#include "STEPPER_interface.h"
#include "util/delay.h"
#define F_CPU 8000000


void STEPPER_VID_INIT(void)
{
	DIO_SetPinDirection(STEPPER_PORT,BLUE,PIN_OUTPUT);
	DIO_SetPinDirection(STEPPER_PORT,PINK,PIN_OUTPUT);
	DIO_SetPinDirection(STEPPER_PORT,YELLOW,PIN_OUTPUT);
	DIO_SetPinDirection(STEPPER_PORT,ORANGE,PIN_OUTPUT);

	DIO_SetPinValue(STEPPER_PORT,BLUE,PIN_HIGH);
	DIO_SetPinValue(STEPPER_PORT,PINK,PIN_HIGH);
	DIO_SetPinValue(STEPPER_PORT,YELLOW,PIN_HIGH);
	DIO_SetPinValue(STEPPER_PORT,ORANGE,PIN_HIGH);
}
void STEPPER_VID_CW(u16 degrees)
{
	u16 i=0;
	u16 max=(degrees*10)/7;

	DIO_SetPinValue(STEPPER_PORT,BLUE,PIN_HIGH);
	DIO_SetPinValue(STEPPER_PORT,PINK,PIN_HIGH);
	DIO_SetPinValue(STEPPER_PORT,YELLOW,PIN_HIGH);
	DIO_SetPinValue(STEPPER_PORT,ORANGE,PIN_HIGH);

	for(i=0; i<max; i++)
	{
		DIO_SetPinValue(STEPPER_PORT,BLUE,PIN_LOW);
		DIO_SetPinValue(STEPPER_PORT,PINK,PIN_HIGH);
		DIO_SetPinValue(STEPPER_PORT,YELLOW,PIN_HIGH);
		DIO_SetPinValue(STEPPER_PORT,ORANGE,PIN_HIGH);
		_delay_ms(2);
		DIO_SetPinValue(STEPPER_PORT,BLUE,PIN_HIGH);
		DIO_SetPinValue(STEPPER_PORT,PINK,PIN_LOW);
		DIO_SetPinValue(STEPPER_PORT,YELLOW,PIN_HIGH);
		DIO_SetPinValue(STEPPER_PORT,ORANGE,PIN_HIGH);
		_delay_ms(2);
		DIO_SetPinValue(STEPPER_PORT,BLUE,PIN_HIGH);
		DIO_SetPinValue(STEPPER_PORT,PINK,PIN_HIGH);
		DIO_SetPinValue(STEPPER_PORT,YELLOW,PIN_LOW);
		DIO_SetPinValue(STEPPER_PORT,ORANGE,PIN_HIGH);
		_delay_ms(2);
		DIO_SetPinValue(STEPPER_PORT,BLUE,PIN_HIGH);
		DIO_SetPinValue(STEPPER_PORT,PINK,PIN_HIGH);
		DIO_SetPinValue(STEPPER_PORT,YELLOW,PIN_HIGH);
		DIO_SetPinValue(STEPPER_PORT,ORANGE,PIN_LOW);
		_delay_ms(2);
	}
}
void STEPPER_VID_CCW(u16 degrees)
{
	u16 i=0;
	u16 max=(degrees*10)/7;

	DIO_SetPinValue(STEPPER_PORT,BLUE,PIN_HIGH);
	DIO_SetPinValue(STEPPER_PORT,PINK,PIN_HIGH);
	DIO_SetPinValue(STEPPER_PORT,YELLOW,PIN_HIGH);
	DIO_SetPinValue(STEPPER_PORT,ORANGE,PIN_HIGH);

	for(i=0; i<max; i++)
	{
		DIO_SetPinValue(STEPPER_PORT,BLUE,PIN_HIGH);
		DIO_SetPinValue(STEPPER_PORT,PINK,PIN_HIGH);
		DIO_SetPinValue(STEPPER_PORT,YELLOW,PIN_HIGH);
		DIO_SetPinValue(STEPPER_PORT,ORANGE,PIN_LOW);
		_delay_ms(2);
		DIO_SetPinValue(STEPPER_PORT,BLUE,PIN_HIGH);
		DIO_SetPinValue(STEPPER_PORT,PINK,PIN_HIGH);
		DIO_SetPinValue(STEPPER_PORT,YELLOW,PIN_LOW);
		DIO_SetPinValue(STEPPER_PORT,ORANGE,PIN_HIGH);
		_delay_ms(2);
		DIO_SetPinValue(STEPPER_PORT,BLUE,PIN_HIGH);
		DIO_SetPinValue(STEPPER_PORT,PINK,PIN_LOW);
		DIO_SetPinValue(STEPPER_PORT,YELLOW,PIN_HIGH);
		DIO_SetPinValue(STEPPER_PORT,ORANGE,PIN_HIGH);
		_delay_ms(2);
		DIO_SetPinValue(STEPPER_PORT,BLUE,PIN_LOW);
		DIO_SetPinValue(STEPPER_PORT,PINK,PIN_HIGH);
		DIO_SetPinValue(STEPPER_PORT,YELLOW,PIN_HIGH);
		DIO_SetPinValue(STEPPER_PORT,ORANGE,PIN_HIGH);
		_delay_ms(2);
	}
}
