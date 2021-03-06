
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
{ int i=0, j=0;
  TRISB=0x00;
  TRISC=0x00;
  while(1)
  { RC3=~1;
    RC4=~1;
    __delay_ms(100);
    RC2=~1;
    RC5=~1;
    __delay_ms(100);
    RC1=~1;
    RC6=~1;
    __delay_ms(100);
    RC0=~1;
    RC7=~1;
    __delay_ms(100);
    __delay_ms(100);
    RB0=~1;
    __delay_ms(100);
    RB1=~1;
    __delay_ms(100);
    RB2=~1;
    __delay_ms(100);
    RB3=~1;
    __delay_ms(100);
    RB4=~1;
    __delay_ms(100);
    RB5=~1;
    __delay_ms(100);
    RB6=~1;
    __delay_ms(100);
    RB7=~1;
    __delay_ms(100);
    __delay_ms(100);
    RC3=~0;
    RC4=~0;
    __delay_ms(100);
    RC2=~0;
    RC5=~0;
    __delay_ms(100);
    RC1=~0;
    RC6=~0;
    __delay_ms(100);
    RC0=~0;
    RC7=~0;
    __delay_ms(100);
    __delay_ms(100);
    RB0=~0;
    __delay_ms(100);
    RB1=~0;
    __delay_ms(100);
    RB2=~0;
    __delay_ms(100);
    RB3=~0;
    __delay_ms(100);
    RB4=~0;
    __delay_ms(100);
    RB5=~0;
    __delay_ms(100);
    RB6=~0;
    __delay_ms(100);
    RB7=~0;
    __delay_ms(100);
   
  }
}
