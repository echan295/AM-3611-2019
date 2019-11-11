// Introduction to inheritance (derived classes)
#include <iostream>
#include <cmath>
#include <cassert>

// base class
class DList
{
// the protected access modifier allows derived classes to access contents, but not the main function
// the private access modifier does not allow derived classes to access contents, so if you want to inherit member variables, use the access modifier protected.
protected:
  // declare pointer m_list
  double* m_list; // = {0., 1./10, 2./10, 3./10, 4./10, 5./10, 6./10, 7./10, 8./10, 9./10};
  // length of m_list (so that we will later be able to change the length of m_list)
  int m_N;
public:
  // constructor that takes N (the length of the list) as an argument
  DList(int N)
  {
    m_N = N;
    m_list = new double [m_N];
    std::cout << "DList has been made.\n";
  }
  // destructor
  ~DList()
  {
    delete[] m_list;
  }
  // overload [] operator
  double& operator[](const int index)
  {
    return m_list[index];
  }
};

// make a derived class called PCFunc (piece-wise function)
// all members from DList class will be inherited by derived class PCFunc
class PCFunc : public DList
{
private: // changed to private (since this is the end of the inheritance chain, we can set the access modifier to private like we always have done)
  double m_lft;
  double m_rgt;
  double m_h;
public:
  // constructor with default values (added the argument N, and added : DList(N), so C++ knows that N refers to m_N in DList class)
  PCFunc(double lefthandside = 0.0 , double righthandside = 1.0, int N = 10) : DList(N)
  {
    // establish the domain of x
    m_lft = lefthandside;
    m_rgt = righthandside;
    // break the domain into m_N-1 parts (and find length of each part)
    m_h = (m_rgt - m_lft)/m_N; // although m_N is defined in class DList, we are able to use it because PCFunc is a derived class from DList
    std::cout << "PCFunc has been made.\n";
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
private: // even though Polynomial is derived from this class, Polynomial does not need to inherite this m_sum variable, and therefore, we can set the access modifier to private instead of protected
  // set m_sum to zero because since we will be summing elements together, it's nice to have this done right away
  double m_sum = 0;
public:
  // constructor, takes argument N, ": DList(N)" tells C++ that N corresponds to m_N
  Series(int N) : DList(N)
  {
    std::cout << "Series has been made\n";
  }
  // create a function called getSum() that will return the sum of elements in m_list
  double getSum()
  {
    m_sum = 0.0;
    for (int i = 0; i < m_N; i++)
    {
      m_sum += m_list[i];
    }
    return m_sum;
  }
};

// inheritance chain (this Polynomial class is derived from the Series class which is derived from the DList class (base class))
class Polynomial : public Series
{
private:
  double m_lft;
  double m_rgt;
public:
  // Constructor
  // Note that we use : Series(N) instead of : DList(N), it has to match the class that the class is derived from (i.e. since this class (Polynomial) is derived from Series, we use Series here instead of DList)
  Polynomial(double leftendpoint, double rightendpoint, int N) : Series(N)
  {
    m_lft = leftendpoint;
    m_rgt = rightendpoint;
    std::cout << "Polynomial has been made.\n";
  }
  // member function to evalulate polynomial
  // A[0] + A[1]x + A[2]x^2 + ... A[n]x^n
  double evalPoly(double x)
  {
    assert((x >= m_lft) && (x <= m_rgt));
    double sum = 0.0;
    for (int i = 0; i < m_N; i++)
    {
      sum += m_list[i]*pow(x, i);
    }
    return sum;
  }
};

int main(int argc, char const *argv[]) {
  // The following commented code shows that the [] operator overload works
  // DList A(10);
  // for (int i = 0; i < 10; i++)
  // {
  //   A[i] = (double) i/(double) 10;
  // }
  // for (int i = 0; i < 10; i++)
  // {
  //   std::cout << A[i] << "\n";
  // }

  // create an instance "stairs" that belongs to the class PCFunc
  PCFunc stairs;
  // assign values to elements in stairs
  for (int i = 0; i < 10; i++)
  {
    stairs[i] = (double) i/(double) 10;
  }
  // To show that EvalPCFunc() function works and that it is using the values from m_list from DList
  for (double x = 0.05; x < 1; x+=0.1)
  {
    std::cout << x << "\t" << stairs.EvalPCFunc(x) << "\n";
  }

  // Shows that getSum sums the elements in m_list from DList class
  Series nOverTen(10);
  // assign values to elements in nOverTen
  for (int i = 0; i < 10; i++)
  {
    nOverTen[i] = (double) i/(double) 10;
  }
  std::cout << nOverTen.getSum() << "\n";

  // create an instance P
  Polynomial P(-1.0, 1.0, 10);
  // assign values to the elements in P
  for (int i = 0; i < 10; i++)
  {
    P[i] = (double) i/(double) 10;
  }
  // print the result of evalPoly (expect 0 because m_list[0] = 0)
  std::cout << P.evalPoly(0) << "\n";

  return 0;
}
