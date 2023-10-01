/******************************* TRICK HEADER ****************************
PURPOSE: (calculations for the spacecraft attributes)
*************************************************************************/


/* Model include files */
#include "../include/spacecraft.h"
#include "../../../guidance/orbit/include/orbit.h"
#include <cmath>
#include <iostream>

/* constructor */
spacecraft::spacecraft(){
    radius, vel, acc, time = 0.0;
    timeAtPeri, timeToPeri = 0.0; 
    timeToApo = 0.0;
    meanAnomaly, trueAnomaly, eccAnomaly = 0.0;
    thrust = 0.1;
}

/* calculations for spacecraft characteristics*/

double spacecraft::calcVel(double r, double sMj, orbit &o) {
    double v = sqrt(o.mass * o.G * (2/r - 1/sMj));
    return v;
}

double spacecraft::calcAcc(double r, double v, orbit &o){
    double a = pow(v, 2) / r;
    return a;
}

double spacecraft::calcMeanAnomaly(double p, double t, double tP, orbit &o) {
    double mA = 2 * M_PI * (t - tP) / p;
    return mA;
}

double spacecraft::calcEccAnomaly(double mA, double e, double acc) {
    double newEcc = mA + e;
    if (mA > M_PI) {
        newEcc = mA - e;
    }
    
    double oldEcc = newEcc + 0.001;
    while (abs(newEcc - oldEcc > acc)) {
        oldEcc = newEcc;
        newEcc = oldEcc + (mA - oldEcc + e*sin(oldEcc)) / (1 - e*cos(oldEcc));
    }

    double eccAnomaly = newEcc;
    return eccAnomaly;
}

double spacecraft::calcTrueAnomaly(double eA, double e) {
    double beta = e / (1 + sqrt(1 - pow(e, 2)));
    trueAnomaly = eA + 2 * atan(beta * sin(eA) / (1 - beta * cos(eA)));
    trueAnomaly = fmod(trueAnomaly, 2*M_PI);
    if (trueAnomaly < 0) {
        trueAnomaly = trueAnomaly + 2*M_PI;
    }
    return trueAnomaly;
}

double spacecraft::calcTimeToPeri(double mA, double sMj, orbit &o) {
    double meanMotion = sqrtf(o.mass * o.G / pow(sMj, 3));
    double timeToPeri = meanAnomaly / meanMotion;
    return timeToPeri;
}

double spacecraft::calcTimeToApo(double mA, double sMj, orbit &o) {
    double timeToApo;
    if (time < o.period / 2) {
        timeToApo = calcTimeToPeri(mA, sMj, o) - o.period / 2;
    } else {
        timeToApo = calcTimeToPeri(mA, sMj, o) + o.period / 2;
    }
    return timeToApo;
}
