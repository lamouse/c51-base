#include "key.h"
#include "Atmel/REGX52.H"
int key1_put_down(){
    return !P3_1 ? 1 : 0;
}



int key2_put_down(){
    return !P3_0 ? 1 : 0;
}