//September 18, 2019
#include <iostream>

int main(int argc, char const *argv[]) {
  // Declare p
  int p = 7;
  // Declare q
  int q = 50;
  if ((p < 10) || (p > 20)) // || -- OR
  {
    std::cout << "This get printed.\n";
  }

  // && -- AND
  if ((p < 5) && (q > 20)) // Both conditions must be met in order to execute statement
  {
    std::cout << "Yay!\n";
  }
  return 0;
}
