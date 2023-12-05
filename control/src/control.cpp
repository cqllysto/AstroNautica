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
#include <Eigen/Dense>
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


// Kalman Filtering

using namespace Eigen;

// Kalman filter parameters
const double alpha = 0.98; // Blending factor

// Process noise covariance (tune based on system characteristics)
const double Q_roll = 1e-4;
const double Q_pitch = 1e-4;
const double Q_yaw = 1e-4;

// Measurement noise covariance (tune based on sensor characteristics)
const double R_roll = 1e-2;
const double R_pitch = 1e-2;
const double R_yaw = 1e-2;

// State transition model: Euler angles update based on gyro rates
void stateTransition(Vector3d& state, const Vector3d& gyro, double dt) {
    state += gyro * dt;
}

// Observation model: Convert direction vector to Euler angles
Vector3d observationModel(const Vector3d& direction) {
    Vector3d angles;
    angles(0) = atan2(direction(1), direction(0)); // Roll
    angles(1) = atan2(-direction(2), sqrt(direction(0)*direction(0) + direction(1)*direction(1))); // Pitch
    angles(2) = 0.0; // Yaw (Assuming single-axis sensor)
    return angles;
}

// Kalman filter update: Prediction and Correction steps
void kalmanUpdate(Vector3d& state, const Vector3d& gyro, const Vector3d& observation, double dt) {
    // Prediction step
    stateTransition(state, gyro, dt);

    // Calculate predicted observation based on predicted state
    Vector3d predictedObservation = observationModel(Vector3d::UnitX()); // Example direction vector (X-axis)

    // Correction step (Update state based on sensor measurements)
    Vector3d innovation = observation - predictedObservation;

    // Kalman gain calculation
    Matrix3d H; // Observation matrix (Jacobian of observation model)
    H.setIdentity();
    
    Matrix3d K = H * (H.transpose() * H + R_roll * Matrix3d::Identity()).inverse();

    // Update state estimate
    state += K * innovation;

    // Update covariance matrix (optional if you need to track uncertainty)
    Matrix3d I = Matrix3d::Identity();
    I -= K * H;
}

int main() {
    // Initial state estimate (roll, pitch, yaw)
    Vector3d stateEstimate(0.0, 0.0, 0.0);

    // Gyro measurements (angular rates)
    Vector3d gyro(0.01, 0.02, 0.03); // Example angular rates (rad/s)

    // Earth/Sun sensor measurements (direction vector)
    Vector3d sunDirection(1.0, 0.0, 0.0); // Example direction vector (X-axis)

    // Convert initial direction vector to Euler angles
    Vector3d observation = observationModel(sunDirection);

    // Time step (assuming constant)
    double dt = 0.1;

    // Kalman filter update
    kalmanUpdate(stateEstimate, gyro, observation, dt);

    // Display the final estimated Euler angles
    std::cout << "Estimated Euler Angles (Roll, Pitch, Yaw): " << stateEstimate.transpose() << std::endl;

    return 0;
}
