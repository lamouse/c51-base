#include "beep.h"
#include <Atmel/REGX52.H>
#include <INTRINS.H>
sbit BEEP = P2 ^ 5;

static Delay500us(void)	//@11.0592MHz
{
	unsigned char data i;

	_nop_();
	i = 227;
	while (--i);
}

void bee(unsigned char time)
{
    unsigned char count = 0;
    for (; count < time; count++) {
        BEEP = !BEEP;
        Delay500us();
        BEEP = !BEEP;
    }
}