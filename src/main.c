/**
 * *********************************************
 *
 * 8051 blink demo
 *
 * PIN: P11
 *
 * *********************************************
 */

#include "uart.h"
#include "delay.h"
#include "led.h"

unsigned char led_index = 0;
void main()
{
    UART_init();

    while (1) {
        if(led_index){
            led_ctrl(led_index, led_reversible);
            led_index = 0;
            UART_send('O');
        }
    }
}

void UART_Routine(void) interrupt 4{
    if(RI == 1){
        led_index = SBUF;
        RI = 0;
    }
}
