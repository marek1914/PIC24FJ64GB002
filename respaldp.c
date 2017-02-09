if (U1STAbits.URXDA){
            lec=uart_GetString(UART_1);
            dato=truncar(lec,3);
            if (strncmp(lec,"M1",2)==0)
                set_dutty(PWM_1,atoi(dato));
            else if (strncmp(lec,"M2",2)==0)  
                set_dutty(PWM_2,atoi(dato));
            else if (strncmp(lec,"M3",2)==0)  
                set_dutty(PWM_3,atoi(dato));
            else
                uart_print(UART_2,lec);
        }
        if (U2STAbits.URXDA){
            //uart_print(UART_1,"M2=ON \r");
            lec_2=uart_GetString(UART_2);
            uart_print(UART_1,lec_2);
            dato_2=truncar(lec,3);
            uart_print(UART_1,dato_2);
            if (strncmp(lec, "M1", 2)==0){
                if (strncmp(dato,"ON",2)==0)
                    pwm_enable(PWM_1,ON);
                else
                    pwm_enable(PWM_1,OFF);
            }
            else if (strncmp(lec, "M2", 2)==0){  
                if (strncmp(dato,"ON",2)==0)
                    pwm_enable(PWM_2,ON);
                else
                    pwm_enable(PWM_2,OFF);
            }
            else if (strncmp(lec,"M3",2)==0){  
                if (strncmp(dato,"ON",2)==0)
                    pwm_enable(PWM_3,ON);
                else
                    pwm_enable(PWM_3,OFF);
            }
            
        }
