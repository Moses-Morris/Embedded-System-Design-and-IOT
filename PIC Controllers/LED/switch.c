#include<pic.h>
__CONFIG (0X3F72);
void delayms(unsigned int);
void delayms(unsigned int ms)
(
	int cnt;
	while(ms >0)
	(
		ms--;
		for(cnt=0;cnt<220;cnt ++);
	}
}
void main()
(
	delayms(10);
	TRISB=0XFF;
	TRISC=0X00;
	PORTC=0X00;
	delayms(10);
	//delayms(10);
	while(1)
	(
	PORTC PORTB;
	delayms(500);
}