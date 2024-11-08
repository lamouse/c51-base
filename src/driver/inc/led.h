#ifndef LED_H
#define LED_H
#include "Atmel/REGX52.H"
#define LED_1 P2_0
#define LED_2 P2_1
#define LED_3 P2_2
#define LED_4 P2_3
#define LED_5 P2_4
#define LED_6 P2_5
#define LED_7 P2_6
#define LED_8 P2_7
#define LED_ALL P2

enum led_ctrl{
    led_on = 0,
    led_off = 1,
    led_reversible = 2
};

#define LED_1 P2_0
#define LED_2 P2_1
#define LED_3 P2_2
#define LED_4 P2_3
#define LED_5 P2_4
#define LED_6 P2_5
#define LED_7 P2_6
#define LED_8 P2_7

void led_ctrl(char index, char ctrl);
void led1_on();
void led1_off();
void led_loop(int ms);

void led_off_all();

#endif