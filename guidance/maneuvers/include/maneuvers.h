
/*************************************************************************
PURPOSE: (Change the spacecraft's orbit)
**************************************************************************/

#ifndef __MANEUVERS_H
#define __MANEUVERS_H

#include "../../orbit/include/orbit.h"
#include "../../../model/spacecraft/include/spacecraft.h"

// Spacecraft class
class maneuvers {
    private:
        void changeApo(orbit &o, spacecraft &sc, double altitude);
        void changePeri(orbit &o, spacecraft &sc, double altitude);
        void circOrbit(orbit &o, spacecraft &sc);
        void hohmann(orbit &o, spacecraft &sc, double sMj);
        void biElliptic(orbit &o, spacecraft &sc, 
            double interApo, double targetApo);
        void biImpulse(orbit &o, spacecraft &sc, 
            double targetPeri, double targetApo);
        // void abort(orbit &o, spacecraft &sc); future function
    public:
        maneuvers();
        double deltaV; /* */
};

#endif
