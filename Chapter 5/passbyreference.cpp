#include <iostream>
#include <cmath>

// function prototype
void calculateXY(double r, double theta, double &x, double &y);

int main(int argc, char const *argv[]) {
  double r = 5.0, theta = M_PI;
  double x, y; // note that we do not use pointers here
  calculateXY(r, theta, x, y);
  std::cout << x << "\t" << y << "\n";
  return 0;
}

// using "&", we "pass by reference"
// essentially, what gets carried out here is the same as "passing by pointer"
// the compiler (c++) does everything "automatically"
void calculateXY(double r, double theta, double &x, double &y)
{
  x = r*cos(theta);
  y = r*sin(theta);
}
