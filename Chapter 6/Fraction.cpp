#include "Fraction.h"
#include <cmath>
#include <cfloat>

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

// // Method 2: use member function
// Fraction Fraction::operator+(const Fraction &frac2) const
// {
//   Fraction fracsum;
//   if (m_denominator == frac2.m_denominator)
//   {
//     fracsum.m_numerator = m_numerator + frac2.m_numerator;
//     fracsum.m_denominator = m_denominator;
//   }
//   else
//   {
//     fracsum.m_numerator = m_numerator*frac2.m_denominator + frac2.m_numerator*m_denominator;
//     fracsum.m_denominator = m_denominator*frac2.m_denominator;
//   }
//   return fracsum;
// }

// unary - overload (member function)
Fraction Fraction::operator-() const
{
  Fraction frac;
  frac.m_numerator = -m_numerator;
  frac.m_denominator = m_denominator;
  return frac;
}

// binary - overload (member function)
Fraction Fraction::operator-(const Fraction &frac2) const
{
  Fraction fracdiff;
  // if denominators are the same, then we can simply subtract the numerators
  if (m_denominator == frac2.m_denominator)
  {
    fracdiff.m_numerator = m_numerator - frac2.m_numerator;
    fracdiff.m_denominator = m_denominator;
  }
  else // but if denominators are not the same, we will need to find a common denominator
  {
    fracdiff.m_numerator = m_numerator*frac2.m_denominator - frac2.m_numerator*m_denominator;
    fracdiff.m_denominator = m_denominator*frac2.m_denominator;
  }
  return fracdiff;
}

// overload << for std::cout
// output = std::cout
// frac = object from Fraction class
std::ostream& operator<<(std::ostream& output, const Fraction &frac)
{
  // output how the fraction should be displayed. Notices there is no "\n" at the end of statement
  return output << frac.m_numerator << "/" << frac.m_denominator;
}

// overload assignment (=) operator
Fraction& Fraction::operator=(const Fraction &frac)
{
  // essentially, you want to assignment ALL private variables to the corresponding private variables from frac
  m_numerator = frac.m_numerator;
  m_denominator = frac.m_denominator;
  // since our return type is Fraction& (notice the &), we need to return a Fraction object. *this is the object to which this function is a member of
  return *this;
}

// overload comparison equation (==) operator
bool operator==(const Fraction &frac1, const Fraction &frac2)
{
  // if numerators and denominators are the same, then we can say they are equal
  if ((frac1.m_numerator == frac2.m_numerator) && (frac1.m_denominator == frac2.m_denominator))
  {
    return true;
  }
  // however, it is typically not as simple, so we want to use the getValue() function to compare the results.
  // Since we are dealing with floating point, we shouldn't expect that the difference between frac1.getValue() and frac2.getValue() to be equal to 0.
  // Instead, we compare the difference to fabs(frac1.getValue())*DBL_EPSILON to help with scaling: larger values need more leeway
  else
  {
    if (fabs(frac1.getValue() - frac2.getValue()) < fabs(frac1.getValue())*DBL_EPSILON)
    {
      return true;
    }
    else
    {
      return false;
    }
  }
}

// overload comparison not equal (!=)
bool operator!=(const Fraction &frac1, const Fraction &frac2)
{
  // ensures that == and != are exclusionary (and that all cases are covered)
  return !(frac1 == frac2);
}

// evaluates the fraction in double precision
double Fraction::getValue()
{
  return (m_numerator/m_denominator);
}

// overload comparison greater than (>) operator
bool operator>(const Fraction &frac1, const Fraction &frac2)
{
  // compare the double precision equivallent rather than checking numerator and denominator
  if (frac1.getValue() > frac2.getValue())
  {
    return true;
  }
  else
  {
    return false;
  }
}

// overload comparison less than (<) operator
bool operator<(const Fraction &frac1, const Fraction &frac2)
{
  if (frac1.getValue() < frac2.getValue())
  {
    return true;
  }
  else
  {
    return false;
  }
}
