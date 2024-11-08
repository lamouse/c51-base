/**
 * *********************************************
 *
 * 8051 blink demo
 *
 * PIN: P11
 *
 * *********************************************
*/


#include "led.h"
#include "key.h"
#include "delay.h"
#define MAX_LED_INDEX 8
#define MIN_LED_INDEX 1

void main(){
	int led_index = 0;
    while(1){
    	// if(key1_put_down()){
		// 	LED_1 = led_on;
		// }else
		// {
		// 	led1_off();
		// }

		if (key2_put_down())
		{
			DelayMs(20);
			while (key2_put_down());
			DelayMs(20);
			led_off_all();
			led_ctrl(++led_index, led_reversible);
		}

		if(KEY_3 == KEY_DOWN){
			DelayMs(20);
			while (KEY_3 == KEY_DOWN);
			DelayMs(20);
			led_off_all();
 			led_ctrl(--led_index, led_reversible);
		}
		if(led_index > MAX_LED_INDEX){
			led_off_all();
			led_index = MIN_LED_INDEX;
			led_ctrl(MIN_LED_INDEX, led_reversible);
		}
		if(led_index < MIN_LED_INDEX){
			led_off_all();
			led_index = MAX_LED_INDEX;
			led_ctrl(MAX_LED_INDEX, led_reversible);
		}
    }
}