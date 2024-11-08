#include "time.h"
#include "Atmel/REGX52.H"
void timer0_init(){
    TMOD = TMOD&0xF0;
    TMOD = TMOD|0x01;
    TF0 = 0;
    TR0 = 1;
    TH0 = 0xfc;
    TL0 = 0x18;
    ET0 = 1;
    EA = 1;
    PT0 = 0;
}

void timer_reset(){
    TH0 = 0xfc;
    TL0 = 0x18;
}