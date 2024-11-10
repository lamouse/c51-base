#ifndef I2C_H
#define I2C_H


void I2C_start();
void I2C_end();

void I2C_send(unsigned char Byte);

unsigned char I2C_receive();

void I2C_send_ack(bit ack);

unsigned char I2C_receive_ack();

#endif