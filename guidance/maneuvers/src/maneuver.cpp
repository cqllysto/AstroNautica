

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
    double newSMJ = (o.apoapsis + o.periapsis) / 2;
    deltaV = sqrt(o.G * o.mass/ o.apoapsis * (2/o.periapsis - 1/newSMJ)) - 
        (o.G*o.mass/o.apoapsis);
    double vel = sc.vel;
    sc.vel = vel + deltaV;


}


void maneuvers::raiseApo(orbit &o, spacecraft &sc) {
    

}
