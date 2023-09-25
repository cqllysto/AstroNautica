/******************************* TRICK HEADER ****************************
PURPOSE: (Calculate orbital characteristics)
*************************************************************************/

/* Model Include files */
#include <cmath>
#include "../include/orbit.h"

using namespace std:

orbit::orbit() {
    semiMajor, semiMinor, e, period, velApo, velPeri = 0;
    apoapsis, periapsis = 0
    mass = 5.9722 * 10^24; 
    G = 6.67430 * 10^−11;
}

double orbit::calcSemiMajor(double a, double p) {
    semiMajor = (a + p) / 2;
    return semiMajor;
}

double orbit::calcSemiMinor(double a, double p) {
    semiMinor = sqrt(a * b);
}

double orbit::calcE(double a, double p) {
    e = (a - p) / (a + p);
    return e;
}

double orbit::calcPeriod(double sMj) {
    period = 2 * pi * sqrt(sMj^3 / (G * mass));
    return period;
}

double orbit::calcVelApo(double a, double sMj) {
    vel = sqrt((G * mass) * (2/a - 1/sMj);
    return vel;
}

double orbit::calcVelPeri(double p, double sMj) {
    vel = sqrt((G * mass) * (2/p - 1/sMj);
    return vel;
}

double orbit::calcApoapsis(double velP, double p) {
    apo = 2 * velP^2 * p / (velP^2 - 2 * G * mass);
    return apo;
}

double orbit::calcPeriapsis(double velA, double a) {
    peri = 2 * velA^2 * a / (velA^2 - 2 * G * mass);
    return peri;
}



