#include "IntArray.h" // You always need to include the header file
#include <iostream>
// This is where you define your function

// :: = scope resolution operator
// format: className::functionName(arguments)
// {
//
// }

// Constructor
IntArray::IntArray(int length)
{
  // set variable mlength
  mlength = length;
  // make array according to length
  mA = new int[length];
  // to show when constructor is called
  std::cout << "The array has been made\n";
}

// Destructor
IntArray::~IntArray()
{
  delete[] mA;
}

// Get length of array
int IntArray::getLength()
{
  return mlength;
}

// Get element of array at index
int IntArray::getElement(int index)
{
  return mA[index];
}

// Set element of array at index with value
void IntArray::setElement(int index, int value)
{
  mA[index] = value;
}

// print all elements in array
void IntArray::printArray()
{
  for (int i = 0; i < mlength; i++)
  {
    std::cout << mA[i] << "\n";
  }
}
