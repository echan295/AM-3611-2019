// function pointers (aka pointers that point to functions)
#include <iostream>
#include <cmath>

// function prototype
double sqrt10(double x);

int main(int argc, char const *argv[]) {
  // how to create a pointer that points to a function
  // note that the pointer takes a function that returns a double variable, hence why the first word is "double"
  // pFunc is our "variable name"
  // in the other parenthesis, it indicates the number of argument of the function we are pointing to: since sqrt10 function only has one argument (type double), we put "(double x)"
  double (*pFunc)(double x);
  pFunc = sqrt10; // in textbook, they write &sqrt10, but sqrt10 and &sqrt10 means the same thing
  std::cout << (*pFunc)(5) << "\n"; // explicit dereference (function pointer)
  std::cout << pFunc(5) << "\n"; // implicit dereference (function pointer) --- only works for newer compilers >C++11
  std::cout << sqrt10(5) << "\n"; // how we normally would call a function
  return 0;
}

// make a function that a pointer will point to
double sqrt10(double x)
{
  return sqrt(x) - 10;
}
