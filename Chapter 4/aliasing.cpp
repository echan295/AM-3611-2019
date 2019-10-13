#include <iostream>

// Aliasing

int main(int argc, char const *argv[]) {
  // Assign the value 3 to a
  int a = 3;
  // Assign the address of a to pointer p_a
  int* p_a = &a;

  // Print the value assigned to p_a
  std::cout << *p_a << "\n";
  // Print the address of a (to show that the address never changed, only the value)
  std::cout << &a << "\n";

  // Assign the value that the pointer points to
  *p_a = 10;

  // Print a: shows that if you change the value using the pointer, it will change the value of a
  std::cout << a << "\n";

  // The address is still the same
  std::cout << p_a << "\n";
  return 0;
}
