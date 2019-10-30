#ifndef FRACTIONHEADERDEF
#define FRACTIONHEADERDEF

class Fraction
{
  // declare private variables
  double m_numerator;
  double m_denominator;
public:
  // constructor, with default value numerator = 0, denominator = 1 (these values should only be written here)
  Fraction(double numerator = 0, double denominator = 1);
  double getNumerator() const; //the object will not be changed
  double getDenominator();
  // friend functions are able to access private member variables
  // notice that we put the keyword friend in front of the function here
  friend double getNumerator(const Fraction &frac);
  friend double getDenominator(const Fraction &frac);
  // keep in mind that there are two ways to overload binary + (both ways are called the same way frac1+frac2), use one or the other, not both
  // Method 1: use friend function
  friend Fraction operator+(const Fraction &frac1, const Fraction &frac2);
  // Method 2: use member function (frac1 is the object)
  // Fraction operator+(const Fraction &frac2) const;

  // overload unary - (member function)
  // -a
  Fraction operator-() const;
  // binary - overload (member function)
  Fraction operator-(const Fraction &frac2) const;
  // assignment = operator overload
  Fraction& operator=(const Fraction &frac);

  // overloading standard operators
  // overloading << (for std::cout)
  // In this case, std::ostream& output would be your std::cout (which would be on the left side of <<)
  // and const Fraction &frac would be the object that you want to print (which would be on the right side of <<)
  friend std::ostream& operator<<(std::ostream& output, const Fraction &frac);

  // overloading comparison operators (friend functions)
  // overload "equal" (frac1 == frac2)
  friend bool operator==(const Fraction &frac1, const Fraction &frac2);
  // overload "not equal" (frac1 != frac2)
  friend bool operator!=(const Fraction &frac1, const Fraction &frac2);
  // overload "greater than" (frac1 > frac2)
  friend bool operator>(const Fraction &frac1, const Fraction &frac2);
  // overload "less than" (frac1 < frac2)
  friend bool operator<(const Fraction &frac1, const Fraction &frac2);
  double getValue();


};

/*
1. The operators =, [], (), must be overloaded using member functions
2. Unary operators should be overloaded using member functions
3. If you have binary operators in which the left argument (like +=, *=, -=) is modified, then use member function
4. If you have binary operators in which the left argument does NOT change (like +, -, *, /), then friend function is preferred
*/

#endif
