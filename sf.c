// PIC16F876A Configuration Bit Settings

// 'C' source line config statements

#include <xc.h>

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

      // Flash Program Memory Code Protection bit (Code protection off)

int main()
{
    int i, tmp;
    TRISC=0x00;
    TRISB=0xFF;
    while(1)
    {
        if(RB0==0)
        {
            PORTC=~0x00;
            tmp=0x01;
            for(i=0;i<8;i++)
            {
                __delay_ms(300);
                PORTC=~tmp;
                tmp<<=1;
            }
            __delay_ms(300);
            PORTC=~0x00;
            tmp=0x80;
            for(i=0;i<8;i++)
            {
                __delay_ms(300);
                PORTC=~tmp;
                tmp>>=1;
            }
            __delay_ms(300);
        }
        else if(RB1==0)
        {
            PORTC=~0x00;
            tmp=0x80;
            for(i=0;i<8;i++)
            {
                __delay_ms(300);
                PORTC=~tmp;
                tmp>>=1;
            }
            __delay_ms(300);
            PORTC=~0x00;
            tmp=0x01;
            for(i=0;i<8;i++)
            {
                __delay_ms(300);
                PORTC=~tmp;
                tmp<<=1;
            }
            __delay_ms(300);
        }
        else if(RB2==0)
        {
            PORTC=0xFF;
            for(i=0;i<8;i++)
            {
                __delay_ms(300);
                PORTC<<=1;
            }
            PORTC=0x00;
            tmp=0xFF;
            for(i=0;i<=8;i++)
            {
                __delay_ms(300);
                PORTC=~tmp;
                tmp>>=1;
            }
        }
        else if(RB3==0)
        {
            PORTC=0x00;
            tmp=0xFF;
            for(i=0;i<=8;i++)
            {
                __delay_ms(300);
                PORTC=~tmp;
                tmp>>=1;
            }
            PORTC=0xFF;
            for(i=0;i<8;i++)
            {
                __delay_ms(300);
                PORTC<<=1;
            }
            __delay_ms(300);
        }
        else
        {
            PORTC=0XFF;
        }
    }

}
