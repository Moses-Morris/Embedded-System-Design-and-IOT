//Weather Humidity and Temperature.

#include <lpc214x.h>
#include <stdint.h> //header shall declare sets of integer types
#include <stdio.h> 
#include <string.h>

#define DHT11 16 //PORT 1.16

//WIFI AT COMMANDS
static unsigned char command_basic_1[5] = "AT\r\n"; //BASIC
static unsigned char command_basic_2[9] = "AT+RST\r\n"; //BASIC
static unsigned char command_ESP_1[14] = "AT+CWMODE=1\r\n"; //WIFI
static unsigned char command_ESP_2[14] = "AT+CWQAP\r\n"; //WIFI
static unsigned char command_ESP_4[25] = "AT+CWDHCP=1,1\r\n"; //THINKSPEAK

//This command is to connect to an Access poin like a router
static unsigned char command_ESP_3[50] = "AT+CWJAP=\"ZTE-adde78\",\"885dfbad\"\r\n";
static unsigned char command_ESP_5[50] = "AT+CIPSTART=\"TCP\",\"184.106.153.149\",80\r\n"; 
static unsigned char command_ESP_6[20] = "AT+CIPSEND=64\r\n";
static unsigned char command_ESP_7[64] = "GET /update?api_key=4567890\r\n"; // api key provided at thinkspeak
static unsigned char command_ESP_8[9] = "&field2=";
static unsigned char command_ESP_9[9] = "\r\n\r\n";
static unsigned char command_ESP_10[20] = "AT+CIPCLOSE\r\n";
static unsigned char dht11_data[8], data_string_1[8], data_string_2[8], display[30] = "HUMIDITY & TEMPERATURE ..";// 4 BYTES OF Data 



//function declarations
//specific process functions.

void config_DHT11(void);
void Init_DHT11(void);
unsigned char receive_bytes(void);
void Init_ESP8266(void);
void Basic_Commands(void);
void Wifi_Conn_Commands(void);
void Thing_Speak_Command_Start(void);
void Data_Commands(void);
void Wifi_acc(void);
void Delay_ms(uint16_t j); //millisecond
void Delay_us(uint16_t j); //microseconds
void integer_to_ascii(unsigned int Val, unsigned char *str);


//Integer to ASCII converion
void integer_to_ascii(unsigned int Val, unsigned char *str)
{
	str[0] = Val/1000 + 0x30;
	Val = Val % 1000;
	
	str[1] = Val/100 + 0x30;
	Val = Val % 100;
	str[2] = Val/10 + 0x30;
	str[3] = Val%10 + 0x30;
	str[4] = '\0';
	
}

//Delay Code

void Delay_ms(uint16_t j)
{
	uint16_t x,i;
	for (i = 0; i < j; i++)
	{
		for(x = 0; x < 6000; x++); //loop to generate 1 millisecond delay with 60MHz Clock
	}
}

void Delay_us(uint16_t j)
{
	uint16_t x, i;
	for(i = 0; i < j; i++)
	{
		for(x = 0; x < 7; x++); //loop to generate 1.04 microseconf=d delay with 60 MHz Clock
	}
}

//UART Transmit and Receive
// UART Initialize
void Init_Uart0(void)
{
	VPBDIV = 2; //CONFIGURE PINS P0.0 and P0.1 as UART0 tX and RX
	PINSEL0 = 5; //Pin P0.0  used as  TXD0  pin P0.1 used as RXD)
	
	//select clock source and frequency = PCLK ie 30 MHz
	//8 bit no parity , 1 stop bit.
	
	U0LCR = 0x83;
	//derive baud rate from UART clock source set DLAB =1 to access baud
	//register
	//Derive baud rate from the UART clock source
	//DLM:DLL=PCLK/(16*baud) = 30 MHz/(16*115200) = 16
	
	U0DLL = 16; //115200 Baud rate @ 30.0 MHz PCLK
	U0LCR = 0x03; //DLAB = 0

		
}
//UART Transmit
void UART0_Txt(unsigned char character)
{
	//check the transmitter flag
	//if it is hih transmit a character
	while((U0LSR & 0x20) == 0); //Bit 5 THRE, check THR empty or not
	U0THR = character; //send the next character		
}

