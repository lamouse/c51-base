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
#include "INTRINS.H"
char h = 23, m = 59; s = 50, ms = 0;
void main()
{
    char key_num= 0;
    timer0_init();
    LCD_Init();
    LCD_ShowString(1, 1, "timer");
    LCD_ShowString(2, 1, "  :  :    ");
    LCD_ShowString(1, 8, "key:");
    while (1) {
        LCD_ShowNum(2, 1, h, 2);
        LCD_ShowNum(2, 4, m, 2);
        LCD_ShowNum(2, 7, s, 2);
        LCD_ShowNum(2, 10, ms, 3);
        key_num = key();
        if (key_num)
        {
            LCD_ShowNum(1, 13, key_num, 1);
        }

    }
}
unsigned int t0_count = 0;
void Timer0_Routine(void) interrupt 1{
    ms = t0_count;
    t0_count++;
    if( t0_count >= 1000){
        s++;
        if(s >= 60){
            s = 0;
            m++;
        }
        if(m >= 60){
            h++;
            m = 0;
        }
        if(h >= 24){
            h = 0;
        }
        t0_count = 0;
    }

    timer_reset();
}