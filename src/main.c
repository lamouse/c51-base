/**
 * *********************************************
 *
 * 8051 blink demo
 *
 * PIN: P11
 *
 * *********************************************
 */

#include "time.h"
#include "Atmel/REGX52.H"
#include "key.h"
#include "nixie.h"
unsigned int t0_count = 0, speed = 0;
int compar = 0;
unsigned char key_num;
sbit Motor=P1^0;
void main()
{

    timer0_init();
    compar = 5;
    while (1) {
        key_num = key();
        if (key_num == 1) {
            speed++;
            speed %= 4;
        }
        if (key_num == 2) {
            speed--;
            speed %= 4;
        }
        if (speed == 0) {
            compar = 0;
        }
        if (speed == 1) {
            compar = 5;
        }
        if (speed == 2) {
            compar = 50;
        }
        if (speed == 3) {
            compar = 100;
        }

        nixie_scan(8, speed);
    }
}

void time_routine(void) interrupt 1
{
	t0_count++;
    t0_count %= 100;
    key_loop();
    timer_reset();
    nixie_loop();
    if (t0_count < compar) {
        Motor = 1;
    } else {
        Motor = 0;
    }
}
