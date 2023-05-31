/* 
 * File:   UART.h
 * Author: Mamdouh
 *
 * Created on November 7, 2021, 10:52 PM
 */


void UART_Init(int baudRate);
void UART_TxChar(char ch);
void UART_TxString(char* a);
char UART_RxChar();
