#include <iostream>

int main(int argc, char const *argv[]) {
  double A[2][2] = {{0, 1}, {1, 0}};
  double B[2] = {5, 7};
  double C[2]; // In previous version, I initialize all elements to 0 here

  for (int i = 0; i < 2; i++)
  {
    C[i] = 0; // In this version, I initalize each element to 0 each outer loop
    for (int j = 0; j < 2; j++)
    {
      C[i] += A[i][j]*B[j];
    }
  }

  std::cout << C[0] << "\n" << C[1] << "\n";
  return 0;
}
