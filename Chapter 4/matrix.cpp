#include <iostream>
// how to dynamically alocate a matrix (non-contiguous)
int main(int argc, char const *argv[]) {
  // initialize variables
  int** A;
  int rows, cols;
  rows = 9;
  cols = 9;

  // making an array of pointers (to indicate the number of rows)
  A = new int* [rows];
  // making an array for each pointer in A to make a matrix
  for (int i = 0; i < rows; i++)
  {
    A[i] = new int [cols];
  }

  // print the addresses of all elements in the first row
  for (int i = 0; i < cols; i++)
  {
    std::cout << &A[0][i] << "\t";
  }

  std::cout << "\n";

  // print the address of all elements in the second row (notice that each row is stored in a different memory space)
  for (int i = 0; i < cols; i++)
  {
    std::cout << &A[1][i] << "\t";
  }
  std::cout << "\n";


  // deleting arrays of integers
  for (int i = 0; i < rows; i++)
  {
    delete[] A[i];
  }

  // delete array of pointers
  delete[] A;
  return 0;
}
