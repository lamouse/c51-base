/**
 * *********************************************
 *
 * 8051 blink demo
 *
 * PIN: P11
 *
 * *********************************************
*/


#include "key.h"
#include "delay.h"
#include "nixie.h"
#define MAX_LED_INDEX 8
#define MIN_LED_INDEX 1

void main(){
	int led_index = 0;
    while(1){
		int i = 0;
 		for(; i<100; i++)
		{
			show_num(9879);
		}
    }
}