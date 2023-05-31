/*
 * File:   newmain.c
 * Author: Mamdouh
 *
 * Created on November 6, 2021, 2:17 PM
 */



// PIC18F452 Configuration Bit Settings

// 'C' source line config statements

// CONFIG1H
#pragma config OSC = HS         // Oscillator Selection bits (HS oscillator)
#pragma config OSCS = OFF       // Oscillator System Clock Switch Enable bit (Oscillator system clock switch option is disabled (main oscillator is source))

// CONFIG2L
#pragma config PWRT = OFF       // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOR = ON         // Brown-out Reset Enable bit (Brown-out Reset enabled)
#pragma config BORV = 20        // Brown-out Reset Voltage bits (VBOR set to 2.0V)

// CONFIG2H
#pragma config WDT = OFF         // Watchdog Timer Enable bit (WDT enabled)
#pragma config WDTPS = 128      // Watchdog Timer Postscale Select bits (1:128)

// CONFIG3H
#pragma config CCP2MUX = ON     // CCP2 Mux bit (CCP2 input/output is multiplexed with RC1)

// CONFIG4L
#pragma config STVR = ON        // Stack Full/Underflow Reset Enable bit (Stack Full/Underflow will cause RESET)
#pragma config LVP = OFF        // Low Voltage ICSP Enable bit (Low Voltage ICSP disabled)

// CONFIG5L
#pragma config CP0 = OFF        // Code Protection bit (Block 0 (000200-001FFFh) not code protected)
#pragma config CP1 = OFF        // Code Protection bit (Block 1 (002000-003FFFh) not code protected)
#pragma config CP2 = OFF        // Code Protection bit (Block 2 (004000-005FFFh) not code protected)
#pragma config CP3 = OFF        // Code Protection bit (Block 3 (006000-007FFFh) not code protected)

// CONFIG5H
#pragma config CPB = OFF        // Boot Block Code Protection bit (Boot Block (000000-0001FFh) not code protected)
#pragma config CPD = OFF        // Data EEPROM Code Protection bit (Data EEPROM not code protected)

// CONFIG6L
#pragma config WRT0 = OFF       // Write Protection bit (Block 0 (000200-001FFFh) not write protected)
#pragma config WRT1 = OFF       // Write Protection bit (Block 1 (002000-003FFFh) not write protected)
#pragma config WRT2 = OFF       // Write Protection bit (Block 2 (004000-005FFFh) not write protected)
#pragma config WRT3 = OFF       // Write Protection bit (Block 3 (006000-007FFFh) not write protected)

// CONFIG6H
#pragma config WRTC = OFF       // Configuration Register Write Protection bit (Configuration registers (300000-3000FFh) not write protected)
#pragma config WRTB = OFF       // Boot Block Write Protection bit (Boot Block (000000-0001FFh) not write protected)
#pragma config WRTD = OFF       // Data EEPROM Write Protection bit (Data EEPROM not write protected)

// CONFIG7L
#pragma config EBTR0 = OFF      // Table Read Protection bit (Block 0 (000200-001FFFh) not protected from Table Reads executed in other blocks)
#pragma config EBTR1 = OFF      // Table Read Protection bit (Block 1 (002000-003FFFh) not protected from Table Reads executed in other blocks)
#pragma config EBTR2 = OFF      // Table Read Protection bit (Block 2 (004000-005FFFh) not protected from Table Reads executed in other blocks)
#pragma config EBTR3 = OFF      // Table Read Protection bit (Block 3 (006000-007FFFh) not protected from Table Reads executed in other blocks)

// CONFIG7H
#pragma config EBTRB = OFF      // Boot Block Table Read Protection bit (Boot Block (000000-0001FFh) not protected from Table Reads executed in other blocks)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.


#define _XTAL_FREQ 8000000
#include <xc.h>

#define LcdDataBus      PORTD
#define LcdControlBus   PORTB

#define LcdDataBusDirnReg   TRISD
#define LcdCtrlBusDirnReg   TRISB

#define LCD_RS     0
#define LCD_RW     1
#define LCD_EN     2

