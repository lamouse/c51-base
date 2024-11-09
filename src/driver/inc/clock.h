#ifndef CLOCK_H
#define CLOCK_H

void DS_1302_init();
void DS_1302_write(unsigned char cmd, unsigned char Data);
unsigned char DS_1302_read(unsigned char cmd);
extern char DS1302_Time[];
void DS1302_ReadTime(void);
void DS1302_SetTime(void);
#endif