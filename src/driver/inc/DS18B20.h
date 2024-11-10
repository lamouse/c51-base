#ifndef DS18B20_H
#define DS18B20_H
#define DS_SKIP_ROM 0xCC
#define DS_CONCERT_T 0x44
#define DS_READ_SCRATCHPAD 0xBE

bit DS_init();
void DS_send_bit(bit b);
bit DS_receive_bit();
void DS_send(unsigned char Byte);
unsigned char DS_receive();
#endif