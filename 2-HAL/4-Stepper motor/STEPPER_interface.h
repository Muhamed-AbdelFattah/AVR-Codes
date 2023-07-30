/**************************************************************/
/**************************************************************/
/*************    Author: Muhamed AbdelFattah    **************/
/*************    Layer: HAL                     **************/
/*************    SWC:Stepper                     *************/
/**************************************************************/
/**************************************************************/
#ifndef STEPPER_INTERFACE_H_
#define STEPPER_INTERFACE_H_

#define STEPPER_PORT PORT_C
#define BLUE PIN_0
#define PINK PIN_1
#define YELLOW PIN_2
#define ORANGE PIN_3

void STEPPER_VID_INIT(void);
void STEPPER_VID_CW(u16 degrees);
void STEPPER_VID_CCW(u16 degrees);


#endif /* STEPPER_INTERFACE_H_ */
