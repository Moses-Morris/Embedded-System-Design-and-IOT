#include<htc.h>
#include<pic.h>
#define _XTAL_FREQ 20000000

#define s1 RDO
#define s2 RD1
#define s3 RD2
#define s4 RD3
#define s5 RD4
#define s6 RD5
#define s7 RD6

void rundutycycle(unsigned int x);

void rundutycycle(unsigned int dutycyc)
{
    T2CON=0x01; // Set Prescaler to be 4, hence PWM frequency is set to 4.88KHz.
    T2CON|=0x04; // Enable the Timer2, hence enable the PWM.TIMERR2 ON=1
    while(1){
        CCPR1L =dutycyc >> 2; // Put MSB 8 bits in CCPR1L
        CCP1CON&=0xCF; // Make bit4 and 5 zero
        CCP1CON|= (0x30&(dutycyc << 4)); // Assign Last 2 LSBs to CCP1CON
        if(s1 == 1){dutycyc=172;}
        else if(s2 == 1){dutycyc=342;}
        else if(s3 == 1){dutycyc=512;}
        else if(s4 == 1){dutycyc=686;}
        else if(s5=-1){dutycyc=858;}
        else if(s6 == 1){dutycyc=1020;}
        else if(s7 == 1){dutycyc=0;}
        dutycyc-dutycyc;
    }
}

void main()
{
TRSID =0xFF ; // PORT D AS INPUT
TRISC2=0;// MAKE CCP1 PIN AS OUTPUT;
CCP1CON=0x0C;// CONFIGURE CCP1 MODULE IN PWM Mode
PR2=0xFF;
rundutycycle(512) ;
}