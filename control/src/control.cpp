/******************************* TRICK HEADER ****************************
PURPOSE: (calculations for the spacecraft attributes)
*************************************************************************/


/* Model include files */
#include "../include/control.h"
#include "../../guidance/orbit/include/orbit.h"
#include "../../model/spacecraft/include/spacecraft.h"
#include "../../model/earthSensor/include/sensor.h"
#include <cmath>
#include <iostream>
using namespace std;

/* constructor */
control::control(){
    
}

// Need to add drift into the melting pot

void control::bangBang(spacecraft &sc, double targetVal, string axis) {
    const double tolerance = 0.01;
    double thrust = sc.thrust;
    double val;
    if (axis == "yaw") {
        val = sc.yaw;
    } else if (axis == "roll") {
        val = sc.roll;
    } else if (axis == "pitch") {
        val = sc.pitch;
    } else if (axis == "spinRate") {
        val = sc.spinRate;
    }
    
    double error = targetVal - val;

    // Apply control input
    if (error > tolerance) {
        val += thrust;
    } else if (error < -tolerance) {
        val -= thrust;
    } else {
        // no control input needed
    }

    if (axis == "yaw") {
            sc.yaw = val;
        } else if (axis == "roll") {
            sc.roll = val;
        } else if (axis == "pitch") {
            sc.pitch = val;
        }  else if (axis == "spinRate") {
            sc.spinRate = val;
        }   

}

void control::stabYaw(spacecraft &sc, double targetVal) {
    bangBang(sc, targetVal, "yaw");
}
void control::stabRoll(spacecraft &sc, double targetVal){
    bangBang(sc, targetVal, "roll");
}
void control::stabPitch(spacecraft &sc, double targetVal){
    bangBang(sc, targetVal, "pitch");
}

void control::spinStabilize (spacecraft &sc, orbit o) {
    double targetSpinRate = 2*M_PI / o.period;
    bangBang(sc, targetSpinRate, "spinRate");
}

void control::stab3Axis (spacecraft &sc, double targetYaw, 
    double targetPitch, double targetRoll) {
    bangBang(sc, targetPitch, "pitch");
    bangBang(sc, targetYaw, "yaw");
    bangBang(sc, targetRoll, "roll");
}
