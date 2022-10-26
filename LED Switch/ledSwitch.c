#include <reg51.h>

#define SWPORT P0 
#define LEDPORT P2

void main()
{
	P0 = 0XFF; //This is the Input
	P2 = 0X00; //This is the expected output port that the Chipset will use.
	while(1)
	{
		LEDPORT = SWPORT;
	}
}