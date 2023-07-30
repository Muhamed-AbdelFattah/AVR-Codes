/**************************************************************/
/**************************************************************/
/*************    Author: Muhamed AbdelFattah    **************/
/*************    Layer: MCAL                    **************/
/*************    SWC: EXTI                       *************/
/**************************************************************/
/**************************************************************/

#ifndef EXTI_REGISTER_H_
#define EXTI_REGISTER_H_

#define MCUCR *((volatile u8*)(0x55))
#define GIFR *((volatile u8*)(0x5A))
#define  GICR *((volatile u8*)(0x5B))
#define MCUCSR *((volatile u8*)(0x54))

//MCUCR  1
#define ISC11 3
#define ISC10 2

//MCUCR  0
#define ISC01 1
#define ISC00 0

//MCUCR 2 For Falling and Rising only
#define ISC2 6


#define INTF1 7
#define INTF0 6
#define INTF2 5

#define INT1 7
#define INT0 6
#define INT2 5



#endif /* EXTI_REGISTER_H_ */
