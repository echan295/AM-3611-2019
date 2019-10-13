#include <iostream>
#include <cmath>

// function prototype
void calculateXY(double theta, double r, double* x, double* y);

int main(int argc, char const *argv[]) {
  double theta = M_PI;
  double r = 5;
  double x, y;
  calculateXY(theta, r, &x, &y);
  std::cout << "The value of x is " << x << "\n";
  std::cout << "The value of y is " << y << "\n";
  return 0;
}

// example to show how to return two values instead of one (use pointers)
void calculateXY(double theta, double r, double* x, double* y)
{
  // since we are passing address (pointers), we need to dereference the pointer when assigning value
  *x = r*cos(theta);
  *y = r*sin(theta);
}
// just double (not pointers/address) are for inputing values in functions
// In order for us to change the value of x and y (which are defined in the main function),
// we need to use the address of the variables so that we can assign a value to them in the function
