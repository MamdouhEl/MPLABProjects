# 1 "LCD.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:/Program Files/Microchip/MPLABX/v5.50/packs/Microchip/PIC16Fxxx_DFP/1.2.33/xc8\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "LCD.c" 2
# 13 "LCD.c"
void Lcd_CmdWrite(char cmd)
{
    PORTD = cmd;
    PORTB &= ~(1<<0);
    PORTB &= ~(1<<1);
    PORTB |= (1<<2);
    __delay_us(100);
    PORTB &= ~(1<<2);

    __delay_us(10000);
}



void Lcd_DataWrite(char dat)
{
    PORTD = dat;
    PORTB |= (1<<0);
    PORTB &= ~(1<<1);
    PORTB |= (1<<2);
    __delay_us(100);
    PORTB &= ~(1<<2);

    __delay_us(10000);
}
