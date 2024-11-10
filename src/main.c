/**
 * *********************************************
 *
 * 8051 blink demo
 *
 * PIN: P11
 *
 * *********************************************
 */

#include "AT24C02.h"
#include "LCD1602.h"
#include "delay.h"

void main()
{
    unsigned char read_data, write_date = 55, address = 3;

    LCD_Init();
    AT24C02_write(address, write_date);
    LCD_ShowString(1, 1, "write");
    LCD_ShowNum(1, 9, write_date, 3);
    DelayMs(10);
    read_data = AT24C02_read(address);
    LCD_ShowNum(2, 1, read_data, 3);
    while (1) {

    }
}
