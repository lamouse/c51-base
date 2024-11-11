/**
 * *********************************************
 *
 * 8051 blink demo
 *
 * PIN: P11
 *
 * *********************************************
 */



#include "lcd12864.h"

void main()
{
	lcd12864_init();

	lcd12864_show_string(0,0,"Hello World!");
	lcd12864_show_string(0,1,"测试中文");
	lcd12864_show_string(0,2,"一二三\xfd");
	lcd12864_show_string(0,3,"四五");

    while (1) {

    }
}
