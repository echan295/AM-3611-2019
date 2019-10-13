// passing arrays through functions
#include <iostream>

// function prototypes
void assignElementValue(double A[], int i, double value);
void assignElementValueP(double* A, int i, double value);
void assignMatrixValue(double** A, int i, int j, double value);

int main(int argc, char const *argv[]) {
  // for the first function, we do not need to use dynamically allocated arrays because we are not passing a pointer
  double A[5];
  for (int i = 0; i < 5; i++)
  {
    assignElementValue(A, i, 2*i);
    std::cout << A[i] << "\n";
  }

  // for the second function, we need to use dynamically allocated arrays because we want to pass a pointer
  double *B;
  B = new double[5];
  for (int i = 0; i < 5; i++)
  {
    assignElementValueP(B, i, 3*i);
    std::cout << B[i] << "\n";
  }
  delete[] B;

  // example similar to the second example, but for matrix
  double **C;
  C = new double*[5];
  C[0] = new double[5*5]; // contiguous memory allocation
  for (int i = 1; i < 5; i++)
  {
    C[i] = C[i-1] + 5;
  }

  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      assignMatrixValue(C, i, j, i*j);
      std::cout << C[i][j] << "\t";
    }
    std::cout << "\n";
  }

  delete[] C[0];
  delete[] C;
  return 0;
}

// create function that assigns value to the ith element of A (using A[])
void assignElementValue(double A[], int i, double value)
{
  A[i] = value;
}

// create function that assigns value to the ith element of A (using *A)
void assignElementValueP(double* A, int i, double value)
{
  A[i] = value;
}

// create function that assigns value to the i, jth element of A (using **A)
void assignMatrixValue(double** A, int i, int j, double value)
{
  A[i][j] = value;
}
