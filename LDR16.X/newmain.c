

// PIC16F877A Configuration Bit Settings

// 'C' source line config statements

// CONFIG
#pragma config FOSC = HS        // Oscillator Selection bits (XT oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = ON       // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = ON         // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3/PGM pin has PGM function; low-voltage programming enabled)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
#define _XTAL_FREQ 8000000

void adc_init() //Initialize ADC conversion
{
    //Conversion clock rate = Fosc/32
    ADCS2 = 0;
    ADCS1 = 1;
    ADCS0 = 0;
    //Select channel 0
    CHS2 = 0;
    CHS1 = 0;
    CHS0 = 0;
    ADFM = 1;
    //Turn on ADC
    ADON = 1;
    //Configure interrupt
    ADIF = 0;
    ADIE = 1;
    PEIE = 1;
    GIE = 1;
    __delay_us(20);
}

void __interrupt() adc_done(){
    if(ADIF == 1){
       PORTD = ADRESH;
       PORTB = ADRESL;
    }
    ADIF = 0;
    __delay_us(20);
    return;
}

void main(void) {
    adc_init();
    TRISB = 0;
    TRISD = 0;
    while(1){
        ADCON0 = ADCON0 | 0b00000100; //set GO/DONE bit
    }
    return;
}