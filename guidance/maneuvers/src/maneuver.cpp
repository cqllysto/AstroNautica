

#include "../include/maneuvers.h"
#include "../../../model/spacecraft/include/spacecraft.h"
#include "../../orbit/include/orbit.h"
#include <cmath>
#include <iostream>

using namespace std;

maneuvers::maneuvers() {
    double deltaV = 0;
}

void maneuvers::circOrbit(orbit &o, spacecraft &sc) {
    double apoBurn = false;
    double periBurn = false;
    while (!apoBurn) {
        double oldSmj = o.semiMajor; 
        double apo1 = o.apoapsis - (o.apoapsis - o.periapsis)/2;
        double sMj1 = ((apo1) + o.periapsis)/2; 
        if (sc.trueAnomaly == 0) {
            deltaV = o.calcVelPeri(sMj1, o.periapsis) - o.velPeri;
            o.velApo = o.calcVelApo(sMj1, apo1);
            double periBurn = true;
            sc.vel = o.velPeri + deltaV;
            // update all simulation parameters here
        } else if (periBurn && sc.trueAnomaly == pi/2) {
            deltaV = o.calcVelApo(oldSmj, o.apoapsis) - o.velPeri;
            o.velPeri = o.calcVelPeri(oldSmj, o.periapsis);
            sc.vel = o.velApo + deltaV;
            apoBurn = true;
        }
    }

}

void maneuvers::hohmann(orbit &o, spacecraft &sc, double sMj) {
    double targetApo = 2*sMj - o.periapsis;
    double apoBurn = false;
    double periBurn = false;
    while (!apoBurn) {
        double sMj1 = ((targetApo) + o.periapsis)/2; 
        if (sc.trueAnomaly == 0) {
            deltaV = o.calcVelPeri(sMj1, o.periapsis) - o.velPeri;
            o.velApo = o.calcVelApo(sMj1, targetApo);
            double periBurn = true;
            sc.vel = o.velPeri + deltaV;
            // update all simulation parameters here
        } else if (periBurn && sc.trueAnomaly == pi/2) {
            deltaV = o.calcVelApo(sMj, o.apoapsis) - o.velPeri;
            o.velPeri = o.calcVelPeri(sMj, o.periapsis);
            sc.vel = o.velApo + deltaV;
            apoBurn = true;
            // update all simulation parameters here
        }
    }
    // recursion??
    // hohmann(orbit &o, spacecraft &sc, double sMj);

}

void maneuvers::raiseApo(orbit &o, spacecraft &sc) {
    

}
