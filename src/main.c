/**
 * *********************************************
 *
 * 8051 blink demo
 *
 * PIN: P11
 *
 * *********************************************
 */

#include "LCD1602.h"
#include "key.h"
#include "time.h"
#include "led.h"
char led_index = 0;
void main()
{
    char last_led_index = led_index;
    timer0_init();
    while (1) {
        if (last_led_index != led_index && led_index)
        {
            led_off_all();
            led_ctrl(led_index, led_on);
            last_led_index = led_index;
        }

    }
}
unsigned int t0_count = 0;
void Timer0_Routine(void) interrupt 1{
    if(t0_count++ > 1000){
        led_index++;
        if(led_index > 8){
            led_index = 1;
        }
        t0_count = 0;
    }

    timer_reset();
}