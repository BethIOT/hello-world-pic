
// PIC16F876A Configuration Bit Settings

// 'C' source line config statements

#include <xc.h>
#include<stdio.h>
#include<string.h>

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
void txrs(char *p);
void rxrs(char *p);
char rxr();


int main()
{
    int r=0, ct=0;
    char a[15];
    TRISB=0x00;
    TXSTA=0x24;
    RCSTA=0x90;
    SPBRG=25;
    ADCON0=0x41; // When conf Port A as digital, use trisa and adcon1=0x06;
    ADCON1=0x80; // and dont set any val to adcon0
    while(1)
    {
        txrs("Enter password : ");
        rxrs(a);
        if(strcmp(a,"admin")==0)
        {
            while(1)
            {
                GO=1;
                while(GO);
                r=ADRESL+(ADRESH<<8);
                if(r>750)
                {
                    PORTB=0xFF;
                    RB1=0;
                    sprintf(a,"TOO HOT.!!");
                    txrs(a);
                    __delay_ms(20);
                }
                else if(r>250)
                {
                    PORTB=0xFF;
                    RB2=0;
                    sprintf(a,"Just Right..");
                    txrs(a);
                    __delay_ms(20);
                }
                else
                {
                    PORTB=0xFF;
                    RB3=0;
                    sprintf(a,"__too cold");
                    txrs(a);
                    __delay_ms(20);
                }
            }
        }
        else
        {
            txrs("Unauthorised Access");
            if(ct<4)
                ct++;
            else
            {
                txrs("You have been blocked..!!");
                while(1);
            }
        }
    }    
}

void txr(char a)
{
    TXREG=a;
    while(!TXIF);
}

void txrs(char *p)
{
    while(*p)
    {
        txr(*p);
        __delay_ms(20);
        p++;
    }
    txr('\n');
    __delay_ms(20);
    txr('\r');
    __delay_ms(20);
}

char rxr()
{
    while(!RCIF);
    txr(RCREG);
    __delay_ms(20);
    return RCREG;
}

void rxrs(char *p)
{
    while(1)
    {
        *p=rxr();
        __delay_ms(20);
        if(*p=='\r')
            break;
        else p++;
    }
    *p='\0';
}