/*
 * File:   newmain.c
 * Author: Mamdouh
 *
 * Created on October 22, 2021, 10:18 PM
 */

// PIC16F877A Configuration Bit Settings

// 'C' source line config statements

// CONFIG
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = ON        // Watchdog Timer Enable bit (WDT enabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = ON       // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = ON         // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3/PGM pin has PGM function; low-voltage programming enabled)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#define _XTAL_FREQ 8000000

#include <xc.h>
#include "LCD.h"

volatile int count = 0;
volatile int capture = 0;
volatile float T1 = 0.0;
volatile float T2 = 0.0;
//void __interrupt() ISR(void){
//    
//    if(CCP1IF == 1){
//        
//        if(capture == 0){
//            T1 = (CCPR1H << 8 + CCPR1L) * 0.0005;
//            TMR1ON = 1;
//            
//        }else{
//            
//            T2 = (CCPR1H << 8 + CCPR1L) * 0.0005 + (count - 1) * 33;
//            
//        }
//        
//        capture++;
//        CCP1IF = 0;
//    }
//    if(TMR1IF == 1){
//        if(T1!=0){
//            
//            count++;
//            
//        }
//        TMR1IF = 0;
//        
//    }
//    
//}
//void main(void) {
//    
//    GIE = 1;
//    PEIE = 1;
//    CCP1IE = 1;
//    TMR1IE = 1;
//    TRISB0 = 0;
//    TRISC2 = 1;
//    CCP1CON = 0x05;
//    
//    
//    
//    
//    return;
//}
void main(void){
    initLCD();
    WriteNumber(0);
    
}