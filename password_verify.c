
// PIC16F876A Configuration Bit Settings

// 'C' source line config statements

#include <xc.h>
#include <string.h>

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

void txr (char a);
char rxr ();
void txrs (char *p);
void rxrs (char *p);

int main()
{
    TXSTA=0x24;
    RCSTA=0x90;
    SPBRG=25;
    TRISB=0x00;
    TRISC=0x80;
    PORTB==0xFF;
    PORTC=0xFF;
    char a[15];
    int i, ct=1;
    while(1)
    {
        txrs("Enter password : ");
        __delay_ms(30);
        rxrs(&a);
        __delay_ms(30);
        if(strcmp(a,"admin")==0)
        {
            txrs("Welcome admin");
            while(1)
            {
                PORTB=0x01;
                __delay_ms(50);
                for(i=0;i<8;i++)
                {
                    PORTB<<=1;
                    __delay_ms(200);
                }
            }
        }
        else 
        {
            txrs("INTRUDER.!!");
            if(ct<4)
                ct++;
            else
            {
                txrs("BLOCKED.!!\n\rCONTACT TECHNICIAN");
                while(1)
                {
                    PORTC=0x80;
                    __delay_ms(500);
                }
            }
        }
    }
}

void txr(char a)
{
    TXREG=a;
    while(!TXIF);
}

char rxr()
{
    while(!RCIF);
    txr(RCREG);
    __delay_ms(30);
    return RCREG;
}

void txrs(char *p)
{
    txr('\r');
    __delay_ms(30);
    txr('\n');
    __delay_ms(30);
    while(*p)
    {
        txr(*p);
        __delay_ms(30);
        p++;
    }
}

void rxrs(char *p)
{
    while(1)
    {
        *p=rxr();
        __delay_ms(30);
        if(*p=='\r')
            break;
        else p++;
    }
    *p='\0';
}
