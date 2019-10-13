#include <iostream>
#include <cmath>

// function prototype (this is where you declare your default values)
// Note that your default values have to come last (or else it messes up the order of the arguments)
double NewtonsMethod(double x0, double tol = 1e-6, double max_iter = 10);

int main(int argc, char const *argv[]) {
  // when calling the function, since tol and max_iter have been set default values,
  // you do not need to include them in the class
  std::cout << NewtonsMethod(0.5) << "\n";

  // However, if you want to use different values for tol and max_iter, you still can by simply inputting values in the argument
  std::cout << NewtonsMethod(0.5, 1e-8, 100) << "\n";
  return 0;
}

double NewtonsMethod(double x0, double tol, double max_iter)
{
  // f(x) = x^2 - 1
  int count = 0;
  // in class, I messed up the brackets in fabs, but it has now been fixed
  while ((fabs(pow(x0, 2) - 1) > tol) && (count < max_iter))
  {
    // print to demonstrate the number of iterations & calculate residuals to see when loop terminates
    std::cout << count << "\t" << fabs((pow(x0, 2) - 1)) << "\n";
    // simple Newton's method
    x0 = x0 - (pow(x0, 2) - 1)/(2*x0);
    count++;
  }
  return x0;
}
