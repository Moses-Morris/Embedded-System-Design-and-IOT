#include<pic.h>
__CONFIG(0X3F72);
#define FOSC 10000
#define BAUD RATE 9.6
#define BAUD_VAL (char) (FOSC/(16*BAUD_RATE))-1;
void main()
(
	unsigned char receivechar;
	TRSIC=0XC0;
	TXSTA=0X24;
	SPBRG BAUD_VAL;
	RCSTA=0X90;
	while(1)
	{
		if (RCIF == 1)
		{
		B receivechar=RCREG;
		if(TXIF == 1)
		TXREG receivechar;
}
}
}