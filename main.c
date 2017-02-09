/*
 * File:   main.c
 * Author: game
 *
 * Created on 6 de diciembre de 2016, 03:09 PM
 */


#include "p24FJ64GB002.h"
#include "type.h"
#include "pragmas.h"
#include "system.h"
#include "UART.h"
#include "pwm.h"
#include "adc.h"
#include "contert.h"
#include <string.h>
#include <stdlib.h>




char *truncar(char *str,int inc){
    int i=0;
    static char buf[8 * sizeof(long)]; 
    for (i=0;str[i]!='\r';++i)
        buf[i]=str[inc+i];
    buf[i++]='\r';
    return(buf);
}

int main(void) {
    set_pin();
    int i=0;
    char *lec,*dato;
    char *lec_2,*dato_2;
    //long c=1;
    //u16 b=1;
    init_uart(UART_1,230400,NONE,8,ONE_BIT);
    init_uart(UART_2,9600,NONE,8,ONE_BIT);
    init_pwm(PWM_1,3000,0);
    init_pwm(PWM_2,3000,0);
    init_pwm(PWM_3,3000,0);
    init_pwm(PWM_4,50,1);
    pwm_enable(PWM_1,OFF);
    pwm_enable(PWM_2,OFF);
    pwm_enable(PWM_3,OFF);
    pwm_enable(PWM_4,ON);
    adc_init();
    for (i=0;i<=10;i++){
        uart_print(UART_2,"PRINT \r");
    }

    while(1){
        
        if (U1STAbits.URXDA){          
            lec=uart_GetString(UART_1);       
            dato=truncar(lec,3);
            uart_print(UART_2,lec);
            uart_print(UART_1,lec);
            if (strncmp(lec,"M1",2)==0)
               set_dutty(PWM_1,atoi(dato));
            else if (strncmp(lec,"M2",2)==0)  
                set_dutty(PWM_2,atoi(dato));
            else if (strncmp(lec,"M3",2)==0)  
                set_dutty(PWM_3,atoi(dato));
        }
        
        if (U2STAbits.URXDA){           
            lec_2=uart_GetString(UART_2);
            uart_print(UART_1,lec_2);
            dato_2=truncar(lec_2,3);
            if (strncmp(lec_2,"M1",2)==0){
                if (strncmp(dato_2,"ON",2)==0)
                   pwm_enable(PWM_1,ON);
                else
                    pwm_enable(PWM_1,OFF);
            }
            else if (strncmp(lec_2, "M2", 2)==0){  
                if (strncmp(dato_2,"ON",2)==0)
                    pwm_enable(PWM_2,ON);
                else
                    pwm_enable(PWM_2,OFF);
            }
            else if (strncmp(lec_2,"M3",2)==0){  
                if (strncmp(dato_2,"ON",2)==0)
                    pwm_enable(PWM_3,ON);
                else
                    pwm_enable(PWM_3,OFF);
            }
            
        }
        
       
       
    }
    return 0;
}
