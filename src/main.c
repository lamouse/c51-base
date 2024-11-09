/**
 * *********************************************
 *
 * 8051 blink demo
 *
 * PIN: P11
 *
 * *********************************************
 */

#include "key.h"
#include "beep.h"
#include "nixie.h"
void main()
{

    unsigned k,kk;
    while (1) {
        k = key();
        if (k) {
            kk = k;
            bee( kk * 100);
        }
        show_index_num(1, kk);
    }
}
