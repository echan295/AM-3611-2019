#ifndef FRACTIONHEADERDEF
#define FRACTIONHEADERDEF

class Fraction
{
  // declare private variables
  double m_numerator;
  double m_denominator;
public:
  // constructor, with default value numerator = 0, denominator = 1 (these values should only be)
  Fraction(double numerator = 0, double denominator = 1);
  double getNumerator() const; //the object will not be changed
  double getDenominator();
  // friend functions are able to access private member variables
  // notice that we put the keyword friend in front of the function here
  friend double getNumerator(const Fraction &frac);
  friend double getDenominator(const Fraction &frac);
  // keep in mind that there are two ways to overload binary + (both ways are called the same way frac1+frac2)
  // Method 1: use friend function
  friend Fraction operator+(const Fraction &frac1, const Fraction &frac2);
  // Method 2: use member function (frac1 is the object)
  Fraction operator+(const Fraction &frac2) const;
};

#endif
