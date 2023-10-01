/******************************* TRICK HEADER ****************************
PURPOSE: (Calculate orbital characteristics)
*************************************************************************/

/* Model Include files */
#include <cmath>
#include "../include/orbit.h"

using namespace std;

orbit::orbit() {
    semiMajor, semiMinor, e, period, velApo, velPeri = 0;
    apoapsis, periapsis = 0;
    mass = pow(5.9722, 24); 
    G = pow(6.67430, -11);
}

double orbit::calcSemiMajor(double a, double p) {
    double semiMajor = (a + p) / 2;
    return semiMajor;
}

double orbit::calcSemiMinor(double a, double p) {
    double semiMinor = sqrt(a * p);
    return semiMinor;
}

double orbit::calcE(double a, double p) {
    e = (a - p) / (a + p);
    return e;
}

double orbit::calcPeriod(double sMj) {
    period = 2 * M_PI * sqrt(pow(sMj, 3) / (G * mass));
    return period;
}

double orbit::calcVelApo(double a, double sMj) {
    double vel = sqrt((G * mass) * (2/a - 1/sMj));
    return vel;
}

double orbit::calcVelPeri(double p, double sMj) {
    double vel = sqrt((G * mass) * (2/p - 1/sMj));
    return vel;
}

double orbit::calcApoapsis(double velP, double p) {
    double apo = 2 * (pow(velP, 2) * p / (pow(velP, 2) - 2 * G * mass));
    return apo;
}

double orbit::calcPeriapsis(double velA, double a) {
    double peri = 2 * (pow(velA, 2) * a / (pow(velA, 2) - 2 * G * mass));
    return peri;
}



