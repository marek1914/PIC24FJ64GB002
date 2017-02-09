
#include "type.h"
#ifndef ADC_H
#define	ADC_H

#define AN0 0



void adc_init();
u16 analogread(u8 pin);
void adc_enable(u8 estado);



#endif	/* XC_HEADER_TEMPLATE_H */

