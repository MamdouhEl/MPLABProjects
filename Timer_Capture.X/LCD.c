#define _XTAL_FREQ 8000000

#include "xc.h"
/*
 * Using PORTD and bit RD0 is RS, bit RD1 is E and D4-D7 are RD4-RD7
 */
void delay(int N) 
{   
    int i;
    for(i = 0; i < N; i++){__delay_ms(10);}
} 

void initLCD(void){
    
    TRISD = 0x00;
    RD0 = 0;
    //Initializing LCD to use 4 communication lines 
    delay(50);
    
    RD4 = 0;
    RD5 = 1;
    RD6 = 0;
    RD7 = 0;
//PORTDbits.RD5 = 1;
    delay(50);
    RD1 = 1;
    delay(100);
    RD1 = 0;
    delay(100);

//COnfigure blinking cursor
    RD4 = 0;
    delay(50);
    RD1 = 1;
    delay(50);
    RD1 = 0;
    delay(50);
    RD4 = 1;
    RD5 = 1;
    RD6 = 1;
    RD7 = 1;
    delay(50);
    RD1 = 1;
    delay(50);
    RD1 = 0;
    delay(50);
}

void WriteNumber(int number){
    int SBit = 0;
    RD0 = 1;
    int i;
    for(i = 0; i < 2; i++){
        if(i == 0){
            SBit = (number & 0xF0) >> 4;
        }else{
            SBit = (number & 0x0F);
        }
    
    
        if(SBit == 0){

            RD0 = 1;
            RD1 = 0;
            RD2 = 0;
            RD3 = 0;
            RD4 = 1;
            RD5 = 1;
            RD6 = 0;
            RD7 = 0;
            delay(50);
            RD1 = 1;
            delay(50);
            RD1 = 0;
            delay(50);
            RD0 = 1;
            RD1 = 0;
            RD2 = 0;
            RD3 = 0;
            RD4 = 0;
            RD5 = 0;
            RD6 = 0;
            RD7 = 0;
            delay(50);
            RD1 = 1;
            delay(50);
            RD1 = 0;
            delay(50);
        }
//        if(SBit == 1){
//
//            LATB |= 0x3100;
//            delay(50);
//            LATBbits.LATB9 = 1;
//            delay(50);
//            LATBbits.LATB9 = 0;
//            delay(50);
//            LATB |= 0x1100;
//            delay(50);
//            LATBbits.LATB9 = 1;
//            delay(50);
//            LATBbits.LATB9 = 0;
//            delay(50);
//        }
//        if(SBit == 2){
//
//            LATB |= 0x3100;
//            delay(50);
//            LATBbits.LATB9 = 1;
//            delay(50);
//            LATBbits.LATB9 = 0;
//            delay(50);
//            LATB |= 0x2100;
//            delay(50);
//            LATBbits.LATB9 = 1;
//            delay(50);
//            LATBbits.LATB9 = 0;
//            delay(50);
//        }
//        if(SBit == 3){
//
//            LATB |= 0x3100;
//            delay(50);
//            LATBbits.LATB9 = 1;
//            delay(50);
//            LATBbits.LATB9 = 0;
//            delay(50);
//            LATB |= 0x3100;
//            delay(50);
//            LATBbits.LATB9 = 1;
//            delay(50);
//            LATBbits.LATB9 = 0;
//            delay(50);
//        }
//        if(SBit == 4){
//
//            LATB |= 0x3100;
//            delay(50);
//            LATBbits.LATB9 = 1;
//            delay(50);
//            LATBbits.LATB9 = 0;
//            delay(50);
//            LATB |= 0x4100;
//            delay(50);
//            LATBbits.LATB9 = 1;
//            delay(50);
//            LATBbits.LATB9 = 0;
//            delay(50);
//        }
//        if(SBit == 5){
//
//            LATB |= 0x3100;
//            delay(50);
//            LATBbits.LATB9 = 1;
//            delay(50);
//            LATBbits.LATB9 = 0;
//            delay(50);
//            LATB |= 0x5100;
//            delay(50);
//            LATBbits.LATB9 = 1;
//            delay(50);
//            LATBbits.LATB9 = 0;
//            delay(50);
//        }
//        if(SBit == 6){
//
//            LATB |= 0x3100;
//            delay(50);
//            LATBbits.LATB9 = 1;
//            delay(50);
//            LATBbits.LATB9 = 0;
//            delay(50);
//            LATB |= 0x6100;
//            delay(50);
//            LATBbits.LATB9 = 1;
//            delay(50);
//            LATBbits.LATB9 = 0;
//            delay(50);
//        }
//        if(SBit == 7){
//
//            LATB |= 0x3100;
//            delay(50);
//            LATBbits.LATB9 = 1;
//            delay(50);
//            LATBbits.LATB9 = 0;
//            delay(50);
//            LATB |= 0x7100;
//            delay(50);
//            LATBbits.LATB9 = 1;
//            delay(50);
//            LATBbits.LATB9 = 0;
//            delay(50);
//        }
//        if(SBit == 8){
//
//            LATB |= 0x3100;
//            delay(50);
//            LATBbits.LATB9 = 1;
//            delay(50);
//            LATBbits.LATB9 = 0;
//            delay(50);
//            LATB |= 0x8100;
//            delay(50);
//            LATBbits.LATB9 = 1;
//            delay(50);
//            LATBbits.LATB9 = 0;
//            delay(50);
//        }
//        if(SBit == 9){
//
//            LATB |= 0x3100;
//            delay(50);
//            LATBbits.LATB9 = 1;
//            delay(50);
//            LATBbits.LATB9 = 0;
//            delay(50);
//            LATB |= 0x9100;
//            delay(50);
//            LATBbits.LATB9 = 1;
//            delay(50);
//            LATBbits.LATB9 = 0;
//            delay(50);
//        }
//        if(SBit == 10){
//
//            LATB |= 0x4100;
//            delay(50);
//            LATBbits.LATB9 = 1;
//            delay(50);
//            LATBbits.LATB9 = 0;
//            delay(50);
//            LATB |= 0x1100;
//            delay(50);
//            LATBbits.LATB9 = 1;
//            delay(50);
//            LATBbits.LATB9 = 0;
//            delay(50);
//        }
//        if(SBit == 11){
//
//            LATB |= 0x4100;
//            delay(50);
//            LATBbits.LATB9 = 1;
//            delay(50);
//            LATBbits.LATB9 = 0;
//            delay(50);
//            LATB |= 0x2100;
//            delay(50);
//            LATBbits.LATB9 = 1;
//            delay(50);
//            LATBbits.LATB9 = 0;
//            delay(50);
//        }
//        if(SBit == 12){
//
//            LATB |= 0x4100;
//            delay(50);
//            LATBbits.LATB9 = 1;
//            delay(50);
//            LATBbits.LATB9 = 0;
//            delay(50);
//            LATB |= 0x3100;
//            delay(50);
//            LATBbits.LATB9 = 1;
//            delay(50);
//            LATBbits.LATB9 = 0;
//            delay(50);
//        }
//        if(SBit == 13){
//
//            LATB |= 0x4100;
//            delay(50);
//            LATBbits.LATB9 = 1;
//            delay(50);
//            LATBbits.LATB9 = 0;
//            delay(50);
//            LATB |= 0x4100;
//            delay(50);
//            LATBbits.LATB9 = 1;
//            delay(50);
//            LATBbits.LATB9 = 0;
//            delay(50);
//        }
//        if(SBit == 14){
//
//            LATB |= 0x4100;
//            delay(50);
//            LATBbits.LATB9 = 1;
//            delay(50);
//            LATBbits.LATB9 = 0;
//            delay(50);
//            LATB |= 0x5100;
//            delay(50);
//            LATBbits.LATB9 = 1;
//            delay(50);
//            LATBbits.LATB9 = 0;
//            delay(50);
//        }
//        if(SBit == 15){
//
//            LATB |= 0x4100;
//            delay(50);
//            LATBbits.LATB9 = 1;
//            delay(50);
//            LATBbits.LATB9 = 0;
//            delay(50);
//            LATB |= 0x6100;
//            delay(50);
//            LATBbits.LATB9 = 1;
//            delay(50);
//            LATBbits.LATB9 = 0;
//            delay(50);
//        }
    }
}
