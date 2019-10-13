// Contiguous memory allocation for matrices (2D array)
// A contiguous array is an array stored in an unbroken block of memory: to access the next value in the array, we just move to the next memory address

#include <iostream>

int main(int argc, char const *argv[]) {
  // Declare and assign values for # of rows and columns for the matrix
  int rows = 3, cols = 5;
  // Declare A using a double pointer
  double** A;
  A = new double*[rows];
  // Create an array to store ALL elements for A for A[0] to point at
  A[0] = new double[rows*cols];
  // Assign the pointer A[i] to the corresponding element in the array that A[0] points to
  for (int i = 1; i < rows; i++)
  {
    A[i] = A[i-1] + cols;
  }

  // assigning values
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      A[i][j] = i+1;
      std::cout << A[i][j] << "\t";
    }
    std::cout << "\n";
  }

  // delete!! (remember to delete in the reverse order of "new")
  delete[] A[0];
  delete[] A;
  return 0;
}