void Lcd_DataWrite(char dat);
void Lcd_CmdWrite(char cmd);
char i,a[]={"Good!"}, b[]={"Transmitted!"};
char FByte;
char SByte;
int TByte;
int count = 0;
void __interrupt() ISR(void){
    
    if(RCIF == 1){
        
        if(OERR == 1){
            
            CREN = 0;
            CREN = 1;
            return;
            
        }
        for(i=0;a[i]!=0;i++)
        {
            Lcd_DataWrite(a[i]);
        }
        Lcd_CmdWrite(0xc0);        //Go to Next line and display Good Morning
        FByte = RCREG;

        Lcd_DataWrite(FByte);

        __delay_ms(500);
        Lcd_CmdWrite(0x01);        // Clear Display
        Lcd_CmdWrite(0x80);        // Move the cursor to beginning of first line


      }
//    if(TXIF == 1){
//        Lcd_CmdWrite(0x01);        // Clear Display
//        Lcd_CmdWrite(0x80);        // Move the cursor to beginning of first line
//        for(i=0;b[i]!=0;i++)
//        {
//            Lcd_DataWrite(b[i]);
//        }
//        Lcd_DataWrite(count);
//        count++;
////        TXEN=0;
//    }
        
    return;
        
    }
    



/* Function to send the command to LCD */
void Lcd_CmdWrite(char cmd)
{
    LcdDataBus = cmd;               //Send the Command nibble
    LcdControlBus &= ~(1<<LCD_RS);  // Send LOW pulse on RS pin for selecting Command register
    LcdControlBus &= ~(1<<LCD_RW);  // Send LOW pulse on RW pin for Write operation
    LcdControlBus |= (1<<LCD_EN);   // Generate a High-to-low pulse on EN pin
    __delay_us(100);
    LcdControlBus &= ~(1<<LCD_EN); 

    __delay_us(10000);
}


/* Function to send the Data to LCD */
void Lcd_DataWrite(char dat)
{
    LcdDataBus = dat;               //Send the data on DataBus nibble
    LcdControlBus |= (1<<LCD_RS);   // Send HIGH pulse on RS pin for selecting data register
    LcdControlBus &= ~(1<<LCD_RW);  // Send LOW pulse on RW pin for Write operation
    LcdControlBus |= (1<<LCD_EN);   // Generate a High-to-low pulse on EN pin
    __delay_us(100);
    LcdControlBus &= ~(1<<LCD_EN);

    __delay_us(10000);
}

void put_c(char c){
    
//    if(!TRMT){

        TXREG = c; 

//    }
    
}

void put_s(char* s){
    
    char CR = 0x0d;
    char LF = 0x0a;
    int j=0;
    while(s){
//        __delay_ms(10);
        put_c(*s);
        s++;
        
    }
    
//    put_c(LF);
//    put_c(CR);
    
}

void main(void) {
    
    GIE = 1;
    PEIE = 1;
    
    SPEN = 1; // Enabling Serial Communication
    
    BRGH = 1; // High speed Asynchronous comm.
    SPBRG = 12;// Setting Baud Rate to 38400; Baud Rate = Fosc / 16*(SPBRG + 1)
    SYNC = 0;
    
    TRISC6 = 0;
    TRISC7 = 1;
//    TRISB2 = 0;
    TXIE = 1;
    RCIE = 1;
    CREN = 1;
    
    
    char i,a[]={"Good morning!"};

    LcdDataBusDirnReg = 0x00;  // Configure all the LCD pins as output
    LcdCtrlBusDirnReg = 0x00;  // Configure the Ctrl pins as output


    Lcd_CmdWrite(0x38);        // enable 5x7 mode for chars 
    Lcd_CmdWrite(0x0E);        // Display OFF, Cursor ON
    Lcd_CmdWrite(0x01);        // Clear Display
    Lcd_CmdWrite(0x80);        // Move the cursor to beginning of first line


    
    char s[] = {"AT+ADDR?\r\n"};

    TXEN = 1;
    put_s(s);
    
//        __delay_ms(2000);
//    __delay_ms(2000);
    while(1){
        
//        if(count == 10){
//            
//            TXEN = 0;
//            
//        }
        
    }
    
    return;
}
