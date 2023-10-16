/******************************* TRICK HEADER ****************************
PURPOSE: (Calculate orbital characteristics)
*************************************************************************/

/* Model Include files */
#include <cmath>
#include <iostream>
#include "../include/orbit.h"

using namespace std;

orbit::orbit() {
    semiMajor, semiMinor, e, period, velApo, velPeri = 0;
    apoapsis, periapsis = 0;
    mass = 5.9722 * pow(10, 24); 
    G = 6.67430 * pow(10, -11);
}

void orbit::calcSemiMajor(double a, double p) {
    semiMajor = (a + p) / 2;
}

void orbit::calcSemiMinor(double a, double p) {
    semiMinor = sqrt(a * p);
}

void orbit::calcE(double a, double p) {
    e = (a - p) / (a + p);
}

void orbit::calcPeriod(double sMj) {
    period = 2 * M_PI * sqrt(pow(sMj, 3) / (G * mass));
}

void orbit::calcVelApo(double a, double sMj) {
    velApo = sqrt((G * mass) * (2/a - 1/sMj));
}

void orbit::calcVelPeri(double p, double sMj) {
    velPeri = sqrt((G * mass) * (2/p - 1/sMj));
}

void orbit::calcApoapsis(double velP, double p) {
    apoapsis = (2.0 * G * mass / (velP * velP)) - p;
}

void orbit::calcPeriapsis(double velA, double a) {
    periapsis = 2 * (pow(velA, 2) * a / (pow(velA, 2) - 2 * G * mass));
}



