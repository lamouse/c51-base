/**
 * *********************************************
 *
 * 8051 blink demo
 *
 * PIN: P11
 *
 * *********************************************
 */

#include "led_screen.h"
#include <time.h>

unsigned char offset = 0;
static unsigned char code animation[]={0x10,0x10,0x10,0x10,0x10,0x10,0x00,0x08,0x08,0x28,0x28,0x28,0x08,0x08,0x00,0x00};
unsigned int max_offset = sizeof(animation)/sizeof(animation[0]) - 8;
unsigned int t0_count = 0;
void main()
{
    led_screen_init();
    timer0_init();
    while (1) {
        led_screen_write(animation, offset);
    }
}


void Timer0_Routine(void) interrupt 1{
    t0_count++;
    if(t0_count > 200){
        t0_count = 0;
        offset++;
        if (offset > 8)
        {
            offset = 0;
        }
    }


    timer_reset();
}
