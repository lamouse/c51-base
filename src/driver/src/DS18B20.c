#include "DS18B20.h"
#include "Atmel/REGX52.H"
#include "INTRINS.H"
sbit DS_DQ = P3^7;


void Delay490us(void)	//@11.0592MHz
{
	unsigned char data i;

	i = 223;
	while (--i);
}

void Delay70us(void)	//@11.0592MHz
{
	unsigned char data i;

	_nop_();
	i = 29;
	while (--i);
}

void Delay5us(void)	//@11.0592MHz
{
}

void Delay45us(void)	//@11.0592MHz
{
	unsigned char data i;

	i = 18;
	while (--i);
}


bit DS_init(){
    bit ack = 0;
    DS_DQ = 1;
    DS_DQ = 0;
    Delay490us();
    DS_DQ = 1;
    Delay70us();
    ack = DS_DQ;
    Delay490us();
    return ack;
}

void DS_send_bit(bit b){
    DS_DQ = 0;
    Delay5us();
    DS_DQ = b;
    Delay45us();
    DS_DQ = 1;
}

bit DS_receive_bit(){
    bit b;
    DS_DQ = 0;
    Delay5us();
    DS_DQ = 1;
    Delay5us();
    b = DS_DQ;
    Delay45us();
    return b;
}

void DS_send(unsigned char Byte){
    unsigned char i;
    for (i = 0; i < 8; i++){
        DS_send_bit(Byte&(0x01 << i));
    }
}
unsigned char DS_receive(){
    unsigned char rec = 0x00, i;
    for(i = 0; i < 8; i++){
        if(DS_receive_bit()){
            rec |= (0x01 << i);
        }
    }
    return rec;
}