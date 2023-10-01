/*************************************************************************
PURPOSE: (Define the basic orbital algorithms)
**************************************************************************/
#ifndef ORBIT_H
#define ORBIT_H

class orbit {
    public:
        double calcSemiMajor(double apoapsis, double periapsis); /* ** calculates sMj axis */
        double semiMajor;                                 /* *io m length of semi major axis */
        double calcSemiMinor(double apoapsis, double periapsis); /* ** calculates sMn axis */
        double semiMinor;                                 /* *io m length of semi minor axis */
        double calcE(double apoapsis, double periapsis); /* ** calculates eccentricity */
        double e;                                         /* *io - eccentricity of orbit */
        double calcPeriod(double semiMajor); /* ** calculates period of orbit */
        double period;                                    /* *io s period of orbit */
        double calcVelApo(double semiMajor, double r);  /* ** calculates vel at apo */
        double velApo;                                    /* *io m/s vel at apoapsis */
        double calcVelPeri(double semiMajor, double r); /* ** calculates period of orbit */
        double velPeri;                                   /* *io m/s vel at periapsis */
        double mass = pow(5.9722, 24);                    /* *io m/s Earth's mass */
        double G = pow(6.67430, -11);                     /* *io m/s Earth's gravitational constant */
        double calcApoapsis(double velPeri, double periapsis); /* ** calculates period of orbit */
        double apoapsis;                                  /* *io m distance from earth to apo */
        double calcPeriapsis(double velApo, double apoapsis); /* ** calculates period of orbit */
        double periapsis;                                 /* *io m distance from earth to peri */
        orbit();
};

#endif
