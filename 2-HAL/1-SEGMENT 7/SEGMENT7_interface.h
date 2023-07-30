/**************************************************************/
/**************************************************************/
/*************    Author: Muhamed AbdelFattah    **************/
/*************    Layer: HAL                     **************/
/*************    SWC:SevenSegment                *************/
/**************************************************************/
/**************************************************************/

#ifndef SEGMENT7_INTERFACE_H_
#define SEGMENT7_INTERFACE_H_

#define comCathode 0
#define comAnode 1

#define zero    0x3f
#define one     0x06
#define two     0x5b
#define three   0x4f
#define four    0x66
#define five    0x6d
#define six     0x7d
#define seven   0x07
#define eight   0x7f
#define nine    0x6f

void Segment7_VidInit(u8 u8PortCopy, u8 u8ComPortCopy, u8 u8ComPinCopy, u8 u8ComPinTypeCopy);
void Segment7_VidSetDisplay(u8 u8SignalCopy,u8 u8PortCopy, u8 comType);
void Segment7_VidClearDisplay(u8 u8PortCopy, u8 comType);
void Segment7_VidEnableDisplay(u8 comPort,u8 comPin,u8 comType);
void Segment7_VidDisableDisplay(u8 comPort,u8 comPin,u8 comType);
#endif /* SEGMENT7_INTERFACE_H_ */
