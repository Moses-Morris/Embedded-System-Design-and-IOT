//this code is for LPC4088 cortex M4
#include "LPC407x_8x_177x_8x.h"

void delay_ms(long ms);
void delay_ms(long ms)
{
	long i, j;
	for (i = 0; i < ms; i++)
	for (j = 0; j < 26659; j++);
}
int main (void)
{
	//Set PCGPIO bit
	LPC_SC->PCONP |= (1 << 15);
	
	//Configure pins P4.0 to P4.7 as GPIO pins
	LPC_IOCON->P4_0 = 0;
	LPC_IOCON->P4_1 = 0;
	LPC_IOCON->P4_2 = 0;
	LPC_IOCON->P4_3 = 0;
	LPC_IOCON->P4_4 = 0;
	LPC_IOCON->P4_5 = 0;
	LPC_IOCON->P4_6 = 0;
	LPC_IOCON->P4_7 = 0;
	
	//Configure the pins P4.0 to P4.7 as output
	LPC_GPIO4->DIR = 0xFF;
	
	while(1)
	{
		//SEND A HIGH
		LPC_GPIO->PIN = 0xFF;
		
		//pause the system for some minutes.
	  delay_ms(500);
		
		//SEND A LOW
		LPC_GPIO->PIN = 0x00;
		
		//PAUSE FOR SOME MILLISECONDS
		delay_ms(500);
		
	}
}