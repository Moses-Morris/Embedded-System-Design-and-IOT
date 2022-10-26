#include <reg51.h>
#define led P2 //port for connector in reg51 in the register
void delay(void)//this function will delay: slow down
{
	unsigned int i;
	for (i = 0; i < 50000; i++);
}
void main()
{
	while(1)
	{
		led = 0x00; //Output
		delay();
		led = 0xFF; //input
		delay();
	}
}