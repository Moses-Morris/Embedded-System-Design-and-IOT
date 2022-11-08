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
    
    //configure the port 4s ans output P4.0 - P4.7
    LPC_GPIO4 -> DIR = 0xFF;

    while(1)
    {
        LPC_GPIO4 -> PIN = 0xFF; //This is off   : ->0xFF is the hex representation of ~0 (i.e. 11111111) 
        delayms(500);
        LPC_GPIO4 -> PIN = 0x00; // This is on
        delayms(500);
    }

}