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
	lcd12864_show_string(0,1,"��������");
	lcd12864_show_string(0,2,"һ����\xfd");
	lcd12864_show_string(0,3,"����");

    while (1) {

    }
}
