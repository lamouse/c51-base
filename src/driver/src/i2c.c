#include "i2c.h"
#include "Atmel/REGX52.H"

sbit I2C_SCL = P2^1;
sbit I2C_SDA = P2 ^ 0;


void I2C_start(){
    I2C_SDA = 1;
    I2C_SCL = 1;

    I2C_SDA = 0;
    I2C_SCL = 0;

}
void I2C_end(){
    I2C_SDA = 0;
    I2C_SCL = 1;
    I2C_SDA = 1;
}


void I2C_send(unsigned char Byte){
    unsigned char current_bit = 0x80;
    while (current_bit)
    {
        I2C_SDA = Byte&current_bit;
        I2C_SCL = 1;
        I2C_SCL = 0;
        current_bit >>= 1;
    }
}

unsigned char I2C_receive(){
    unsigned red_byte = 0x00, i;
    I2C_SDA = 1;
    for(i = 0; i < 8; i++){
        I2C_SCL = 1;

        if(I2C_SDA){
            red_byte |= (0x80 >> i);
        }
        I2C_SCL = 0;
    }

    return red_byte;
}

void I2C_send_ack(bit ack){
    I2C_SDA = ack;
    I2C_SCL = 1;
    I2C_SCL = 0;
}

unsigned char I2C_receive_ack(){
    unsigned char ack;
    I2C_SDA = 1;
    I2C_SCL = 1;
    ack = I2C_SDA;
    I2C_SCL = 0;
    return ack;
}