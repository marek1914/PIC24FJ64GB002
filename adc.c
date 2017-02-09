#include "type.h"
#include "adc.h"
#include "p24FJ64GB002.h"
#include <xc.h>
#define  _XTAL_FREQ 20000000
void adc_init(){
     //Turn on, auto sample start, auto-convert
    
    AD1PCFGbits.PCFG0 = 0; 
    
    
    
    AD1PCFG = 0xFFFE;      // Configure A/D port AN0 input pin is analog
    AD1CON1 = 0x2002;       // Configure sample clock source
    AD1CON2 = 0;           // Configure A/D voltage reference
    AD1CON3 = 0x1FA0;      // Configure sample time = 1Tad,
    AD1CHS  = 0;           // Configure input channels,
    AD1CSSL = 0;           // No inputs are scanned.
    AD1CON1bits.ADON = 1;              // turn ADC ON
}

void adc_enable(u8 estado){
    AD1CON1bits.ADON = estado;              // turn ADC ON
}

u16 analogread(u8 pin){
    int c=0;
    AD1CON1bits.SAMP = 1;          // start sampling, then after 31Tad go to conversion
    while (c<25000)
      c++;
    AD1CON1bits.SAMP = 0; 
    while (!AD1CON1bits.DONE);  // conversion done?
    return ADC1BUF0;          // yes then get ADC value
}
