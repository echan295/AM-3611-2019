// September 18, 2019
#include <iostream>

int main(int argc, char const *argv[]) {
  bool a = true; //boolean
  bool b;
  // example of assigning condition to bool variable
  b = (5 > 2);
  std::cout << b << "\n";

  std::cout << a << "\n";
  std::cout << (6 < 5) << "\n";
  // When printed true = 1, false = 0
  if (a)
  {
    std::cout << "yay!\n";
  }
  else
  {
    std::cout << "lol\n";
  }
  return 0;
}
