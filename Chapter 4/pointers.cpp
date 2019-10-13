#include <iostream>
// more on dynamically allocated arrays
int main(int argc, char const *argv[]) {
  // vector
  // initialize pointer A
  int* A;
  // pointer points to array of integers of length 5
  A = new int[5];
  // assign value to each element in A
  for (int i = 0; i < 5; i++)
  {
    A[i] = i+1;
    // one way of printing elements in A
    std::cout << A[i] << "\n";
    // another way of printing elements in A
    std::cout << *(A+i) << "\n";
    // print address of each element in A (note that integers take 3 bytes)
    std::cout << &A[i] << "\n";
  }
  // delete pointer
  delete[] A;

  // set variable n to 510
  int n = 510;
  // initialize pointer B
  double* B;
  // have pointer B pointer to an array of length n
  B = new double[n];

  for (int i = 0; i < 5; i++)
  {
    // print the address of each element in B
    std::cout << B + i << "\n";
  }
  // delete variable
  delete[] B;
  return 0;
}
