#include "key.h"
#include "delay.h"
#include "Atmel/REGX52.H"

static unsigned char key_number = 0;
char key()
{
    unsigned t = key_number;
    key_number = 0;
    return t;
}

char key_state()
{
    if (P3_1 == KEY_DOWN) return 1;
    if (P3_0 == KEY_DOWN) return 2;

    if (P3_2 == KEY_DOWN) return 3;

    if (P3_3 == KEY_DOWN) return 4;
    return 0;
}
void key_loop()
{
    static unsigned char last_key = 0, current_key = 0;
    last_key    = current_key;
    current_key = key_state();
    if (last_key == 1 && current_key == 0) {
        key_number = 1;
    }

    if (last_key == 2 && current_key == 0) {
        key_number = 2;
    }

    if (last_key == 3 && current_key == 0) {
        key_number = 3;
    }

    if (last_key == 4 && current_key == 0) {
        key_number = 4;
    }
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