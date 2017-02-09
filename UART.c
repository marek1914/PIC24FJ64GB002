#include "UART.h"
#include "system.h"
#include "p24FJ64GB002.h"
#include "type.h"
#include "PPS.h"

u16 set_baud(u8 est,int baud){
    u16 reg;
    if (est){
        reg=4*baud;
        reg=FCY/reg;
        reg=reg-1;
    }    
    else {
        reg=(16)* baud;
        reg=FCY/(reg);
        reg=reg-1;
    }
    return reg;
}


void uart_write(u8 uart,u8 tx){
    if (uart==UART_1){
        while(!U1STAbits.TRMT);
        U1TXREG=tx;
    }
    else if (uart==UART_2){
        while(!U2STAbits.TRMT);
        U2TXREG=tx;
    }
}

u8 uart_read(u8 uart){
    if (uart==UART_1){
        while(!U1STAbits.URXDA);
        return U1RXREG;
    }
    else if (uart==UART_2){
        while(!U2STAbits.URXDA);
        return U2RXREG;
    }
}

void uart_print(u8 uart,char *msm){
    u8 a=0;
    do{
        uart_write(uart,msm[a++]);
    }while (msm[a]!='\r');
    //uart_write(uart,'\n');
    uart_write(uart,'\r');
    //while(uart_read(uart)!='\n');
}

void uart_enable(u8 uart,u8 on_off){
    if (uart==UART_1){
        U1MODEbits.UARTEN=on_off;
        U1STAbits.UTXEN=1;
        
    }
    else if (uart==UART_2){
        U2MODEbits.UARTEN=on_off;
        U2STAbits.UTXEN=1;
    }
}

void stop_bit(u8 uart,u8 stop_bits){
    if (uart==UART_1 && !stop_bits)
        U1MODEbits.STSEL=0;
    else if (uart==UART_1 && stop_bits)
        U1MODEbits.STSEL=1;
    else if (uart==UART_2 && !stop_bits)
        U2MODEbits.STSEL=0;
    else if (uart==UART_2 && stop_bits)
        U2MODEbits.STSEL=1;
}

void paridad(u8 uart, u8 par, u8 len){
    if (uart==UART_1){
        if (len==9)
            U1MODEbits.PDSEL=3;
        else if (len==8 && par==NONE)
             U1MODEbits.PDSEL=0;
        else if (len==8 && par==EVEN)
             U1MODEbits.PDSEL=1;
        else if (len==8 && par==ODD)
             U1MODEbits.PDSEL=2;
    }
    else if (uart==UART_2){
        if (len==9)
            U2MODEbits.PDSEL=3;
        else if (len==8 && par==NONE)
             U2MODEbits.PDSEL=0;
        else if (len==8 && par==EVEN)
             U2MODEbits.PDSEL=1;
        else if (len==8 && par==ODD)
             U2MODEbits.PDSEL=2;
        
    }
}

void init_uart(u8 uart,int baud, u8 parity, u8 leng, u8 stop_bits ){
    if (uart==UART_1){
        U1MODEbits.UEN=0;
        U1MODEbits.BRGH=1;
        U1MODEbits.USIDL=1;//
        U1MODEbits.WAKE=1;//
        U1MODEbits.LPBACK=0;
        U1MODEbits.ABAUD = 0; 
        U1MODEbits.RXINV=0;
        U1STAbits.URXISEL = 0;
        stop_bit(uart,stop_bits);
        U1BRG=10;//set_baud(U1MODEbits.BRGH,baud);
        paridad(uart,parity,leng);      
        uart_enable(UART_1,ON);
    }
    else if (uart==UART_2){
        U2MODEbits.UEN=0;
        U2MODEbits.BRGH=1;
        U2MODEbits.USIDL=1;
        U2MODEbits.WAKE=1;//
        U2MODEbits.LPBACK=0;
        U2MODEbits.ABAUD = 0; 
        U2MODEbits.RXINV=0;
        U2STAbits.URXISEL = 0;
        U2MODEbits.STSEL=0;
        U2BRG=set_baud(U2MODEbits.BRGH,baud);
        paridad(uart,parity,leng);
        uart_enable(UART_2,ON);
    }
}


char * uart_GetString(u8 uart)
{
    u8 i = 0;
    char c;
    static char buffer[80];
    do {
        c = uart_read(uart);
        buffer[i++] = c;
    } while (c != '\r');
    buffer[i++] = '\r';

    //uart_write(uart,'\n');
    return (buffer);
}