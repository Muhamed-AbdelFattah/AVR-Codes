/**************************************************************/
/**************************************************************/
/*************    Author: Muhamed AbdelFattah    **************/
/*************    Layer: MCAL                    **************/
/*************    SWC: UART                      **************/
/**************************************************************/
/**************************************************************/

#include "../../3-LIB/BIT_MATH.h"
#include "../../3-LIB/STD_TYPES.h"
#include "UART_register.h"
#include "UART_interface.h"


void UART_init(void){
    u8 UCSRC_Value=0;
    /* Enable Start bit*/
    SET_BIT(UCSRC_Value,URSEL);

    /* UART Mode Select Asynchronous But Register initial is Asynchronous*/
    CLR_BIT(UCSRC_Value,UMSEL);

    /*Parity Mode Disable  But Register Initial  is disable*/

    CLR_BIT(UCSRC_Value,UPM0);
    CLR_BIT(UCSRC_Value,UPM1);

    /*Data Size 8 Bit  */

    SET_BIT(UCSRC_Value,UCSZ0);
        
    SET_BIT(UCSRC_Value,UCSZ1);
    
    //SET_BIT(UCSRB,UCSZ2);  // for 9 bit data

    /* Stop Bit Select */
    CLR_BIT(UCSRC_Value,USBS);

    UCSRC=UCSRC_Value;
    
    /*Baud Rate 9600*/

    UBRRL=51;

    /*Enable Transmitter and Receiver*/
    SET_BIT(UCSRB,RXEN);
    SET_BIT(UCSRB,TXEN);


}
u8 UART_recievechar(void){
    while (GET_BIT(UCSRA,RXC)==0);
    return(UDR);
}
void UART_sendchar(u8 data){
    while(GET_BIT(UCSRA,UDRE)==0);
    UDR=data;
}
