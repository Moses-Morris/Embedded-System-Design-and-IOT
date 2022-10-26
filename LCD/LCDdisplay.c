#include <reg51.h>
//#include <reg52.h> will produce an erro of redefinition
#include <stdio.h>
#define DATA P0

//LCD serial bit connection ports
sbit RS = P0^0; //Register Select
sbit RW = P0^1; //Read Write
sbit LCD_ENABLE = P0^2; //lcd enable

unsigned char message1[] = ("Hello"); 
unsigned char message2[] = ("ESD Masterclass");
void lcd_init(void);
void delay(int);
void lcd_cmd(unsigned char);
void lcd_data(unsigned char);

void delay(int k)
{
	unsigned int i;
	for (i = 0; i < k; i++);
}

void lcd_cmd(unsigned char command)
{
	DATA = 0xF0 & command;  //upper nibble 1111 0000
	RS = 0; //COMMAND in Register segments
	RW = 0; //write in Read/write
	LCD_ENABLE = 1;
	delay(35);
	LCD_ENABLE = 0;
	
	DATA = command <<4;
	RS = 0; //COMMAND in Register segments
	RW = 0; //write in Read/write
	LCD_ENABLE = 1;
	delay(35);
	LCD_ENABLE = 0;
}
void lcd_data(unsigned char data1)
{
	DATA = 0xF0 & data1;  //upper nibble 1111 0000
	RS = 1; //COMMAND in Register segments
	RW = 0; //write in Read/write
	LCD_ENABLE = 1;
	delay(35);
	LCD_ENABLE = 0;
	
	
	DATA = data1 <<4;
	RS = 1; //COMMAND in Register segments
	RW = 0; //write in Read/write
	LCD_ENABLE = 1;
	delay(35);
	LCD_ENABLE = 0;
}

void lcd_init(void)
{
	unsigned int i;
	lcd_cmd(0x28); //2 lines in 2x16 LCD
	delay(15); //miliseconds
	lcd_cmd(0x0C); //Display ON, cursor OFF in 2x16 LCD
	delay(15); //miliseconds
	lcd_cmd(0x06); //Display ON, cursor OFF in 2x16 LCD
	delay(15); //miliseconds
	lcd_cmd(0x01); //Display ON, cursor OFF in 2x16 LCD
	delay(15); //miliseconds
	
	delay(5000);
	
	//Display message 1
	lcd_cmd(0x80); //Force cursor to beginning of first linein 2x16 LCD
	delay(15); //miliseconds
	
	i = 0;
	while(message1[i] != '\0')//get to end of the line
	{
		lcd_data(message1[i]);//now print out the message
		i++;
	}
	delay(50);
	
	//Display message 2
	lcd_cmd(0x80); //Force cursor to beginning of first linein 2x16 LCD
	delay(15); //miliseconds
	
	i = 0;
	while(message2[i] != '\0')//get to end of the line
	{
		lcd_data(message2[i]);
		i++;
	}
	delay(50);
}

void main()
{
	P0 = 0;
	lcd_init();
	delay(10);
	while(1);
}