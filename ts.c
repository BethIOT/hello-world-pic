
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
    int i=0;
    char a[]="Bethsay Tom Varughese";
    TXSTA=0x24;
    RCSTA=0x90;
    SPBRG=25;
    while(1)
    {
        for(i=0;a[i]!='\0';i++)
        {
            TXREG=a[i];
            while(!TRMT);
            __delay_ms(25);
        }
        TXREG='\n';
        while(!TRMT);
        TXREG='\r';
        while(!TRMT);
        __delay_ms(500);
    }
}