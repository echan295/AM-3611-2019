// September 18, 2019
#include <iostream>

int main(int argc, char const *argv[]) {
  // Chapter 2
  // Declare variables
  int p = 30, q = 10;
  // if statement
  if (p < 10)
  {
    std::cout << "This is printed.\n";
  }
  else if (p > 20)
  {
    std::cout << "This print something something else. \n";
  }
  else // else: everything but the condition in if
  {
    std::cout << "This prints something else. \n";
  }
  return 0;
}
