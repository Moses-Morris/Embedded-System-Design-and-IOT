#include "lpc407x_8x_177x_8x.h"

void delayms(long ms);

void delayms(long ms)
{
    long i, j;
    for (i = 0 ; i < ms ; i++)
    {
        for(j = 0 ; j < 266659 ; j++);
    }
}

int main(void)
{
    //set the power control for PCGPIO Bit
    LPC_SC -> PCONP |= (1 < 15);

    //CONFIGURE THE LED GPIO PINS P4.O TO P4.7 
    //-> OPERATOR means its it a pointer pointing to the variable name
    LPC_IOCON -> P4_0 = 0;
    LPC_IOCON -> P4_1 = 0;
    LPC_IOCON -> P4_2 = 0;
    LPC_IOCON -> P4_3 = 0;
    LPC_IOCON -> P4_4 = 0;
    LPC_IOCON -> P4_5 = 0;
    LPC_IOCON -> P4_6 = 0;
		LPC_IOCON -> P4_7 = 0;
	
	  LPC_IOCON -> P4_8 = 0;
    LPC_IOCON -> P4_9 = 0;
    LPC_IOCON -> P4_10 = 0;
    LPC_IOCON -> P4_11 = 0;
    LPC_IOCON -> P4_12 = 0;
    LPC_IOCON -> P4_13 = 0;
    LPC_IOCON -> P4_14 = 0;
		LPC_IOCON -> P4_15 = 0;
    
    //configure the port 4s as output P4.0 - P4.7
		//configure the P4.8 - 15 as input
    LPC_GPIO4 -> DIR = 0x00FF;

    while(1)
    {
        LPC_GPIO4 -> PIN >>= 8; //This is the pins greater than P0.8 or equall
        delayms(50);
        
    }

}