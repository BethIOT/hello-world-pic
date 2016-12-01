// PIC16F876A Configuration Bit Settings

// 'C' source line config statements

#include <xc.h>
#include<stdio.h>

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

// CONFIG
#pragma config FOSC = XT        // Oscillator Selection bits (XT oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)
#define _XTAL_FREQ 4000000

void txr(char a);
//void txr_num(int a);
void txrs(char *p);

int main()
{
    int r=0;
    char a[13];
    TRISC=0xFC;
    TRISB=0x00;
    TXSTA=0x24;
    RCSTA=0x90;
    SPBRG=25;
    ADCON0=0x41; // When conf Port A as digital, use trisa and adcon1=0x06;
    ADCON1=0x80; // and dont set any val to adcon0
    while(1)
    {
        GO=1;
        while(GO);
        PORTB=ADRESL;
        PORTC=ADRESH;
        r=ADRESL+(ADRESH<<8);
//        txr_num(r);
        sprintf(a,"val is %d\n\r",r);
        txrs(a);
        __delay_ms(20);
    }
}

void txr(char a)
{
    TXREG=a;
    while(!TXIF);
}
/*
void txr_num(int p) //Getting garbage values
{ 
    int j;
    char b;
    txrs("val = ");
    __delay_ms(20);
    for(j=10000;j>=10;j/=10)
    {
        b=(p%j)+48;
        txr(b);
        __delay_ms(20);
    }
    txr("\n\r");
    __delay_ms(20);
}
*/
void txrs(char *p)
{
    while(*p)
    {
        txr(*p);
        __delay_ms(20);
        p++;
    }
}
