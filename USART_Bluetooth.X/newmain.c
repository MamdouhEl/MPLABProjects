/*
 * File:   newmain.c
 * Author: Mamdouh
 *
 * Created on October 30, 2021, 10:24 AM
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

#define _XTAL_FREQ 20000000
#include <xc.h>
#include "LCD.h"
#include "UART.h"

#define LcdDataBusDirnReg   TRISD
#define LcdCtrlBusDirnReg   TRISB
//int FByte;
//int SByte;

//void __interrupt() ISR(void){
//    
//    if(RCIF == 1){
//        if(OERR == 1){
//            
//            CREN = 0;
//            CREN = 1;
//            return;
//            
//        }
//        
//        FByte = RCREG;
//        SByte = RCREG;
////        RB2 = !RB2;
////        __delay_ms(20);
//        TXEN = 1;
//        TXREG = FByte;
////        while(!TRMT);
////        TXEN = 0;
////        if(FByte == 1){
//        
//        
////        if(SByte != 0){
////
////            TXREG = SByte;
////
////        }
//            
////        }
//        
//    }
//    
//}

//void main(void) {
//    
//    GIE = 1;
//    PEIE = 1;
//    
//    SPEN = 1; // Enabling Serial Communication
//    
//    BRGH = 1; // High speed Asynchronous comm.
//    SPBRG = 25;// Setting Baud Rate to 9600; Baud Rate = Fosc / 16*(SPBRG + 1)
//    SYNC = 0;
//    TXEN = 0; // Disabling Transmit until we receive data
//    TRISC6 = 0;
//    TRISC7 = 1;
//    TRISB2 = 0;
//    RCIE = 1;
//    CREN = 1;
//    RB2 = 0;
//    while(1){
////        if(TRMT == 1){
////            
////            TXEN = 0;
////            
////        }
//    }
//    
//    return;
//}
//void put_c(unsigned char* c){
//    
//    if(!TRMT){
//        
//        TXREG = *c;
//        
//    }
//    
//}
//
//void put_s(char* s){
//    
//    while(*s){
//        
//        put_c(s);
//        s++;
//        
//    }
//    
//}
//void main(void) {
//    
//    GIE = 1;
//    PEIE = 1;
//    
//    SPEN = 1; // Enabling Serial Communication
//    
//    BRGH = 1; // High speed Asynchronous comm.
//    SPBRG = 12;// Setting Baud Rate to 9600; Baud Rate = Fosc / 16*(SPBRG + 1)
//    SYNC = 0;
//    TXEN = 1; // Enabling Transmit
//    TRISC6 = 0;
//    TRISC7 = 1;
//    TRISB2 = 0;
//    TXIE = 1;
//    RCIE = 1;
//    CREN = 1;
//    RB2 = 0;
//    put_s("AT+RMAAD");
//    put_s("AT+ROLE=1");
//    put_s("AT+CMODE=0");
//    put_s("AT+BIND=c0,ee,fb,35,ab,57");
//    put_s("AT+UART=38400,0,0");
//    
//    while(1){
////        if(TRMT == 1){
////            
////            TXEN = 0;
////            
////        }
//    }
//    
//    return;
//}
void main(){
    TRISB7 = 0;
    char x;
    
    LcdDataBusDirnReg = 0x00;  // Configure all the LCD pins as output
    LcdCtrlBusDirnReg = 0x00;  // Configure the Ctrl pins as output


    Lcd_CmdWrite(0x38);        // enable 5x7 mode for chars 
    Lcd_CmdWrite(0x0E);        // Display OFF, Cursor ON
    Lcd_CmdWrite(0x01);        // Clear Display
    Lcd_CmdWrite(0x80);        // Move the cursor to beginning of first line
    
    
    UART_Init(9600);          //Initialize the UART module with 38400 baud rate



    while(1){
        
        x = UART_RxChar();
        RB7 = 1;
//        Lcd_DataWrite(x);
        
    }
}