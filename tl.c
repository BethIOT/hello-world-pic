
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

int main()
{
    int count=0;
    TRISB=0X00;
    OPTION_REG=0X07; // xtal[t0sc]; TMR0[psa]; pre-scale=1:256[000];
    while(1)
    {
//        if(TMR0==0xAA)
//            PORTB=~TMR0;
        if(TMR0IF==1)
        {
            TMR0IF=0;
//            PORTB=~PORTB;
            count++;
        }
        if((count%10)==0)
        {
            PORTB=~count;
            __delay_ms(200);
            PORTB=0xFF;
        }
    }
}