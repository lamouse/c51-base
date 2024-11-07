/**
 * *********************************************
 *
 * 8051 blink demo
 *
 * PIN: P11
 *
 * *********************************************
*/

#include "REG52.H"
#include "intrins.h"

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
    P2 = 0xFE;

    while(1){
		if(P2 == 0xFF){
			P2 = 0xFE;
		}
        DelayMs(500);
		P2 = P2 << 1;
        P2 = P2 | 0x01;
    }
}