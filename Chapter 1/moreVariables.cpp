// September 13, 2019

#include <iostream>
// #include <string> //for assignment, do not include

int main(int argc, char const *argv[]) {
  // const = constant
  const double g = 9.8; // cannot change value
  // g = 2; // This gives an error

  // char (character) -- ascii
  char a = 'Q'; // notice that only single quotes
  std::cout << a << "\n";

  // error
  // char b = "4"; // notice double quotes which is string
  // std::cout << b << "\n";

  std::string s = "The dog jumped over the moon.";
  std::cout << s << "\n";

  return 0;
}
