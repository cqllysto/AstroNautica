/*************************************************************************
PURPOSE: (Represent the state and initial conditions of a spacecraft)
**************************************************************************/

#ifndef SPACECRAFT_H
#define SPACECRAFT_H


// Spacecraft class
class sc {
    public:
        double radius;
        double vel(double radius, double semiMajor);
        double acc(double radius, double vel);
        double time;
        double timeAtPeri;
        double acc;
        double meanAnomaly(double period, double time, double timePeri);
        double eccAnomaly(double meanAnomaly, double eccentricity,
                double acc);
        double trueAnomaly(double eccAnomaly, double eccentricity);
        double timeToPeri(double meanAnom, double semiMajor);
        double timeToApo(double meanAnom, double semiMajor);
}

#endif
