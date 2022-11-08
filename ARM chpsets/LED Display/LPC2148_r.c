#include <lpc214x.h>
#define LED 0XFF0000  //configure LED port P1.16 TO P1.23

// For ARM 
void delay();

void delay(unsigned int n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < 120000; j++)
		{
			;
		}
	}
}

int main(void)
{
	IODIR1 = LED;
	while(1)
	{
		IOSET1 = LED;
		delay(20);
		IOCLR1 = LED;
		delay(20);
		
	}
}