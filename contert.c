#include "type.h"

char *Number_strin(u16 n, u8 base)
{  
	u8 buf[8 * sizeof(long)]; // Assumes 8-bit chars. 
	u16 i = 0;

	if (n == 0)
	{
		buf[i++]=('0');
        buf[i++]=('\r');
		return (buf);
	} 

	while (n > 0)
	{
		buf[i++] = ((char)(n % base)+0x30);
		n /= base;
	}
    buf[i++]='\r';

	//for (; i > 0; i--)
	//	lcd_write((char) (buf[i - 1] < 10 ? '0' + buf[i - 1] : 'A' + buf[i - 1] - 10));
    return (buf);
}

char  *printFloat(float number, u8 digits)
{ 
	u8  toPrint;
    u8 base=10;
	u16 int_part;
	float rounding, remainder;
    static char buf[8 * sizeof(long)]; 
    static char buf1[8 * sizeof(long)]; 
	u16 i = 0;
    u16 m,l;

	
	if (number < 0.0)
	{
		//trans_dato('-');
		number = -number;
	}

	
	rounding = 0.5;
	for (i=0; i<digits; ++i)
		rounding /= 10.0;

	number += rounding;

	
	int_part = (u16)number;
	remainder = number - (float)int_part;
    
    

	if (int_part == 0)
	{
        buf[i++]='0';
	} 

	while (int_part > 0)
	{
        //lcd_write((char) (buf[i - 1] < 10 ? '0' + buf[i - 1] : 'A' + buf[i - 1] - 10));
		buf[i++] =((char) (int_part % base)+0x30);
		int_part /= base;
	}
    l=i-1;
    for (m=0;m<l;m++){
        buf1[m]=buf[i-m];
    }
   
    buf1[i++]='.';
	//entero=printNumber(int_part, 10);

	
	//if (digits > 0)
	///	trans_dato('.'); 

	
	while (digits-- > 0)
	{
		remainder *= 10.0;
		toPrint = (unsigned int)remainder; 
		buf1[i++] =((char) (toPrint)+0x30);
		remainder -= toPrint; 
	}
    buf1[i++]='\r';
    return (buf1); 
}


void strreverse(char* begin, char* end)
{  
    char aux;  
    while(end>begin)   
        aux=*end, *end--=*begin, *begin++=aux; 
}
void itoa_(int value, char *str)
{
    char* wstr=str;
    int sign;  
    //div_t res;
   
    if ((sign=value) < 0) value = -value;
   
    do {   
      *wstr++ = (value%10)+'0';
    }while(value=value/10);
   
    if(sign<0) *wstr++='-';
    *wstr='\0';

    strreverse(str,wstr-1);
}