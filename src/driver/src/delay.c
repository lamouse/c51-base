#include "delay.h"
#include "intrins.h"

void Delay1ms(void)	//@12.000MHz
{

	unsigned char data i, j;

	_nop_();
	i = 2;
	j = 199;
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
