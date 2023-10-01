/*************************************************************************
PURPOSE: (Represent the state and initial conditions of a spacecraft)
**************************************************************************/

#ifndef SPACECRAFT_H
#define SPACECRAFT_H

#include "../../../guidance/orbit/include/orbit.h"

// Spacecraft class
class spacecraft {
    public:
        // position and guidance characteristics
        double radius;      /* *io m distance from earth to spacecrafts current position */
        double calcVel(double radius, double semiMajor, orbit &o);
        double vel;         /* *io m/s current velocity of spacecraft */
        double calcAcc(double radius, double vel, orbit &o); 
        double acc;         /* *io m/s current velocity of spacecraft */
        double time;        /* *io s simulation time */
        double timeAtPeri;  /* *io s time when at peri (0) */
        double calcMeanAnomaly(double period, double time, double timePeri, orbit &o); 
        double meanAnomaly; /* *io rad current mean anomaly */
        double calcEccAnomaly(double meanAnomaly, double eccentricity,
                double acc); /* ** */
        double eccAnomaly;  /* *io rad current eccentric anomaly */
        double calcTrueAnomaly(double eccAnomaly, double eccentricity); 
        double trueAnomaly; /* *io rad current true anomaly */
        double calcTimeToPeri(double meanAnom, double semiMajor, orbit &o); 
        double timeToPeri;  /* *io s countdown to periapsis */
        double calcTimeToApo(double meanAnom, double semiMajor, orbit &o);   
        double timeToApo;   /* *io s countdown to apoapsis */

        // control characteristics
        double yaw;             /* *io rad yaw */
        double pitch;           /* *io rad pitch */    
        double roll;            /* *io rad roll */
        double thrust;          /* *io rad angular thrust of the RCS control thrusters */
        double spinRate;        /* *io rad/s spin rate of the spacecraft */

        spacecraft();
};

#endif
