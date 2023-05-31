/*
 * File:   newmain.c
 * Author: Mamdouh
 *
 * Created on October 22, 2021, 11:49 AM
 */


// PIC16F877A Configuration Bit Settings

// 'C' source line config statements

// CONFIG
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF        // Watchdog Timer Enable bit (WDT enabled)
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
int value = 0;
volatile int count = 0;
void __interrupt() ISR(void){
    if(TMR1IF == 1){
        count++;
        
        if(count == 30){
            
            value = !value;
            count = 0;
            
        }
        TMR1IF = 0; 
    }
    
}

void main(void) {
    
    
    TRISB0 = 0;
    T1CON = 0x01;
    GIE = 1;
    PEIE = 1; 
    TMR1IE = 1;
    RB0 = value;
    
   while(1){   
       RB0 = value;
    }
    return;
}
