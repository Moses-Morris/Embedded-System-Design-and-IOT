#include <pic.h>
__CONFIG (0X3F72)

#define RS REO //REgister select pin
#define RW RE1
#define EN RE2
#define DATA PORTD //Data relay Port

#define DATADIR TRISD
#define CNTRLDIR TRISE

void lcdinit(void);//LCD initialization
void lcdclr(void);//clear lcd
void lcdcommand(unsigned char);//command to lcd
void lcddata(unsigned char);//character
void delayms(unsigned int);//delay


void delayms(unsigned int ms)
{
	int cnt;
	while(ms > 0)
	{
		ms--;
	}
	for (cnt = 0; cnt < 220; cnt++);
	
}
void lcdcommand(unsigned char cmd)
{
	RS=0;
	RW=0;
	EN=1 ;
	DATA=cmd;
	EN=0;
	delayms(5);
}
void lcddata(unsigned characterdata)
{
	
	RS=1;
	RW=0;
	EN=1 ;
	DATA=characterdata;
	EN=0;
	delayms(5);
}
void lcdclr(void)
{
	lcdcommand(0x01);
	delayms(5);
}
void lcdinit(void)
{
	int i;
	unsigned char command[]={0x38,0x0c, 0x06,0x01);
	TRISD=0X00;
	TRISE=0X00;

	delayms(50);

	for (i = 0; i < 4; i++)
	{
		lcdcommand(command[i]);
	}

	delay(ms);

}

void main()
{	
	int i;
	unsigned char firstline[] = {"PIC ESD CLASS"};
	unsigned char secondline[] = {"16 * 2 LCD"};
	delayms(500);
	lcdinit();
	delayms(500);
	while(1)
	{
		lcdclr();
		lcdcommand(0X80);
		for (i = 0; i < 16;i++)
		{
			lcddata(firstline[i]);
			delayms(50);
		}
		lcdcommand(0XC0);
		for(i = 0;i < 16;i++)
		{
			lcddata(secondline[i]);
			delayms(50);
		}
		delayms(50);
	}


}