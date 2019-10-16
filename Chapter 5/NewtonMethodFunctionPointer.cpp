#include <iostream>
#include <cmath>

// function prototype
double NewtonMethod(double (*pFunc)(double x), double (*pDFunc)(double x), double x0);
double func(double x);
double dfunc(double x);

int main(int argc, char const *argv[]) {
  // print results from the NewtonMethod function
  std::cout << NewtonMethod(func, dfunc, 0.5) << "\n";
  return 0;
}

// create a Newton Method function that takes two function pointers: one is the function that we are finding the solution to, the other is the derivative of the functions
// The function also takes the initial guess x0 as an argument
double NewtonMethod(double (*pFunc)(double x), double (*pDFunc)(double x), double x0)
{
  // since we are focusing on function pointers, we are going to iterate Newton's method 10 times using a for loop (we typically wouldn't do this in real life)
  for (int i = 0; i < 10; i++)
  {
    // carry out Newton's method
    x0 = x0 - (*pFunc)(x0)/(*pDFunc)(x0);
  }
  // return the calculated solution
  return x0;
}

// function that we want to solve the root for
double func(double x)
{
  return x*x - 1;
}

// derivative of the function that we want to solve the root for
double dfunc(double x)
{
  return 2*x;
}
