/*
 * File:   newmain.c
 * Author: Mamdouh
 *
 * Created on November 7, 2021, 11:05 AM
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

#define SBIT_TXEN     5
#define SBIT_SPEN     7
#define SBIT_CREN     4
#define SBIT_BRGH     2


void UART_Init(int baudRate)
{    
    TRISC=0x80;            // Configure Rx pin as input and Tx as output  
    TXSTA=(1<<SBIT_TXEN) | (1<<SBIT_BRGH);  // Asynchronous mode, 8-bit data & enable transmitter
    RCSTA=(1<<SBIT_SPEN) | (1<<SBIT_CREN);  // Enable Serial Port and 8-bit continuous receive
    SPBRG = (20000000UL/(long)(16UL*baudRate));      // baud rate @20Mhz Clock
}


void UART_TxChar(char ch)
{
    while(TXIF==0);    // Wait till the transmitter register becomes empty
    TXIF=0;            // Clear transmitter flag
    TXREG=ch;          // load the char to be transmitted into transmit reg
    if(TRMT == 1){
        
        TXREG='\n';
        
    }
    if(TRMT == 1){
        
        TXREG='\r';
        
    }
}
void UART_TxString(char* a){
    
    for(int i=0;a[i]!=0;i++)
    {
        UART_TxChar(a[i]); // Transmit predefined string
    }
    
}

char UART_RxChar()
{
    while(RCIF==0);    // Wait till the data is received 
    RCIF=0;            // Clear receiver flag
    return(RCREG);     // Return the received data to calling function
}
int main()
{
    char i,a[]={"AT"};
    char ch;

    UART_Init(38400);          //Initialize the UART module with 9600 baud rate
    for(i=0;a[i]!=0;i++)
    {
        UART_TxChar(a[i]); // Transmit predefined string
    }

    while(1)
    {
        ch = UART_RxChar(); // Receive a char from serial port
        UART_TxChar(ch);    // Transmit the received char
    }
}