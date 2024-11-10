#include "AT24C02.h"
#include "Atmel/REGX52.H"
#include "i2c.h"

#define AT24C02_ADDRESS 0xA0


void AT24C02_write(unsigned char address, unsigned char Byte){
    unsigned char i2c_ack = 0;
    I2C_start();
    I2C_send(AT24C02_ADDRESS);
    I2C_receive_ack();

    I2C_send(address);
    I2C_receive_ack();

    I2C_send(Byte);
    I2C_receive_ack();
    I2C_end();
}
unsigned char AT24C02_read(unsigned char address){
    unsigned read_data = 0x00;
    I2C_start();
    I2C_send(AT24C02_ADDRESS);
    I2C_receive_ack();
    I2C_send(address);
    I2C_receive_ack();
    I2C_start();
    I2C_send(AT24C02_ADDRESS | 0x1);
    I2C_receive_ack();
    read_data = I2C_receive();
    I2C_send_ack(1);
    I2C_end();
    return read_data;
}