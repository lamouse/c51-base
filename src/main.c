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
#include "temperature.h"
#include "temperature.h"

void main()
{
    float temperature;
    LCD_Init();
    LCD_ShowString(1, 1, "temperature:");

    while (1) {
        DS_convert_T();
        temperature =  get_temperature();
        if(temperature < 0){
            LCD_ShowChar(2, 1, '-');
            temperature = -temperature;
        }else{
            LCD_ShowChar(2, 1, '+');
        }
        LCD_ShowNum(2, 2, temperature, 3);
        LCD_ShowChar(2, 5, '.');
        LCD_ShowNum(2, 6, (unsigned long)(temperature * 10000) % 10000, 3);
    }
}
