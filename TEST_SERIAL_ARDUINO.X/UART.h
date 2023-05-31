/* 
 * File:   UART.h
 * Author: Mamdouh
 *
 * Created on November 7, 2021, 10:52 PM
 */

#ifndef UART_H
#define	UART_H

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* UART_H */
void UART_Init(int baudRate);
void UART_TxChar(char ch);
void UART_TxString(char* a);
char UART_RxChar();
