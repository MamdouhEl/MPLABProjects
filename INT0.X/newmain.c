/*
 * File:   newmain.c
 * Author: Mamdouh
 *
 * Created on October 16, 2021, 10:11 PM
 */

#define _XTAL_FREQ 8000000

// PIC16F877A Configuration Bit Settings

// 'C' source line config statements

// CONFIG
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = ON        // Watchdog Timer Enable bit (WDT enabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = ON       // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>

void __interrupt() ISR(void)
{
        if (INTF==1) //External Interrupt detected
        { 
            RB2 = 1;
            RB3 = 1;
            __delay_ms(2000);
            RB2 = 0;
            RB3 = 0;
            INTF = 0; // clear the interrupt flag after done with it
            
        }
}


void main(void) {
    
    TRISB0 = 1; //RB0 as Input PIN
    TRISB1 = 1; //RB1 as Input PIN
    TRISB2 = 0; //RB2 as Output PIN
    TRISB3 = 0; //RB2 as Output PIN
    GIE = 1;
    INTE = 1;       //Enable RB0 as external Interrupt pin
    
    int count = 0;
    int laststate = 0;
    while(1){
        
        if(RB1 != laststate){
            __delay_ms(30);
            if(RB1 != laststate){
                
                laststate = RB1;
                count++;
                
            }

        }

        if(count % 2 == 0){
            
            RB2 = 1;
            RB3 = 0;
        }else{
            
            RB2 = 0;
            RB3 = 1;
        }
        
    }
    
    return;
}
