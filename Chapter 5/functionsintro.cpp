#include <iostream>
#include <cmath>

// function protocols
int findMinimum(int a, int b);
double findMaximum(double a, double b);
void printString(std::string s);

int main(int argc, char const *argv[]) {
  // call a function
  int q = findMinimum(3, 6);
  std::cout << q << "\n";
  // not correct because the variable type of r and t are not integers, although runs without errors
  double r = findMinimum(3, 6);
  std::cout << r << "\n";
  bool t = findMinimum(3, 6);

  // Declare some variables
  double z = 6.0, x = 2.5;
  double p;
  // call another function
  p = findMaximum(z, x);
  std::cout << p << "\n";

  // call another function
  printString("Hello World!");
  return 0;
}

// conventionally, functions are written here (after the main function)
int findMinimum(int a, int b){
// "int" is the return variable type
// findMinimum is our function name
// a, b are our arguments (integers)
  if (a < b)
  {
    return a;
  }
  else
  {
    return b;
  }
  // Disclaimer: we're not considering a = b
}

double findMaximum(double a, double b){
  // findMaximum is our function name
  // double a, double b is our arguments
  // we are returning a double
  if (a > b)
  {
    return a;
  }
  else
  {
    return b;
  }
  // Disclaimer: we're not considering a = b
}

void printString(std::string s)
{
  std::cout << s << "\n";
  // note that void function has no return
  // We need "void" to indicate to C++ that there is no return value
}
