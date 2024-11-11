#include "time.h"
#include "Atmel/REGX52.H"
void timer0_init(){
    TMOD = TMOD&0xF0;
    TMOD = TMOD|0x01;
    TF0 = 0;
    TR0 = 1;
    timer_reset();
    ET0 = 1;
    EA = 1;
    PT0 = 0;
}

void timer_reset(){
	TL0 = 0x9C;				//设置定时初始值
	TH0 = 0xFF;				//设置定时初始值
}