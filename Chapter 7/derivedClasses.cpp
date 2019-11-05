// Introduction to inheritance (derived classes)

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
public:
  // set m_sum to zero because since we will be summing elements together, it's nice to have this done right away
  double m_sum = 0;
public:
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

int main(int argc, char const *argv[]) {
  // The following commented code shows that the [] operator overload works
  // DList A;
  // for (int i = 0; i < 10; i++)
  // {
  //   std::cout << A[i] << "\n";
  // }

  // create an instance "stairs" that belongs to the class PCFunc
  PCFunc stairs;
  // Illustrate that despite the fact that the object stairs belongs to the class PCFunc, we are still able to use the member functions of the base class DList
  for (int i = 0; i < 10; i++)
  {
    std::cout << stairs[i] << "\n";
  }

  // To show that EvalPCFunc() function works and that it is using the values from m_list from DList
  for (double x = 0.05; x < 1; x+=0.1)
  {
    std::cout << x << "\t" << stairs.EvalPCFunc(x) << "\n";
  }

  // Shows that getSum sums the elements in m_list from DList class
  Series nOverTen;
  std::cout << nOverTen.getSum() << "\n";
  return 0;
}
