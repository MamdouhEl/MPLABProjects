#include <xc.h>

#define _XTAL_FREQ 20000000

#define SBIT_TXEN     5
#define SBIT_SPEN     7
#define SBIT_CREN     4



void UART_Init(int baudRate)
{    
    TRISC=0x80;            // Configure Rx pin as input and Tx as output  
    TXSTA=(1<<SBIT_TXEN);  // Asynchronous mode, 8-bit data & enable transmitter
    RCSTA=(1<<SBIT_SPEN) | (1<<SBIT_CREN);  // Enable Serial Port and 8-bit continuous receive
    SPBRG = (20000000UL/(long)(64UL*baudRate))-1;      // baud rate @20Mhz Clock
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
void UART_TxString(char a[]){
    
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
