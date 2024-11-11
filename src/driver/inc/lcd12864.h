#ifndef _lcd12864_H
#define _lcd12864_H

#include "public.h"

//�ܽŶ���
sbit LCD12864_RS=P2^6;
sbit LCD12864_WR=P2^5;
sbit LCD12864_E=P2^7;
#define LCD12864_DATAPORT	P0	//LCD12864���ݶ˿ڶ���
sbit LCD12864_PSB=P3^2;

//��������
void lcd12864_init(void);
void lcd12864_clear(void);
void lcd12864_show_string(u8 x,u8 y,u8 *str);
#endif
