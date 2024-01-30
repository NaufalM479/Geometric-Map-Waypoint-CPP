#include <iostream>
#include <math.h>
#include <iomanip>
#define PI 3.14
using std::cout; using std::endl; using std::setprecision;

void generateSquarePath(double currentLat, double currentLon, double heading, double sideLength) {
  // Convert side length from meters to degrees (1 degree = 111.32 km)
  double sideLengthDegrees = sideLength / 111320.0;

  // Convert heading from degrees to radians
  double headingRad = heading * PI / 180.0;

  // Calculate new coordinates for each corner of the square
  double squareCoords[4][2];
  squareCoords[0][0] = currentLat + sideLengthDegrees * cos(headingRad);
  squareCoords[0][1] = currentLon + sideLengthDegrees * sin(headingRad);

  squareCoords[1][0] = currentLat + sideLengthDegrees * cos(headingRad + PI / 2.0);
  squareCoords[1][1] = currentLon + sideLengthDegrees * sin(headingRad + PI / 2.0);

  squareCoords[2][0] = currentLat + sideLengthDegrees * cos(headingRad + PI);
  squareCoords[2][1] = currentLon + sideLengthDegrees * sin(headingRad + PI);

  squareCoords[3][0] = currentLat + sideLengthDegrees * cos(headingRad + 3 * PI / 2.0);
  squareCoords[3][1] = currentLon + sideLengthDegrees * sin(headingRad + 3 * PI / 2.0);

  // Calculate translation vector
  double translationLat = currentLat - squareCoords[0][0];
  double translationLon = currentLon - squareCoords[0][1];

  // Translate all waypoints
  for (int i = 0; i < 4; i++) {
    squareCoords[i][0] += translationLat;
    squareCoords[i][1] += translationLon;
  }

  // Print the translated coordinates
  for (int i = 0; i < 4; i++) {
    cout << "Waypoint " << i + 1;
    cout << setprecision(8) << ": Lat " << squareCoords[i][0];
    cout << setprecision(8) << ", Lon " << squareCoords[i][1] << endl;
  }

  // Continue in the initial heading
  double initialHeadingRad = headingRad;

  // Number of waypoints to continue in the initial heading
  int numWaypoints = 5;
 
  cout << "Continuing to initial heading: " << endl;
  
  for (int i = 0; i < numWaypoints; i++) {
    currentLat += sideLengthDegrees * cos(initialHeadingRad);
    currentLon += sideLengthDegrees * sin(initialHeadingRad);
    cout << "Lat ";
    cout << setprecision(8) << currentLat;
    cout << ", Lon ";
    cout << setprecision(8) << currentLon << endl;
  }
}


int main() {
    generateSquarePath(40.741895, -73.98930777777778, 90, 100);
}

//- WP di translasi based on selisih wp 1 ke posisi awal
//- wp di mulai dari titik 0