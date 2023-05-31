/*
 * File:   newmain.c
 * Author: Mamdouh Ellamei
 *
 * Created on October 16, 2021, 11:44 AM
 */

#define _XTAL_FREQ 8000000

// 'C' source line config statements

// CONFIG
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = ON        // Watchdog Timer Enable bit (WDT enabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = ON       // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = OFF         // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3/PGM pin has PGM function; low-voltage programming enabled)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>

void main(void) {
    
    TRISB0 = 0; //RB0 as Output PIN
    TRISB1 = 1; //RB1 as Input PIN
    TRISB2 = 0; //RB2 as Output PIN
    int count = 0;
    int laststate = 0;
    while(1){
        
        if(RB1 != laststate){
            laststate = RB1;
            count++;

        }

        if(count % 2 == 0){
            
            RB0 = 1;
            RB2 = 0;
        }else{
            
            RB0 = 0;
            RB2 = 1;
        }
        
    }
    return;
}
