// September 20, 2019
// Newton's method x[n+1] = x[n] - f(x[n])/f'(x[n])
// f(x) = x^2 - 1

#include <iostream>
#include <cmath>

int main(int argc, char const *argv[]) {
  double x = 0.5;
  double tol = 1e-6; //10^-6
  int count = 0; // safeguard
  // fabs is absolute value of a floating point
  while ((fabs(x*x - 1) > tol) && (count < 30))
  {
    count++;
    // Newton's method
    x = x - (x*x - 1)/(2*x);
    std::cout << x << "\n";
  }
  // std::cout << x*x - 1 << "\n";
  return 0;
}
