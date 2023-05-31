/*
 * File:   newmain.c
 * Author: Mamdouh
 *
 * Created on October 23, 2021, 11:39 PM
 */


// PIC16F877A Configuration Bit Settings

// 'C' source line config statements

// CONFIG
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
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
#define _XTAL_FREQ 4000000
//void __interrupt() ISR(void)
//{
//        if (INTF==1) //External Interrupt detected
//        { 
//            if(PR2 > CCPR1L){
//                
//                CCPR1L += 1;
//                
//                
//            }else{
//                
//                CCPR1L = 1;
//                
//            }
//            
//            __delay_ms(30);
//            INTF = 0; // clear the interrupt flag after done with it
//            
//        }
//}

void main(void) {
    
    TRISB0 = 1; //RB0 as Input PIN
//    GIE = 1;
//    INTE = 1;       //Enable RB0 as external Interrupt pin
    
    TRISC2 = 0;
    PR2 = 10;
    CCPR1L = 1;
    CCP1CON = 0x0C;
    T2CON = 0x04;
    int laststate = 0;
    while(1){
        
        if(RB0 != laststate){
            __delay_ms(30);
            if(RB0 != laststate){
                laststate = RB0;
                if(PR2 > CCPR1L){
                
                CCPR1L += 1;
                
                
            }else{
                
                CCPR1L = 1;
                
            }
                
            }

        }
    }
    return;
}
