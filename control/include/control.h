/*************************************************************************
PURPOSE: (Control the orientation and attitude spacecraft)
**************************************************************************/

#ifndef CONTROL_H
#define CONTROL_H


// Spacecraft class
class control {
    public:
        void bangBang(spacecraft &sc, double targetVal, string axis);
        void stabYaw(spacecraft &sc, double targetVal);
        void stabRoll(spacecraft &sc, double targetVal);
        void stabPitch(spacecraft &sc, double targetVal);
        void spinStabilize(spacecraft &sc, orbit o);
        void stab3Axis(spacecraft &sc, double targetYaw, double targetPitch,
            double targetRoll);
        control();
};

// Kalman filter
#include <Eigen/Dense>

class KalmanFilter {
public:
    // Constructor
    KalmanFilter();

    // Destructor
    ~KalmanFilter();

    // Initialize the Kalman filter with initial state estimate
    void initialize(const Eigen::Vector3d& initialState);

    // Perform a Kalman filter update
    void update(const Eigen::Vector3d& gyro, const Eigen::Vector3d& observation, double dt);

    // Get the current state estimate
    Eigen::Vector3d getState() const;

private:
    // State variables
    Eigen::Vector3d stateEstimate;

    // Process noise covariance matrix (tune based on system characteristics)
    double Q_roll;
    double Q_pitch;
    double Q_yaw;

    // Measurement noise covariance matrix (tune based on sensor characteristics)
    double R_roll;
    double R_pitch;
    double R_yaw;

    // Kalman filter matrices
    Eigen::Matrix3d H; // Observation matrix

    // Kalman filter functions
    void stateTransition(const Eigen::Vector3d& gyro, double dt);
    Eigen::Vector3d observationModel(const Eigen::Vector3d& direction);
};

#endif
