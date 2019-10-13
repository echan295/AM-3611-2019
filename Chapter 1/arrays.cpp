// September 11, 2019

#include <iostream>
#include <cmath>

int main(int argc, char const *argv[]) {
  //  Arrays!
  int A[2] = {6, 10};
  std::cout << A[0] << "\t" << A[1] << "\n";
  //  "Matrices" (2D array)
  double B[2][2] = {{M_PI, 2.71}, {3.2, 7.5}}; // {} gives array of zeros
  // B[0][0] = M_PI;
  std::cout << "B = \n";
  std::cout << B[0][0] << "\t" << B[0][1] << "\n";
  std::cout << B[1][0] << "\t" << B[1][1] << "\n";
  return 0;
}
