#include <iostream>
#include <cmath>

//function prototype
// matrix*vector
void Multiply(double** A, int rows, int cols, double* b, int len, double* c);
// scalar*matrix
void Multiply(double** A, int rows, int cols, double s, double** B);

int main(int argc, char const *argv[]) {
  // preparing for matrix multiplication
  double** A;
  A = new double*[2];
  A[0] = new double[2*2];
  for (int i = 1; i < 2; i++)
  {
    A[i] = A[i-1] + 2;
  }
  double* b, *c;
  b = new double[2];
  c = new double[2];
  double** B;
  B = new double*[2];
  B[0] = new double[2*2];
  for (int i = 1; i < 2; i++)
  {
    B[i] = B[i-1] + 2;
  }

  // we haven't declared any values, so we hope the answer is 0, 0
  // in your assignment, you should declare values here

  // Due to the arguments in calling the function, the compiler knows to use the matrix*vector function rather than the scalar*matrix function
  Multiply(A, 2, 2, b, 2, c);

  // print result (although pointless because we haven't assigned any values)
  for (int i = 0; i < 2; i++)
  {
    std::cout << c[i] << "\n";
  }

  // Due to the arguments, the compiler knows that this is calling the scalar*matrix function rather than the matrix*vector function
  Multiply(A, 2, 2, 4.6, B);

  delete[] A[0];
  delete[] A;
  delete[] b;
  delete[] c;
  delete[] B[0];
  delete[] B;
  return 0;
}

// Matrix * vector
void Multiply(double** A, int rows, int cols, double* b, int len, double* c)
{
  assert(cols == len);
  for (int i = 0; i < rows; i++)
  {
    c[i] = 0; // initialize to 0
    for (int j = 0; j < len; j++)
    {
      c[i] += A[i][j]*b[j];
    }
  }
}

// scalar*matrix
void Multiply(double** A, int rows, int cols, double s, double** B)
{
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      B[i][j] = s*A[i][j];
    }
  }
}
