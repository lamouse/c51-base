#include "led.h"
#include "Atmel/REGX52.H"
void led1_on(){
    P2_0 = 0;
}
void led1_off(){
    P2_0 = 1;
}