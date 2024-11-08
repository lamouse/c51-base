#include "key.h"
#include "delay.h"
#include "Atmel/REGX52.H"
int key1_put_down()
{
    return !P3_1 ? 1 : 0;
}

int key2_put_down()
{
    return !P3_0 ? 1 : 0;
}

unsigned char matrixKey()
{
    unsigned key_num = 0;
    P1               = 0xFF;
    P1_3             = 0;
    if (P1_7 == KEY_DOWN) {
        DelayMs(20);
        while (P1_7 == KEY_DOWN);
        DelayMs(20);
        key_num = 1;
    }
    if (P1_6 == KEY_DOWN) {
        DelayMs(20);
        while (P1_6 == KEY_DOWN);
        DelayMs(20);
        key_num = 5;
    }
    if (P1_5 == KEY_DOWN) {
        DelayMs(20);
        while (P1_5 == KEY_DOWN);
        DelayMs(20);
        key_num = 9;
    }
    if (P1_4 == KEY_DOWN) {
        DelayMs(20);
        while (P1_4 == KEY_DOWN);
        DelayMs(20);
        key_num = 13;
    }

    P1   = 0xFF;
    P1_2 = 0;
    if (P1_7 == KEY_DOWN) {
        DelayMs(20);
        while (P1_7 == KEY_DOWN);
        DelayMs(20);
        key_num = 2;
    }
    if (P1_6 == KEY_DOWN) {
        DelayMs(20);
        while (P1_6 == KEY_DOWN);
        DelayMs(20);
        key_num = 6;
    }
    if (P1_5 == KEY_DOWN) {
        DelayMs(20);
        while (P1_5 == KEY_DOWN);
        DelayMs(20);
        key_num = 10;
    }
    if (P1_4 == KEY_DOWN) {
        DelayMs(20);
        while (P1_4 == KEY_DOWN);
        DelayMs(20);
        key_num = 14;
    }

    P1   = 0xFF;
    P1_1 = 0;
    if (P1_7 == KEY_DOWN) {
        DelayMs(20);
        while (P1_7 == KEY_DOWN);
        DelayMs(20);
        key_num = 3;
    }
    if (P1_6 == KEY_DOWN) {
        DelayMs(20);
        while (P1_6 == KEY_DOWN);
        DelayMs(20);
        key_num = 7;
    }
    if (P1_5 == KEY_DOWN) {
        DelayMs(20);
        while (P1_5 == KEY_DOWN);
        DelayMs(20);
        key_num = 11;
    }
    if (P1_4 == KEY_DOWN) {
        DelayMs(20);
        while (P1_4 == KEY_DOWN);
        DelayMs(20);
        key_num = 15;
    }

    P1   = 0xFF;
    P1_0 = 0;
    if (P1_7 == KEY_DOWN) {
        DelayMs(20);
        while (P1_7 == KEY_DOWN);
        DelayMs(20);
        key_num = 4;
    }
    if (P1_6 == KEY_DOWN) {
        DelayMs(20);
        while (P1_6 == KEY_DOWN);
        DelayMs(20);
        key_num = 8;
    }
    if (P1_5 == KEY_DOWN) {
        DelayMs(20);
        while (P1_5 == KEY_DOWN);
        DelayMs(20);
        key_num = 12;
    }
    if (P1_4 == KEY_DOWN) {
        DelayMs(20);
        while (P1_4 == KEY_DOWN);
        DelayMs(20);
        key_num = 16;
    }

    return key_num;
}