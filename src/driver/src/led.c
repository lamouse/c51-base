#include "led.h"
#include "delay.h"
void led1_on(){
    P2_0 = 0;
}
void led1_off(){
    P2_0 = 1;
}

int current_led_state = 0;

void led_loop(int ms){
    current_led_state = 1;
    P2 = 0xFE;

    while(current_led_state){
		if(P2 == 0xFF){
			P2 = 0xFE;
		}
        DelayMs(ms);
		P2 = P2 << 1;
        P2 = P2 | 0x01;
    }
}


void led_off_all(){
    current_led_state = 0;
    P2 = 0xFF;
}

void led_ctrl(char index, char ctrl){
    char led_state = LED_ALL >> (index-1);
    led_state = led_state & 0x1;
    if (ctrl == led_reversible){
        if(led_state == 0){
            ctrl = 1;
        }else {
            ctrl = 0;
        }
    }

    if (ctrl == led_state) {
        return;
    }

    if(ctrl == 0 && led_state == 1){
        LED_ALL &= ~(1 << (index - 1));
    }

    if(ctrl == 1 && led_state == 0){
        LED_ALL ^= (1 << (index - 1));
    }
}