//UART Receive a character
unsigned char UART0_Rxt(void)
{
	//check the transmitter flag
	//if it is hih transmit a character
	while((U0LSR & 0x01) == 0); //Bit0-RDR, check receive data ready
	return(U0RBR); //	Read the data
}

//transmit a string
void UART0_Print(unsigned char *print_string)
{
	while(*print_string)
		UART0_Txt(*print_string++);
}

//Config DHT
void config_DHT11(void)
{
	PINSEL2 = 0;
	IO1DIR = 1 << DHT11;
	IO1SET = 1 << DHT11;
	Delay_ms(100);
}

//initialize DHT
void Init_DHT11(void)
{
	unsigned char a = 0;
	IO1DIR = 1 << DHT11;
	IO1SET = 1 << DHT11;
	IO1CLR = 1 << DHT11;
	
	Delay_ms(25);
	
	IO1SET = 1 << DHT11;
	IO1DIR = 0 << DHT11;
	
	
	while(((IO1PIN >> DHT11) & 1) == 1);
	while(((IO1PIN >> DHT11) & 1) == 0);
	while(((IO1PIN >> DHT11) & 1) == 1);
	
	for(a = 0; a <= 4; a++)
	{
		dht11_data[a] = receive_bytes();
	}
}


//Receive Bytes
unsigned char receive_bytes(void)
{
	unsigned char a = 0;
	unsigned char out;
	
	for(a = 0; a <= 7; a++)
	{
		while(((IO1PIN >> DHT11) & 1) == 0);
		Delay_us(35);
		
		if(((IO1PIN >> DHT11) & 1) == 1)
		{
			out |= 1;
			out = out << 1;
		}
		else
		{
			out |= 0;
			out = out << 1;
		}
		while(((IO1PIN >> DHT11) & 1) == 1);
	}
	return (out);
}

//AT Commands
void Wifi_Conn_Commands(void)
{
	UART0_Print(command_ESP_1);
	Delay_ms(500);
	UART0_Print(command_ESP_2);
	Delay_ms(500);
}

void Thing_Speak_Command_Start(void)
{
	UART0_Print(command_ESP_4);
	Delay_ms(5000);
}

//Initialize esp
void Init_ESP8266(void)
{
	Delay_ms(5000);
	Basic_Commands();
	Wifi_Conn_Commands();
}

void Wifi_acc(void)
{
	UART0_Print(command_ESP_3);
	Delay_ms(8000);
}


//Data Commands (AT coommand)
void Data_Commands(void)
{
	UART0_Print(command_ESP_5);
	Delay_ms(5000);
	
	UART0_Print(command_ESP_6);
	Delay_ms(5000);
	
	UART0_Print(command_ESP_7);
	UART0_Print(data_string_1);
	
	UART0_Print(command_ESP_8);
	UART0_Print(data_string_2);
	
	UART0_Print(command_ESP_9);
	Delay_ms(1000);
	
	UART0_Print(command_ESP_10);
	Delay_ms(5000);
}

//Main program
int main(void)
{
	//Init_Timer_0();
	//Init_Timer_1();
	Init_Uart0();
	
	config_DHT11();
	
	Init_ESP8266();
	
	Wifi_acc();
	
	Thing_Speak_Command_Start();
	
	Delay_ms(500);
	
	while(1)
	{
		Init_DHT11();
		
		dht11_data[0] = dht11_data[0]/ 1.60;
		integer_to_ascii(dht11_data[0], data_string_1);
		
		dht11_data[2] = dht11_data[2]/ 2.05;
		integer_to_ascii(dht11_data[2], data_string_2);
		
		Data_Commands();
		
		UART0_Print(display);
		
		UART0_Print(data_string_1);
		
		UART0_Txt('\t');
		UART0_Txt('\t');
		
		UART0_Print(data_string_2);
		
		UART0_Txt('\r');
		UART0_Txt('\n');
		
		Delay_ms(10000);
		
	}
}






