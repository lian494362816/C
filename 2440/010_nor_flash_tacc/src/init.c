#include "s3c2440_soc.h"
#include "init.h"


int bank0_tacc_set(int value)
{

    /* nor flash can change 0->1, but can't change 1->0
    so can't clear [10:8]
    */
    //BANKCON0 &= ~(0x7 << 8);
    //BANKCON0 |= (value << 8);
    BANKCON0 = value << 8;

    return 0;
}

