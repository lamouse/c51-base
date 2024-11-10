/**
 * *********************************************
 *
 * 8051 blink demo
 *
 * PIN: P11
 *
 * *********************************************
 */



#include "nixie.h"
#include "key.h"
#include "time.h"

void main()
{
    char key_num = 0, k_t;
    timer0_init();
    while (1) {
        key_num = key();
        if(key_num){
            k_t = key_num;
        }
        nixie_scan(1, k_t);
    }
}

void time0_routine() interrupt 1 {
    static unsigned int T_count;
    T_count++;
    if(T_count % 20){
        key_loop();

    }
    if(T_count % 2){
        nixie_loop();
    }
    timer_reset();
}