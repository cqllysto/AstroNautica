/*************************************************************************
PURPOSE: (Control the orientation and attitude spacecraft)
**************************************************************************/

#ifndef CONTROL_H
#define CONTROL_H


// Spacecraft class
class control {
    public:
        void bangBang(spacecraft &sc, double targetVal, string axis);
        void stabYaw(spacecraft &sc, double targetVal);
        void stabRoll(spacecraft &sc, double targetVal);
        void stabPitch(spacecraft &sc, double targetVal);
        void spinStabilize(spacecraft &sc, orbit o);
        void stab3Axis(spacecraft &sc, double targetYaw, double targetPitch,
            double targetRoll);
        control();
};

#endif
