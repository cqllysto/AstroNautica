/*************************************************************************
PURPOSE: (Define the basic orbital algorithms)
**************************************************************************/
#ifndef ORBIT_H
#define ORBIT_H

class orbit {
    public:
        void calcSemiMajor(double apoapsis, double periapsis); /* ** calculates sMj axis */
        double semiMajor;                                 /* *io m length of semi major axis */
        void calcSemiMinor(double apoapsis, double periapsis); /* ** calculates sMn axis */
        double semiMinor;                                 /* *io m length of semi minor axis */
        void calcE(double apoapsis, double periapsis); /* ** calculates eccentricity */
        double e;                                         /* *io - eccentricity of orbit */
        void calcPeriod(double semiMajor); /* ** calculates period of orbit */
        double period;                                    /* *io s period of orbit */
        void calcVelApo(double apoapsis, double semiMajor);  /* ** calculates vel at apo */
        double velApo;                                    /* *io m/s vel at apoapsis */
        void calcVelPeri(double periapsis, double semiMajor); /* ** calculates period of orbit */
        double velPeri;                                   /* *io m/s vel at periapsis */
        double mass = pow(5.9722, 24);                    /* *io m/s Earth's mass */
        double G = pow(6.67430, -11);                     /* *io m/s Earth's gravitational constant */
        void calcApoapsis(double velPeri, double periapsis); /* ** calculates period of orbit */
        double apoapsis;                                  /* *io m distance from earth to apo */
        void calcPeriapsis(double velApo, double apoapsis); /* ** calculates period of orbit */
        double periapsis;                                 /* *io m distance from earth to peri */
        orbit();
};

#endif
