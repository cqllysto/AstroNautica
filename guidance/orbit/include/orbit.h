/*************************************************************************
PURPOSE: (Define the basic orbital algorithms)
**************************************************************************/
#ifndef ORBIT_H
#define ORBIT_H

class orbit {
    public:
        double calcSemiMajor(double apoapsis, double periapsis);
        double semiMajor;
        double calcSemiMinor(double apoapsis, double periapsis);
        double semiMinor;
        double calcE(double apoapsis, double periapsis);
        double e;
        double calcPeriod(double semiMajor);
        double period;
        double calcVelApo(double semiMajor, double r);
        double velApo;
        double calcVelPeri(double semiMajor, double r);
        double velPeri;
        const double mass;
        const double G;
        double calcApoapsis(double velPeri, double periapsis);
        double apoapsis;
        double calcPeriapsis(double velApo, double apoapsis);
        double periapsis;
}
