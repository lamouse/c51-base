#include "uart.h"
#include "Atmel/REGX52.H"
void UART_init()
{
    SCON = 0x50;
    PCON |= 0x80; // 使能波特率倍速位SMOD 不开倍率会传输数据异常

    TMOD = TMOD & 0x0F;
    TMOD = TMOD | 0x20;
    TL1  = 0xF4; // 设置定时初始值
    TH1  = 0xF4; // 设置定时重载值
    ET1  = 0;    // 禁止定时器中断
    TR1  = 1;
    EA = 1;
    ES = 1;
}

void UART_send(unsigned char Byte)
{
    SBUF = Byte;
    while (TI == 0);
    TI = 0;
}