/*
 * File:   newmain.c
 * Author: Mamdouh
 *
 * Created on October 23, 2021, 3:59 PM
 */


// PIC16F877A Configuration Bit Settings

// 'C' source line config statements

// CONFIG
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = ON       // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.


#define _XTAL_FREQ 4000000
#include <xc.h>

void __interrupt() ISR(void){
    
    if(CCP1IF ==1){
        
        
        if(CCP1CON == 0x08){
            
            CCP1CON = 0x09;
            
        }else{
            
            CCP1CON = 0x08;
            
        }
        TMR1ON = 0;
        CCP1IF = 0;
        TMR1ON = 1;
    }
     
}
void main(void) {
    
    
    GIE = 1;
    PEIE = 1;
    CCP1IE = 1;
    CCP1CON = 0x08;
    T1CON = 0x30;
    CCPR1 = 0xFFFF;
    TRISC2 = 0;
    TMR1ON = 1;
    
    while(1){
        
  
    }
    
    return;
}
