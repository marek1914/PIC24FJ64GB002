#include "type.h" 

#ifndef XC_HEADER_TEMPLATE_H
#define	XC_HEADER_TEMPLATE_H

#define UART_1 1
#define UART_2 2
#define ONE_BIT 0
#define TWO_BIT 1
#define NONE 0
#define EVEN 1
#define ODD  2

u16 set_baud(u8 est,int baud);
void uart_write(u8 uart,u8 tx);
void uart_print(u8 uart,char *msm);
u8 uart_read(u8 uart);
void uart_enable(u8 uart,u8 on_off);
void stop_bit(u8 uart,u8 stop_bits);
void paridad(u8 uart, u8 par, u8 len);
void init_uart(u8 uart,int baud, u8 parity, u8 leng, u8 stop_bits );
char * uart_GetString(u8 uart);

#endif	/* XC_HEADER_TEMPLATE_H */

