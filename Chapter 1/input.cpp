// September 13, 2019

#include <iostream>

int main(int argc, char const *argv[]) {
  // Declare variables
  int a, b;
  double c, d;
  // For first assignment, you need to write "and hit RETURN"
  std::cout << "The program adds two numbers. Please enter one integer and then hit RETURN \n";
  // User puts input
  std::cin >> a;

  // Ask for another numbers
  std::cout << "Enter another integer and then hit RETURN\n";
  std::cin >> b;

  std::cout << "The sum of " << a << " and " << b << " is " << a+b << ".\n";

  std::cout << "Now this program multiplies two numbers. Please enter both numbers then hit RETURN.\n";
  std::cin >> c >> d;

  std::cout << "The product is " << c*d << ".\n";
  return 0;
}
