

#include "p24FJ64GB002.h"


void set_pin(){
    AD1PCFGL=0XFFFF;            
    TRISA = 0X0001;             
    TRISB = 0XFFFF;
    
__builtin_write_OSCCONL(OSCCON & 0xBF);

//************************************************************
//***************************
// ASIGNACION U1Rx A Pin RP0
//***************************
RPINR18bits.U1RXR = 0;  //PIN 4   
//***************************
// ASIGNACION U2RX A Pin RP1
//***************************
RPINR19bits.U2RXR = 1;  //PIN 5            
//************************************************************
// CONFIGUARACIÓN DE PINES DE SALIDA DE UART
//************************************************************
//***************************
// ASIGNACION U1Tx A Pin RP2
//***************************
RPOR1bits.RP2R = 3;   //PIN 6                
//***************************
//ASIGNACIO  U2TX A Pin RP3
//***************************
RPOR1bits.RP3R = 5;    //PIN 7
//************************************************************
//ASIGNACION DE PINES DE PWM
//************************************************************
RPOR7bits.RP15R = 18;   //PWM 1 PIN 26
RPOR7bits.RP14R = 19;   //PWM 2 PIN 25
RPOR6bits.RP13R = 20;   //PWM 3 PIN 24
RPOR5bits.RP11R = 21;   //PWM 4 PIN 11
    
__builtin_write_OSCCONL(OSCCON | 0x40);
}