#include "nixie.h"
#include "delay.h"
#include "Atmel/REGX52.H"

#define LED_SEGMENT_DISPLAY_1 \
    P2_4 = 0;                 \
    P2_3 = 0;                 \
    P2_2 = 0
#define LED_SEGMENT_DISPLAY_2 \
    P2_4 = 0;                 \
    P2_3 = 0;                 \
    P2_2 = 1

#define LED_SEGMENT_DISPLAY_3 \
    P2_4 = 0;                 \
    P2_3 = 1;                 \
    P2_2 = 0

#define LED_SEGMENT_DISPLAY_4 \
    P2_4 = 0;                 \
    P2_3 = 1;                 \
    P2_2 = 1

#define LED_SEGMENT_DISPLAY_5 \
    P2_4 = 1;                 \
    P2_3 = 0;                 \
    P2_2 = 0

#define LED_SEGMENT_DISPLAY_6 \
    P2_4 = 1;                 \
    P2_3 = 0;                 \
    P2_2 = 1

#define LED_SEGMENT_DISPLAY_7 \
    P2_4 = 1;                 \
    P2_3 = 1;                 \
    P2_2 = 0

#define LED_SEGMENT_DISPLAY_8 \
    P2_4 = 1;                 \
    P2_3 = 1;                 \
    P2_2 = 1

#define LED_SEGMENT_NUM_0 0x3F
#define LED_SEGMENT_NUM_1 0x6
#define LED_SEGMENT_NUM_2 0x5B
#define LED_SEGMENT_NUM_3 0x4f
#define LED_SEGMENT_NUM_4 0x66
#define LED_SEGMENT_NUM_5 0x6d
#define LED_SEGMENT_NUM_6 0x7d
#define LED_SEGMENT_NUM_7 0x7
#define LED_SEGMENT_NUM_8 0x7F
#define LED_SEGMENT_NUM_9 0x6f
static char nixie_buff[8] = {10, 10, 10, 10, 10, 10, 10, 10};
static char nixie_num[]   = {LED_SEGMENT_NUM_0, LED_SEGMENT_NUM_1, LED_SEGMENT_NUM_2, LED_SEGMENT_NUM_3, LED_SEGMENT_NUM_4,
                             LED_SEGMENT_NUM_5, LED_SEGMENT_NUM_6, LED_SEGMENT_NUM_7, LED_SEGMENT_NUM_8, LED_SEGMENT_NUM_9, 0x4};
char get_num_index(char num)
{
    switch (num) {
        case 1:
            return LED_SEGMENT_NUM_1;
        case 2:
            return LED_SEGMENT_NUM_2;
        case 3:
            return LED_SEGMENT_NUM_3;
        case 4:
            return LED_SEGMENT_NUM_4;
        case 5:
            return LED_SEGMENT_NUM_5;
        case 6:
            return LED_SEGMENT_NUM_6;
        case 7:
            return LED_SEGMENT_NUM_7;
        case 8:
            return LED_SEGMENT_NUM_8;
        case 9:
            return LED_SEGMENT_NUM_9;
        case 0:
            return LED_SEGMENT_NUM_0;
        default:
            return 0x4;
    }
}

void show_index_num(char index, char num)
{
    P0 = 0x00;
    switch (index) {
        case 1: {
            LED_SEGMENT_DISPLAY_1;
        } break;

        case 2: {
            LED_SEGMENT_DISPLAY_2;
        } break;

        case 3: {
            LED_SEGMENT_DISPLAY_3;

        } break;

        case 4: {
            LED_SEGMENT_DISPLAY_4;

        } break;

        case 5: {
            LED_SEGMENT_DISPLAY_5;
        } break;

        case 6: {
            LED_SEGMENT_DISPLAY_6;
        } break;

        case 7: {
            LED_SEGMENT_DISPLAY_7;
        } break;

        case 8: {
            LED_SEGMENT_DISPLAY_8;
        } break;

        default:
            break;
    }

    P0 = nixie_num[num];
}

void show_num(int num)
{
    char count = 0;
    char num_arr[8];
    int i  = 1;
    char s = num < 0 ? get_num_index(-1) : 0;
    for (; num; i++) {
        num_arr[count++] = num % 10;
        num /= 10;
    }

    for (i = 0; i < count; i++) {
        nixie_scan(i + 1, num_arr[i]);
    }

    if (s) {
        P0 = s;
    }
}

void nixie_loop()
{
    unsigned char i;
    for (i = 1; i < 9; i++) {
        if (nixie_buff[i - 1] <= 9) {
            show_index_num(i, nixie_buff[i - 1]);
        }
    }
}

void nixie_scan(char index, char num)
{
    nixie_buff[index - 1] = num;
}

void nixie_clear(char index)
{
    nixie_buff[index - 1] = 10;
}

void nixie_clear_all()
{
    unsigned char i;
    for (i = 0; i < 8; i++) {
        nixie_buff[i] = 10;
    }
}