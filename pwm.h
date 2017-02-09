#include "type.h"
#ifndef pwm_H
#define	pwm_H

#define PWM_1 1
#define PWM_2 2
#define PWM_3 3
#define PWM_4 4
#define PWM_5 5

void set_freq(u8 modulo, float fre);
void set_dutty(u8 modulo, int dutty);
void init_pwm(u8 modulo, float fre, int dutty);
void pwm_enable(u8 modulo,u8 on_off );






#endif	/* XC_HEADER_TEMPLATE_H */

