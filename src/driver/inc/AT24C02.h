#ifndef AT24C02_H
#define AT24C02_H
void AT24C02_write(unsigned char address, unsigned char Byte);
unsigned char AT24C02_read(unsigned char address);
#endif