/*************************************************************************
PURPOSE: (Represent the state and initial conditions of a spacecraft)
**************************************************************************/

#ifndef SPACECRAFT_H
#define SPACECRAFT_H


// Spacecraft class
class sc {
    public:
        double radius;      /* *io m distance from earth to spacecrafts current position */
        double calcVel(double radius, double semiMajor); /* ** */
        double vel;         /* *io m/s current velocity of spacecraft */
        double calcAcc(double radius, double vel); /* ** */
        double acc;         /* *io m/s current velocity of spacecraft */
        double time;        /* *io s simulation time */
        double timeAtPeri;  /* *io s time when at peri (0) */
        double calcMeanAnomaly(double period, double time, double timePeri); /* ** */
        double meanAnomaly; /* *io rad current mean anomaly */
        double calcEccAnomaly(double meanAnomaly, double eccentricity,
                double acc); /* ** */
        double eccAnomaly;  /* *io rad current eccentric anomaly */
        double calcTrueAnomaly(double eccAnomaly, double eccentricity);     /* ** */
        double trueAnomaly; /* *io rad current true anomaly */
        double calcTimeToPeri(double meanAnom, double semiMajor);           /* ** */
        double timeToPeri;  /* *io s countdown to periapsis */
        double calcTimeToApo(double meanAnom, double semiMajor);            /* ** */
        double timeToApo;   /* *io s countdown to apoapsis */
}

#endif
