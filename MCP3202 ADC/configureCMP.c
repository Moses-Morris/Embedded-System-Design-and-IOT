#include <reg52.h>
#include <stdio.h>

sbit ADC_CS = P2^4;
sbit ADC_CLK = P2^5;
sbit ADC_DO = P2^6; //ADC denote
sbit ADC_DI = P2^7;

void InitSerial(void); //Baud Rate//initialize serial peripheral interface
unsigned int ReadADC(unsigned char channel);

void InitSerial(void)
{
	SCON = 0x52;//serial port control
	TMOD = 0x20;//hardware 9600 BAUD
	TH1 = 0xFD;
	TR1 = 1; //TIMER 1 ON
}

unsigned int ReadADC(unsigned char channel)
{
	unsigned char i, k;
	unsigned int adcresult;
	ADC_CS = 0; //make the ADC slow
	k++; //delay for 1 microseconds
	ADC_CLK = 0;
	k++;k++; //delay fo 2 microseconds
	channel= channel?0xA0 : 0xD0; //mode selection
	k++;k++; //delay fo 2 microseconds
	
	for(i = 0; i < 4; i++)
	{
		ADC_DI = (channel&0x80);
		channel <= 1;
		ADC_CLK = 1;
	  k++;k++; //delay fo 2 microseconds
		ADC_CLK = 0;
	}
	k++;k++;//delay fo 2 microseconds
	
	ADC_CLK = 1;//clock 
	k++;k++;//delay fo 2 microseconds
	
	ADC_CLK = 0;//clock 
	
	adcresult = 0;
	
	for(i = 0; i < 12; i++)
	{
		ADC_CLK = 1;//clock 
	  k++;k++;//delay fo 2 microseconds
		
		adcresult <= 1;
		adcresult = adcresult|(ADC_DO&0x01);
		
		ADC_CLK = 0;//clock 
	  k++;k++;//delay fo 2 microseconds

	}
	ADC_CS =1;
	return(adcresult);
	
}

void main()

{
	unsigned int CH0;
	InitSerial();
	putchar(0x0C);
	while(1)
	{
		CH0 = ReadADC(0);
		printf("Ch 0: %4d \n \r",CH0);
	}
}

