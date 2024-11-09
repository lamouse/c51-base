#ifndef LED_SCREEN_H
#define LED_SCREEN_H
#include "Atmel/REGX52.H"
/**
 * @brief led点阵屏
 *
 */

sbit RCK  = P3 ^ 5; //RCLK
sbit SRCLK = P3 ^ 6;
sbit SER   = P3 ^ 4;

void led_screen_write_byte(unsigned char Byte);
void led_screen_write(unsigned char* Data, unsigned char offset);
void led_screen_init();

#endif