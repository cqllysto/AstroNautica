# AstroNautica
AstroNautica is a spacecraft guidance and navigation project that employs C++ as the core language and Python as the input interface (not yet implemented). The project focuses on advanced orbital maneuver planning and basic attitude control modes. AstroNautica is designed to be used in NASA's trick simulator in order to offer a robust system for simulation.

## Program Details:
Simplifications and Assumptions:
    Assume 2d system with no inclination changes.
    Maneuvers can only be performed at periapsis or apoapsis (if the orbit is circular, then the    spacecraft is set to behave as if it is always at periapsis).
    The spacecraft orbits a gravity well of earth characteristics, but there is no physical body simulated yet.
    Maneuver burns happen instantly, rather than over a period of time.

## Spacecraft:
    Describes the current position using the mean and true anamoly.
    Features current velocity, acceleration, simulation time, and distance from earth.
    Features time to periapsis and time to apoapsis.
    Features current yaw, pitch, and roll as well as thrust, spin rate and drift of spacecrafts.

## Maneuvers:
    change Apoapsis
    change Periapsis
    circularize orbit
    hohmann transfer
    bi-elliptical transfer
    bi-impulse transfer

## Controls:
    Using bang bang control to control yaw, pitch, and roll axis.
    Spin stabilization to spin the spacecraft around a specific point in space (Earth).
    3 axis stabilization to stabilize yaw, pitch, and roll to a specific point.


### To-Do List:
    Update the S_define file with control files
    Add the Earth sensor for control and attitude calibration
    Complete the abort maneuver function
    Write the biElliptical maneuver function
    Rewrite homann, circOrbit, bi-impulse to call changeApo and changePeri for simplicity
    Add the update functions to update orbital and spacecraft parameters as simulation is running
    Write test functions to test each class functionality
    Ask r/KerbalSpaceProgram and r/programming for feedback

### Future Plans:
    Implement a PID control loop instead of bang bang
    Add 3rd dimension functionality with inclination changes
    Make maneuvers valid at any point of the orbit
    Add the earth and a crash function

