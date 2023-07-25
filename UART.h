/* 
 * File:   UART.h
 * Author: Luis Antunez
 *
 * Created on 21 de julio de 2023, 01:16 PM
 */

#ifndef UART_H
#define	UART_H
#include <xc.h>

void UART_RX_config (uint16_t baudrate);
void UART_TX_config (uint16_t baudrate);
void UART_write_char (char *c);
char UART_read_char ();

#endif	/* UART_H */

