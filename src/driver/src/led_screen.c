#include "led_screen.h"
#include "delay.h"
void led_screen_write_byte(unsigned char Byte)
{
    unsigned char current_bit = 0x80;
    while (current_bit) {
        SER   = Byte & current_bit;
        SRCLK = 1;
        SRCLK = 0;
        current_bit >>= 1;
    }
    RCK = 1;
    RCK = 0;
}

static void write_column(unsigned char column, unsigned char Data)
{
    led_screen_write_byte(Data);
    P0 = ~(0x80 >> column);
    DelayMs(1);
    P0 = 0xFF;
}

void led_screen_init()
{
    SRCLK = 0;
    RCK   = 0;
}

void led_screen_write(unsigned char* Data, unsigned char offset)
{
    int i = 0;
    for(; i < 8; i++){
        write_column(i, Data[i + offset]);
    }
}