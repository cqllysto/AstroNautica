/******************************* TRICK HEADER ****************************
PURPOSE: (Set the initial data values)
*************************************************************************/

/* WORK IN PROGRESS */


/* Model Include files */
#include <math.h>
#include "../include/spacecraft.h"

/* default data */
int spacecraft_default(spacecraft &sc) {
    sc.acc = 0.0;
    sc.time = 0.0;

    return 0;
}

/* initialization */
int spacecraft_init(spacecraft &sc) {
}
