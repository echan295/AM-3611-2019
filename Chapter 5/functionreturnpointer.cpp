#include <iostream>
#include <cmath>

// function prototype
double** makeMatrix(int rows, int cols);
void deleteMatrix(double** A);

int main(int argc, char const *argv[]) {
  double** B = makeMatrix(3, 3);
  // assign elements in B to values, so that it is an identity matrix
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      if (i == j)
      {
        B[i][j] = 1;
      }
      else
      {
        B[i][j] = 0;
      }
      // print each element in array B
      std::cout << B[i][j] << "\t";
    }
    std::cout << "\n";
  }
  // deallocate pointers
  deleteMatrix(B);
  return 0;
}

// function to make matrix (dynamically allocated contiguous)
double** makeMatrix(int rows, int cols)
{
  double** A;
  A = new double* [rows];
  // contiguous array
  A[0] = new double [rows*cols];
  for (int i = 1; i < rows; i++)
  {
    A[i] = A[i-1] + cols;
  }
  return A;
}

// function to delete pointers created by makeMatrix function
// note that we are using double** as a variable type (we'll learn more about this later)
void deleteMatrix(double** A)
{
  // since we dynamically allocated the array contiguously, we can simply delete the pointers without knowing the number of rows and cols
  delete[] A[0];
  delete[] A;
}
