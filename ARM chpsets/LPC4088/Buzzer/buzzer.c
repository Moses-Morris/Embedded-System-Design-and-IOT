#include "lpc407x_8x_177x_8x.h"

void delay_ms(long ms);

void delay_ms(long ms)
{
    long i, j;
    for (i = 0 ; i < ms ; i++)
    {
        for(j = 0 ; j < 266659 ; j++);
    }
}

int main(void)
{
	//set the PCGPIO bit
	LPC_SC->PCONP |= (1<<15);
	LPC_IOCON->P0_26 = 0;
	LPC_GPIO0->DIR = 0x4000000;
	
	while(1)
	{
		//send  a high
		LPC_GPIO0->PIN = 0x4000000;
		
		//pause the system
		delay_ms(500);
		
		//send a low
		LPC_GPIO0->PIN = 0x0000000;
		
		//pause the system
		delay_ms(500);
	}
	
}

   
