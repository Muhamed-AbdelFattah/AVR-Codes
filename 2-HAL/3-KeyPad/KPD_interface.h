/**************************************************************/
/**************************************************************/
/*************    Author: Muhamed AbdelFattah    **************/
/*************    Layer: HAL                     **************/
/*************    SWC:KPD                         *************/
/**************************************************************/
/**************************************************************/

#ifndef KPD_INTERFACE_H_
#define KPD_INTERFACE_H_

#define KPD_PORT PORT_A
#define   ROW_START  PIN_0
#define   ROW_END    PIN_3
#define   COLUMN_START  PIN_4
#define   COLUMN_END    PIN_7


void KPD_init(void);
u8 KPD_GetKey(void);

#endif /* KPD_INTERFACE_H_ */
