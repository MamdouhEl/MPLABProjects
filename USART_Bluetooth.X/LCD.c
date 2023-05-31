#include <xc.h>

#define _XTAL_FREQ 20000000

#define LcdDataBus      PORTD
#define LcdControlBus   PORTB

#define LcdDataBusDirnReg   TRISD
#define LcdCtrlBusDirnReg   TRISB

#define LCD_RS     0
#define LCD_RW     1
#define LCD_EN     2


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
