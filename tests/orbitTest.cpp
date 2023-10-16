/******************************* TRICK HEADER ****************************
PURPOSE: Test the Orbit Class
*************************************************************************/


/* Model include files */
#include <iostream>
#include <cmath>

#include "../guidance/orbit/include/orbit.h"

using namespace std;

int main() {
    orbit o;

    // radius of the earth is 6 378.1 kilometers
    // or 6,378,100 meters

    o.velPeri = 7670; // m/s
    o.periapsis = 400000 + 6378100; // m
    cout << "periapsis is " << o.periapsis << endl;

    o.calcApoapsis(o.velPeri, o.periapsis);
    cout << "apoapsis is " << o.apoapsis << endl;

    o.calcSemiMajor(o.apoapsis, o.periapsis);
    o.calcE(o.apoapsis, o.periapsis);
    o.calcSemiMinor(o.apoapsis, o.periapsis);
    o.calcPeriod(o.semiMajor);
    o.calcVelApo(o.apoapsis, o.semiMajor);

    cout << "semiMajor is " << o.semiMajor << endl;
    cout << "semiMinor is " << o.semiMinor << endl;
    cout << "period is " << o.period << endl;
    cout << "velApo is " << o.velApo << endl;
    cout << "velPeri is " << o.velPeri << endl;
    cout << "eccentricity is " << o.e << endl;
    cout << "mass is " << o.mass << endl;
    cout << "gravitational constant is " << o.G << endl;
    return 0;
}


// compile command:
// g++ orbitTest.cpp ../guidance/orbit/src/orbit.cpp -o orbitTest

