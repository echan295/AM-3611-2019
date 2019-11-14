// Introduction to inheritance (derived classes)
// November 13, 2019

// This is an extension of "derivedClasses.cpp"

#include <iostream>
#include <cmath>
#include <cassert>

class DList
{
public: //this will be changed in a later class (aka we will be introduced to another access modifier)
  // set a list of 10 elements
  double m_list[10] = {0., 1./10, 2./10, 3./10, 4./10, 5./10, 6./10, 7./10, 8./10, 9./10};
  // length of m_list (so that we will later be able to change the length of m_list)
  double m_N = 10;
public:
  // overload [] operator
  double& operator[](const int index)
  {
    return m_list[index];
  }

  // overload << as a friend function
  friend std::ostream& operator<<(std::ostream& out, const DList& lst)
  {
    for (int i = 0; i < lst.m_N; i++)
    {
      out << lst.m_list[i] << "\t";
    }
    return out << "\n";
  }
};

// make a derived class called PCFunc (piece-wise function)
// all members from DList class will be inherited by derived class PCFunc
class PCFunc : public DList
{
public: // again, we will change this later (since I told you that setting member variables public is bad programming practice)
  double m_lft;
  double m_rgt;
  double m_h;
public:
  // constructor
  PCFunc(double lefthandside = 0.0 , double righthandside = 1.0)
  {
    // establish the domain of x
    m_lft = lefthandside;
    m_rgt = righthandside;
    // break the domain into m_N-1 parts (and find length of each part)
    m_h = (m_rgt - m_lft)/m_N; // although m_N is defined in class DList, we are able to use it because PCFunc is a derived class from DList
  }
  // function that will give you the "y" value for the corresponding "x" value according to m_list for piece-wise function
  double EvalPCFunc(double x)
  {
    // make sure that the x value is within domain
    assert((x >= m_lft) && (x < m_rgt));
    // find which index the x value corresponds to in the context of m_list
    int ix = (int) ((x - m_lft)/m_h);
    return m_list[ix];
  }
};

// make another derived class called Series
class Series : public DList
{
protected:
  // set m_sum to zero because since we will be summing elements together, it's nice to have this done right away
  double m_sum;
public:
  // virtual function, this will be called when a Series object called the evalSum function
  virtual double Func(double x, int i)
  {
    return 1.0;
  }
  // create a function called getSum() that will return the sum of elements in m_list
  double evalSum(double x = 0)
  {
    m_sum = 0.0;
    for (int i = 0; i < m_N; i++)
    {
      m_sum += m_list[i]*Func(x, i);
    }
    return m_sum;
  }

  //create a function to determine whether series is decreasing
  bool decreasing()
  {
    std::cout << "You are using Series::decreasing()\n";
    // Go through all elements in m_list and check whether the following element is less than the previous element
    for (int i = 1; i < m_N; i++)
    {
      if (m_list[i-1] <= m_list[i])
      {
        return false;
      }
    }
    return true;
  }

  // Since derived classes do not inherit friend functions from base class (DList),
  // we have to "re"-overload it in the derived class
  friend std::ostream& operator<<(std::ostream& out, const Series& srs)
  {
    // Instead of writing a for loop and printing each element, we call the << overload in the DList class
    // static_cast<DList>(srs) means that we are converting srs into DList class
    // This is similar to converting an int to a double
    return out << static_cast<DList>(srs);
  }
};

class Polynomial: public Series
{
private:
  double m_sum;
  // Option 1:
  // to make decreasing function private
  // Since the decreasing function is private, functions outside this class (such as the main function) cannot use the decreasing function
  // for example, in the main function, if we have Polynomial aPoly; we cannot call aPoly.decreasing();
  // using Series::decreasing;
  // However, we can use the decreasing function here in the class
  // Option 2:
  // Delete the function
  // Similar to Option 1
  // bool decreasing() = delete;
public:
  // virtual function (this function gets called when a Polynomial object calls the evalSum() function)
  // monomial basis
  virtual double Func(double x, int i)
  {
    return pow(x, i);
  }
  // override decreasing function (because Series::decreasing() may not necessarily be useful in the Polynomial case)
  // check A[i]x^i > A[i+1]x^(i+1)
  bool decreasing(double x)
  {
    std::cout << "You are using Polynomial::decreasing()\n";
    for (int i = 1; i < m_N; i++)
    {
      if (m_list[i-1]*pow(x, i-1) <= m_list[i]*pow(x, i))
      {
        return false;
      }
    }
    return true;
  }
};

int main(int argc, char const *argv[]) {
  Polynomial aPoly;
  // call Polynomial::decreasing() (the decreasing() function that we have defined in the Polynomial class)
  aPoly.decreasing(3.0);
  // calls Polynomial::decreasing(), but will give you errors because C++ thinks that you are missing an argument.
  // aPoly.decreasing();
  // calls the decreasing function defined in the Series class
  aPoly.Series::decreasing();

  // Shows that << operator has been overloaded in the DList class
  DList aList;
  std::cout << aList;
  // Shows that << operator has been overloaded in the Series class
  Series aSeries;
  std::cout << aSeries;

  // evaluates the sum of the elements in aSeries
  // Since aSeries belongs to the Series class, the Func() function that EvalSum uses is the one defined in Series
  std::cout << aSeries.evalSum() << "\n";

  // evaluates the polynomial at the given value of x
  // Since aPoly belongs to the Polynomial class, the Func() function that EvalSum (from Series class) uses is the one defined in the Polynomial class
  std::cout << aPoly.evalSum(0) << "\n";
  std::cout << aPoly.evalSum(1) << "\n";
  return 0;
}
