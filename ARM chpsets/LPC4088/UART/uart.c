#include "LPC407x_8x_177x_8x.h"

unsigned char welcomestring[] = "helo \r\n";
unsigned char receiveValue = 0;
unsigned char Uart0_Receive(void);
void Uart0_transmit(unsigned char Chr);
void Uart0_Init(void);
void Uart0_SendString(unsigned char *string);
void Uart0_Init(void)
{
	LPC_SC->PCONP |= (1<<3); //enable power supply
	LPC_IOCON->P0_2 |= 1; //select uart0 txd
	LPC_IOCON->P0_2 |= 1; //select uart0 rxd
	
	LPC_UART0->LCR = 0x83; //baud rate calculation
	LPC_UART0->DLL = 195;
	LPC_UART0->LCR = 0;
	LPC_UART0->LCR = 0x03;
}

void Uart0_Transmit(unsigned char Chr)
{
	while((LPC_UART0->LSR & 0X20) == 0);
		LPC_UART0->THR = Chr;
}

unsigned char Uart0_Receive(void)
{
	while((LPC_UART0->LSR & 0X01) == 0);
		return (LPC_UART0->RBR);
}

int main(void)
{
	Uart0_Init();
	while(1)
	{
		receiveValue = Uart0_Receive();
		Uart0_Transmit(receiveValue);
	}
}
