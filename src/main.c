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

void main()
{
    char ke_num;
    int ser;
    int count;
    LCD_Init();

beg:
	ser = 0;
	count = 1;
    LCD_ShowString(1, 1, "           ");
    LCD_ShowString(2, 1, "           ");
    LCD_ShowString(1, 1, "num ser: ");
    while (1) {
        ke_num = matrixKey();
        if (ke_num && ke_num <= 10) {
            ser *= 10;
            ser += ke_num % 10;
            LCD_ShowNum(2, 1, ser, count++);

            if (count > 5) {
                goto beg;
            }
        }
        if (ke_num == 16) {
            goto beg;
        }
    }
}