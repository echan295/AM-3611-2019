#include <iostream>

// Addresses and Pointers
// Chapter 4.1

int main(int argc, char const *argv[]) {
  int a = 4;
  // Address (&) of a
  std::cout << &a << "\n";

  int *p_a, *p_b; // Pointer (int)
  double* p_c; // an example of other variable type (double)

  // assign pointer p_a to address of a
  p_a = &a;

  std::cout << p_a << "\n"; //prints address
  std::cout << *p_a << "\n"; // dereference pointer -> prints the value of a

  // WARNING
  // p_b = &3; // no address, gives you error

  // introduce "new"; this makes space in your computer to store
  p_b = new int;
  p_c = new double;

  std::cout << p_b << "\n";
  std::cout << *p_b << "\n"; // For newer c++ gives 0, older c++ may give other results

  // assign value to p_b
  *p_b = 2;
  std::cout << *p_b << "\n";

  // delete "new" pointers (ALWAYS DO THIS WHEN CREATING "NEW" POINTERS)
  delete p_b;
  delete p_c;

  return 0;
}
