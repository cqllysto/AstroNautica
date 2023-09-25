
/*************************************************************************
PURPOSE: (Change the orbit of the spacecraft)
**************************************************************************/

#ifndef MANEUVER_H
#define MANEUVER_H


// Spacecraft class
class maneuver {
    private:
        void raiseApo();
        void raisePeri();
        void lowerApo();
        void lowerPeri();
        void circOrbit();
        void hohmann();
        void biImpulse()
        void abort();
    public:
        double deltaV();
}

#endif
