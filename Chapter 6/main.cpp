#include <iostream>
#include "IntArray.h" // include header file "IntArray.h" so we can use our class

// To compile:
// g++ -c IntArray.cpp
// g++ -c main.cpp
// g++ IntArray.o main.o
// ./a.out
// OR
// g++ IntArray.cpp main.cpp

// main function
int main(int argc, char const *argv[]) {
  IntArray A(4); // create an instance of IntArray class, object name = A

  // go through each element to set elements to i+1 based on index i
  for (int i = 0; i < 4; i++)
  {
    A.setElement(i, i+1);
  }
  // call print array function
  A.printArray();

  return 0;
}
