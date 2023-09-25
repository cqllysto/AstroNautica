/******************************* TRICK HEADER ****************************
PURPOSE: (Set the initial data values)
*************************************************************************/

/* Model Include files */
#include <math.h>
#include "../include/spacecraft.h"

/* default data */
int spacecraft_default( SPACECRAFT* S ) {
    S->acc[0] = 0.0;
    S->acc[1] = -9.81;
    S->orient0 = 0;
    S->height0 = 1000;
    S->time = 0.0;

    return 0;
}

/* initialization */
int spacecraft_init( SPACECRAFT* S) {
    S->vel0[0]
}
