

#include "../include/spacecraft.h"
#include "../../../guidance/orbit/include/orbit.h"
#include <cmath>
#include <iostream>

sc::sc(){

}

double sc::vel(double r, double sMj) {
    double v = sqrt(mass * G (2/r - 1/sMj));
    return v;
}

double sc::acc(double r, double v){
    double a = v^2 / r;
    return a;
}

double sc::meanAnomaly(double p, double t, double tP) {
    double mA = 2 * pi * (t - tP) / p;
    return mA;
}

double sc::eccAnomaly(double mA, double e, double acc) {
    double newEcc = mA + e;
    if (mA > pi) {
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

double sc::trueAnomaly(double eA, double e) {
    double beta = e / (1 + sqrt(1 - e^2));
    double trueAnomaly = eA + 2 * atan(beta * sin(eA) / (1 - beta * cos(eA)));
    trueAnomaly = trueAnomoly % (2*pi);
    if (trueAnomaly < 0) {
        trueAnomaly = trueAnomaly + 2*pi;
    }
    return trueAnomaly;
}

double sc::timeToPeri(double mA, double sMj) {
    double meanMotion = sqrt(mass * G / sMj^3);
    double timeToPeri = meanAnom / meanMotion;
    return timeToPeri;
}

double sc::timeToApo(double mA, double sMj) {
    double timeToApo;
    if (time < period / 2) {
        timeToApo = timeToPeri(mA, sMj) - period / 2;
    } else {
        timeToApo = timeToPeri(mA, sMj) + period / 2;
    }
    return timeToApo;
}





