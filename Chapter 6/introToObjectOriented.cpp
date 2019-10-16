// Example to demonstrate the differences between traditional and object-oriented programming
// traditionally
// driveTo(Eunice, work)

// object oriented
// Eunice.driveTo(work)

// now onto an actual example
#include <iostream>

// we put our class here (between header and main function)
class Hello
{
  // access modifier (public: gives main function access to content, private: does not give main function access to content)
public: // add colon
  // create a function/method that prints "Hello World!"
  void printhello()
  {
    std::cout << "Hello World!\n";
  }
}; // Make sure you have semi colon

int main(int argc, char const *argv[]) {
  // printhello() // cannot simply call function in class
  Hello h; //h is the object that belongs to the class "Hello"
  h.printhello(); // since h belongs to the class "Hello" and the function "printhello()" is a method in this class, we are able to apply this function to the object
  // repeat to show that we can create many objects from the same class
  Hello p;
  p.printhello();
  return 0;
}
