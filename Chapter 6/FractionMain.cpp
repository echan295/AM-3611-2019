#include <iostream>
#include "Fraction.h"

int main(int argc, char const *argv[]) {
  Fraction a; //because we aren't specifying numerator and denominator, default is numerator = 0, denominator = 1
  std::cout << a.getNumerator() << "/" << a.getDenominator() << "\n";

  // const object
  const Fraction b(4, 5);
  // since getDenominator member function is not const, we get error when calling b.getDenominator();
  // the following code is commented because it gives us an error
  // std::cout << b.getNumerator() << "/" << b.getDenominator() << "\n";
  std::cout << getNumerator(b) << "/" << getDenominator(b) << "\n";

  // operator overload, so a+b (where a and b are fractions) is okay (both methods are called this way)
  Fraction c = a+b;
  std::cout << getNumerator(c) << "/" << getDenominator(c) << "\n";
  return 0;
}
