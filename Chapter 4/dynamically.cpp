#include <iostream>

int main(int argc, char const *argv[]) {
  // dynamically allocating a vector

  // create a pointer A
  int *A;
  // create space in your computer's memory to store 5 integer values in the form of an array
  A = new int [5];
  // You would index this kind of vector as A[0], A[1], ...
  for (int i = 0; i < 5; i++)
  {
    // Assign each element in A as i+1
    A[i] = i+1;
  }

  // Always delete your pointer, the [] indicates that A is storing a vector
  delete[] A;

  // Advantage to using dynamically allocated arrays
  // For some computers, this will give you errors because you cannot use a variable to assign a length to the array
  int n = 4;
  double B[n];

  // Dynamically allocating a matrix
  // Use a double pointer for matrix (a pointer that points to a pointer)
  double** C;
  // create space in your computer to store an array of pointers
  C = new double*[5];
  // create space in your computer to store an array of doubles for each pointer in array C
  for (int i = 0; i < 5; i++)
  {
    C[i] = new double[5];
  }
  // You would index the matrix as follows: C[0][0], C[0][1], C[0][2]

  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      // Assigning values to elements in C
      C[i][j] = i+j;
    }
  }

  // delete matrix
  // We have to go through each pointer that we created an array for and delete them
  for (int i = 0; i < 5; i++)
  {
    delete[] C[i];
  }

  // delete the pointer to array of pointers
  delete[] C;
  return 0;
}
