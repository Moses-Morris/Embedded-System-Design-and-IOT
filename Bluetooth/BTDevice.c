#include <reg51.h>

void Uart_Init();
void Uart_Txchar(char);
char Uart_Rxchar(); //Return
void Uart_SendString(char *);

sbit Lamp = P0^0; //GPIO ports for lamp
sbit Fan = P0^1; //GPIO ports for Fan

void Uart_Init()
{
	TMOD = 0x20;
	TH1 = 0xFD;
	SCON = 0x50;
	TR1 = 1;
}

//transmit the data
void Uart_Txchar(char Data)
{
	SBUF = Data;
	while(TI == 0);
	TI = 0;
}

//Receive data for transmission
char Uart_Rxchar()
{
	char dat;
	while(RI == 0);
	RI = 0;
	dat = SBUF;
	return (dat);
}

void Uart_SendString(char *string)
{
	int i;
	for (i = 0; string[i] != 0; i++)
	{
		Uart_Txchar(string[i]);
	}
}

void main()
{
	char Data_in;
	Uart_Init();
	P0 = 0;
	while(1)
	{
		Data_in = Uart_Rxchar(); // receive the data so that it can be transmitted from the bluetoth device
		if(Data_in == '1')
		{
			Lamp = 1;
			Uart_SendString("Lamp On");
		}
		else if(Data_in == '2')
		{
			Lamp = 0;
			Uart_SendString("Lamp Off");
		}
		else if(Data_in == '3')
		{
			Fan = 1;
			Uart_SendString("Fan On");
			
		}
		else if(Data_in == '4')
		{
			Fan = 0;
			Uart_SendString("Fan Off");
			
		}
		else
		{
			Uart_SendString("Choose a state:  1, 2, 3, 4");
		}
	}
	
}
