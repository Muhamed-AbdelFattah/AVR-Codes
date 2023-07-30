/**************************************************************/
/**************************************************************/
/*************    Author: Muhamed AbdelFattah    **************/
/*************    Layer: APP                     **************/
/**************************************************************/
/**************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "SEGMENT_interface.h"

#include "util/delay.h"
#define F_CPU 8000000

u8 numbers[10]={
		zero  ,
		one   ,
		two   ,
		three ,
		four  ,
		five  ,
		six   ,
		seven ,
		eight ,
		nine
};

void main(void){
	Segment7_VidInit(PORT_C,PORT_A,PIN_0,comCathode);
	Segment7_VidInit(PORT_C,PORT_A,PIN_1,comCathode);
	Segment7_VidEnableDisplay(PORT_A,PIN_0,comCathode);
	Segment7_VidEnableDisplay(PORT_A,PIN_1,comCathode);
	u8 i=0;
	u8 right=0,left=0;
	while(1){

		for(i=0;i<100;i++)
		{
			right=i%10;
			left=i/10;
			Segment7_VidEnableDisplay(PORT_A,PIN_1,comCathode);
			Segment7_VidSetDisplay(numbers[left],PORT_C,comCathode);
			_delay_ms(1000);
			Segment7_VidDisableDisplay(PORT_A,PIN_1,comCathode);

			Segment7_VidEnableDisplay(PORT_A,PIN_0,comCathode);
			Segment7_VidSetDisplay(numbers[right],PORT_C,comCathode);
			_delay_ms(10);
			Segment7_VidDisableDisplay(PORT_A,PIN_0,comCathode);

		}

	}
}
