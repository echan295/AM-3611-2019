#include "Fraction.h"

//constructor (do not put default values here)
Fraction::Fraction(double numerator, double denominator)
{
  m_numerator = numerator;
  m_denominator = denominator;
}

// const member function to get numerator
// const member function works for both constant and non-constant objects
double Fraction::getNumerator() const
{
  return m_numerator;
}

// (non const) member function to get denominator
// non const member function works only on non-const objects, (does NOT work for const objects)
double Fraction::getDenominator()
{
  return m_denominator;
}

// friend (non member) function (getNumerator)
// friend functions are able to access private member variables
// notice that the keyword friend is not here
double getNumerator(const Fraction &frac)
{
  // frac.m_numerator is okay because this function is a friend
  return frac.m_numerator;
}

// friend (non member) function (getDenominator)
double getDenominator(const Fraction &frac)
{
  return frac.m_denominator;
}

// operator overload (binary +, frac1 + frac2)
// Method 1: using a friend function
Fraction operator+(const Fraction &frac1, const Fraction &frac2)
{
  Fraction fracsum;
  if (frac1.m_denominator == frac2.m_denominator)
  {
    fracsum.m_numerator = frac1.m_numerator + frac2.m_numerator;
    fracsum.m_denominator = frac1.m_denominator;
  }
  else
  {
    fracsum.m_numerator = frac1.m_numerator*frac2.m_denominator + frac2.m_numerator*frac1.m_denominator;
    fracsum.m_denominator = frac1.m_denominator*frac2.m_denominator;
  }
  return fracsum;
}

// Method 2: use member function
Fraction Fraction::operator+(const Fraction &frac2) const
{
  Fraction fracsum;
  if (m_denominator == frac2.m_denominator)
  {
    fracsum.m_numerator = m_numerator + frac2.m_numerator;
    fracsum.m_denominator = m_denominator;
  }
  else
  {
    fracsum.m_numerator = m_numerator*frac2.m_denominator + frac2.m_numerator*m_denominator;
    fracsum.m_denominator = m_denominator*frac2.m_denominator;
  }
  return fracsum;
}
