// September 20, 2019
// for loops

#include <iostream>
#include <cmath>

int main(int argc, char const *argv[])
{
  double A[3] = {M_PI, 2.7, 1.6};
  int B[3][2] = {{1, 2}, {3, 4}, {5, 6}};
  double c[2] = {1.1, 2.2};
  double d[3] = {};

  // Printing array A using loops
  for (int i = 0; i < 3; i++)
  {
    std::cout << A[i] << "\n";
  }

  // Printing 2D array A using loops
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 2; j++)
    {
      std::cout << B[i][j] << "\t";
    }
    std::cout << "\n";
  }

  // Multiplying arrays B and c together to get d
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 2; j++)
    {
      d[i] += B[i][j]*c[j];
    }
    std::cout << d[i] << "\n";
  }

  return 0;
}
