#include <iostream>

class IntArray
{
private:
  int *mA; // pointer that points to array
  int mlength; // variable to store length
public:
  // make our constructor
  IntArray(int length)
  {
    // set variable mlength
    mlength = length;
    // make array according to length
    mA = new int[length];
    // to show when constructor is called
    std::cout << "The array has been made\n";
  }

  // function that returns the length of the array
  int getLength()
  {
    return mlength;
  }

  // function to get the value of the element of the array
  int getElement(int index)
  {
      return mA[index];
  }

  // function to set the value of the element of the array (doesn't return anything)
  void setElement(int index, int value)
  {
    mA[index] = value;
  }

  // c++ automatically makes a implicit copy constructor
  // we will overwrite the one that c++ makes in the following (by using the same name as the class)
  //in this case because we are using pointers, we need to make our own
  IntArray(const IntArray& org_array)
  {
    mlength = org_array.mlength;
    mA = new int [mlength];
    for (int i = 0; i < mlength; i++)
    {
      mA[i] = org_array.mA[i];
    }
  }

  // make our destructor
  // similar to constructor, no return type
  ~IntArray()
  {
    delete[] mA;
    std::cout << "The array has been deleted\n";
  }
};

int main(int argc, char const *argv[]) {
  IntArray A(5); // create an instance, the length of the array A is 5
  std::cout << A.getLength() << "\n"; // print the length of the array
  A.setElement(2, 90); // set A[2] = 90 (we cannot use [] because they are not defined in our class)
  // since mA is private, we cannot simply index mA[index]
  // instead:
  std::cout << A.getElement(2) <<"\n";

  IntArray B(A); // use the copy constructor that we have made
  std::cout << B.getLength() << "\n";

  return 0;
}
