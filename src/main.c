/**
 * *********************************************
 *
 * 8051 blink demo
 *
 * PIN: P11
 *
 * *********************************************
*/


#include "intrins.h"
#include "led.h"

void Delay1ms(void)	//@12.000MHz
{
	unsigned char data i, j;

	i = 2;
	j = 239;
	do
	{
		while (--j);
	} while (--i);
}

void DelayMs(unsigned int ms)	//@12.000MHz
{
	while (ms--) {
		Delay1ms();
	}
}


void main(){
	led1_on();

    while(1){
    	DelayMs(500);
		led1_off();
		DelayMs(500);
		led1_on();
    }
}