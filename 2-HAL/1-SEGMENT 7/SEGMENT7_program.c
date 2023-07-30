/**************************************************************/
/**************************************************************/
/*************    Author: Muhamed AbdelFattah    **************/
/*************    Layer: HAL                     **************/
/*************    SWC:SevenSegment                *************/
/**************************************************************/
/**************************************************************/

#include "../../3-LIB/STD_TYPES.h"
#include "../../3-LIB/BIT_MATH.h"
#include "../../1-MCAL/1-DIO/DIO_interface.h"
#include "SEGMENT7_interface.h"

void Segment7_VidInit(u8 u8PortCopy, u8 u8ComPortCopy, u8 u8ComPinCopy, u8 u8ComPinTypeCopy){
	DIO_SetPortDirection(u8PortCopy, PORT_OUTPUT);
	DIO_SetPinDirection(u8ComPortCopy, u8ComPinCopy, PIN_OUTPUT);
	Segment7_VidClearDisplay(u8PortCopy, u8ComPinTypeCopy);
	Segment7_VidDisableDisplay(u8ComPortCopy, u8ComPinCopy, u8ComPinTypeCopy);
}

void Segment7_VidSetDisplay(u8 u8SignalCopy,u8 u8PortCopy, u8 comType){
	switch (comType)
	{
	case comAnode:
		DIO_SetPortValue(u8PortCopy, ~(u8SignalCopy));
		break;
	case comCathode:
		DIO_SetPortValue(u8PortCopy, u8SignalCopy);
		break;
	}
}
void Segment7_VidClearDisplay(u8 u8PortCopy, u8 comType){
	switch (comType)
	{
	case comAnode:
		DIO_SetPortValue(u8PortCopy, PORT_HIGH);
		break;
	case comCathode:
		DIO_SetPortValue(u8PortCopy, PORT_LOW);
		break;
	}
}
void Segment7_VidEnableDisplay(u8 comPort,u8 comPin,u8 comType){
	switch (comType)
		{
		case comAnode:
			DIO_SetPinValue(comPort, comPin, PIN_HIGH);
			break;
		case comCathode:
			DIO_SetPinValue(comPort, comPin, PIN_LOW);
			break;
		}
}
void Segment7_VidDisableDisplay(u8 comPort,u8 comPin,u8 comType){
	switch (comType)
			{
			case comAnode:
				DIO_SetPinValue(comPort, comPin, PIN_LOW);
				break;
			case comCathode:
				DIO_SetPinValue(comPort, comPin, PIN_HIGH);
				break;
			}
}
