// Bad example of a class (DO NOT EVER DO THIS)

#include <iostream>

// make a class called "DateClass"
class DateClass
{
  // access modifier
public:
  // initialize variables publicly (bad)
  int m_day;
  int m_month;
  int m_year;

  // create function/method in public (okay)
  void printDate()
  {
    std::cout << m_year << "/" << m_month << "/" << m_day << "\n";
  }
};

int main(int argc, char const *argv[]) {
  DateClass today; // create an instance (today is the object and belongs to the class DateClass)
  today.m_day = 16; // access the variables from the class and assign them values (bad)
  today.m_month = 10; // access the variables from the class and assign them values (bad)
  today.m_year = 2019; // access the variables from the class and assign them values (bad)
  today.printDate(); // call printDate function (okay)
  return 0;
}
