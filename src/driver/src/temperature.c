#include "temperature.h"
#include "Atmel/REGX52.H"
#include "DS18B20.h"

void DS_convert_T(void){
    DS_init();
    DS_send(DS_SKIP_ROM);
    DS_send(DS_CONCERT_T);
}

float get_temperature(){
    unsigned char TLSB, TMSB;
    int tmp;
    float res;
    DS_init();
    DS_send(DS_SKIP_ROM);
    DS_send(DS_READ_SCRATCHPAD);
    TLSB = DS_receive();
    TMSB = DS_receive();
    tmp =  (TMSB << 8) | TLSB;
    res = tmp /16.0;
    return res;
}