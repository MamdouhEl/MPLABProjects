#include <xc.h>
#define _XTAL_FREQ 16000000
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = ON        // Watchdog Timer Enable bit (WDT enabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = ON       // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = ON         // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3/PGM pin has PGM function; low-voltage programming enabled)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

volatile int system = 0;
void main(void) {  
    TRISB=TRISB & 0b11111000;
    TRISA0=1;
    ADCON1=0b11001110;
    ADCON0=0b10000001;
    ADIF=0;
    ADIE=1;
    PEIE=1;
    GIE=1;
    
   
    TRISD7 = 1;//SENSOR
    TRISD6 = 1;//error keypad
    TRISD5 = 1;//system input button
    TRISD4 = 0;//BUZZER
    TRISC7 = 1;//right password
    //TRISC6 = 0;//KEYpad only open the system 
    TRISC5 = 0;//system output
    TRISC4 = 1;//system input
    //there is a button only when push it will close the system (locked))
     
    while(1){
        ADCON0=0b10000101;//ldr
        RD4 = 0;
        if(RD7 == 1 && RC4==0){
            buzzer();
            __delay_ms(100);
        }
        if(RD6 == 1){
            buzzer();
                __delay_ms(100);
        }
        if(RD5 == 1){
            RC5 = 0;
            __delay_ms(100);
        }
        if(RC7 ==1){
            RC5 = 1;
             __delay_ms(100);
        }
     
    }
    return;
}
int buzzer(){
    __delay_ms(100);
    RD4 = 1;
    __delay_ms(5000);
    RD4 = 0;
    return 0;
}
void __interrupt() ISR(){
    if(ADIF){
         // data is now in the ADRESSH & ADRESSL
       
        if (ADRESH == 0x00 || RC4 == 0)
            {
            RB0 = 1;
            RB1 = 1;
            RB2 = 1;
        }
        else if (ADRESH == 0b00000011)
        {
            RB0 = 0;
            RB1 = 0;
            RB2 = 0;
        }
        else if (ADRESH == 0b00000010)
        {
            RB0 = 1;
            RB1 = 0;
            RB2 = 0;
        }
        else if (ADRESH == 0b00000001)
        {
            RB0 = 1;
            RB1 = 1;
            RB2 = 0;
        }
        
       ADIF=0;
      // ADCON0 = ADCON0 | 0b00000100;
    }
    return;
}