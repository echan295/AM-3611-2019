// September 11, 2019

#include <iostream>
#include <cmath>

int main(int argc, char const *argv[]) {
  // Declare all variables
  double a = 5;
  double b = 2;
  // M_PI is from cmath header
  double pi = M_PI;
  int c = 3;
  int d = 7;
  // Explicit conversion from int to double for c and d 
  double t = ((double) c) / ((double) d);
  int q = c/d;
  // Print a*b
  std::cout << a << "x" << b << " = " << a*b << "\n";
  // Print a/b
  std::cout << a << "/" << b << " = " << a/b << "\n";

  //trig functions
  std::cout << sin(pi) << "\n";
  std::cout << cos(pi) << "\n";

  //Inverse trig function (simply add "a" in front of trig function)
  std::cout << acos(-1) << "\n";

  //Log base 10
  std::cout << log10(1000) << "\n";
  // ln()
  std::cout << log(100) <<"\n";

  // Dividing c/d
  std::cout << c << "/" << d << " = " << ((double) c)/((double) d) << "\n";
  // Integer division
  std::cout << c/d << "\n";
  return 0;
}
