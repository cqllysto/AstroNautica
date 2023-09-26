
/*************************************************************************
PURPOSE: (Change the orbit of the spacecraft)
**************************************************************************/

#ifndef __MANEUVERS_H
#define __MANEUVERS_H

#include "../../orbit/include/orbit.h"
#include "../../../model/spacecraft/include/spacecraft.h"

// Spacecraft class
class maneuvers {
    private:
        void raiseApo(orbit &o, spacecraft &sc);
        void raisePeri(orbit &o, spacecraft &sc);
        void lowerApo(orbit &o, spacecraft &sc);
        void lowerPeri(orbit &o, spacecraft &sc);
        void circOrbit(orbit &o, spacecraft &sc);
        void hohmann(orbit &o, spacecraft &sc);
        void biImpulse(orbit &o, spacecraft &sc);
        void abort(orbit &o, spacecraft &sc);
    public:
        maneuvers();
        double deltaV;
};

#endif
