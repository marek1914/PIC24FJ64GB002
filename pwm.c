#include "system.h"
#include "p24FJ64GB002.h"
#include "type.h"
#include "pwm.h"

void set_freq(u8 modulo,float fre){
    float f=0.0;
    if (modulo==PWM_1){       
        f=1/fre;
        OC1RS=(f*FCY)-1;
    }
    else if (modulo==PWM_2){
        f=1/fre;
        OC2RS=(f*FCY)-1;
    }
    else if (modulo==PWM_3){
        f=1/fre;
        OC3RS=(f*FCY)-1;
    }
    else if (modulo==PWM_4){
        f=1/fre;
        OC4RS=(f*FCY)/64-1;
    }      
}
void set_dutty(u8 modulo, int dutty){
    if (modulo==PWM_1)
        OC1R=dutty;
    else if (modulo==PWM_2)
        OC2R=dutty;
    else if (modulo==PWM_3)
        OC3R=dutty;        
    else if (modulo==PWM_4)
        OC4R=dutty; 
}
  
void init_pwm(u8 modulo, float fre, int dutty){
    if (modulo==PWM_1){
        T2CONbits.TCKPS = 0b00;       //FCY = 10MHz preescaler 1:1
        T2CONbits.TON = 1;            //ENCENDIDO TIMER 2
        OC1CON1 = 0;
        OC1CON2 = 0;
        OC1CON2bits.SYNCSEL = 0x1f;   //
        OC1CON1bits.OCTSEL = 0;       //FUETE TIMER 2
        //OC1CON1bits.OCM = 0b110;      //PWM
        set_freq(modulo,fre);
        set_dutty(modulo,dutty);
    }
    else if (modulo==PWM_2){
        T2CONbits.TCKPS = 0b00;       //FCY = 10MHz preescaler 1:1
        T2CONbits.TON = 1;            //ENCENDIDO TIMER 2
        OC2CON1 = 0;
        OC2CON2 = 0;
        OC2CON2bits.SYNCSEL = 0x1f;   //
        OC2CON1bits.OCTSEL = 0;       //FUETE TIMER 2
        //OC2CON1bits.OCM = 0b110;      //PWM
        set_freq(modulo,fre);
        set_dutty(modulo,dutty);
    }
    else if (modulo==PWM_3){
        T2CONbits.TCKPS = 0b00;       //FCY = 10MHz preescaler 1:1
        T2CONbits.TON = 1;            //ENCENDIDO TIMER 2
        OC3CON1 = 0;
        OC3CON2 = 0;
        OC3CON2bits.SYNCSEL = 0x1f;   //
        OC3CON1bits.OCTSEL = 0;       //FUETE TIMER 2
        //OC3CON1bits.OCM = 0b110;      //PWM
        set_freq(modulo,fre);
        set_dutty(modulo,dutty);       
    }
    else if (modulo==PWM_4){
        T3CONbits.TCKPS = 0b10;       //FCY = 10MHz preescaler 1:8
        T3CONbits.TON = 1;            //ENCENDIDO TIMER 2
        OC4CON1 = 0;
        OC4CON2 = 0;
        OC4CON2bits.SYNCSEL = 0x1f;   //
        OC4CON1bits.OCTSEL = 1;       //FUETE TIMER 2
        //OC3CON1bits.OCM = 0b110;      //PWM
        set_freq(modulo,fre);
        set_dutty(modulo,dutty);       
    }    
    
}
    
void pwm_enable(u8 modulo,u8 on_off ){
    if (modulo==PWM_1 ){
        if (on_off)
            OC1CON1bits.OCM = 0b110;
        else
            OC1CON1bits.OCM = 0;
    }
    else if (modulo==PWM_2){
        if (on_off)
            OC2CON1bits.OCM = 0b110;
        else
            OC2CON1bits.OCM = 0;
    }
    else if (modulo==PWM_3){
        if (on_off)
            OC3CON1bits.OCM = 0b110;
        else
            OC3CON1bits.OCM = 0;
    }
    else if (modulo==PWM_4){
        if (on_off)
            OC4CON1bits.OCM = 0b110;
        else
            OC4CON1bits.OCM = 0;
    }
}
