// creating a function for Newton's method
#include <iostream>
#include <cmath>

// function protocols (don't worry too much about function overloading right now---we will learn about it later)
void Newton(double *A, double x0);
void Newton(double *A);

int main(int argc, char const *argv[]) {
  double *A;
  A = new double [5];
  // Newton(A, 0.5);
  // or
  A[0] = 0.5;
  Newton(A);
  // print the elements in the array
  for (int i = 0; i < 5; i++)
  {
    std::cout << A[i] << "\n";
  }
  delete[] A;
  return 0;
}

// one way of creating function for Newton's method: initializing the x0 in the function
void Newton(double *A, double x0)
{
  // f = x^2 - 1 <- the function that we are solving the solution of
  A[0] = x0;
  for (int i = 1; i < 5; i++)
  {
    A[i] = A[i-1] - (pow(A[i-1], 2) - 1)/(2*A[i-1]);
  }
}

// another way of creating function for Newton's method: initialize the x0 in the main function and passing the array to the function
// This is the way I want you to initialize your array in Assignment 3, part B
void Newton(double *A)
{
  // f = x^2 - 1 <- the function that we are solving the solution of
  for (int i = 1; i < 5; i++)
  {
    A[i] = A[i-1] - (pow(A[i-1], 2) - 1)/(2*A[i-1]);
  }
}
