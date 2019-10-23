// Good example of a class

#include <iostream>

// make a class called "DateClass"
class DateClass
{
  // access modifier
private: // things that are private aren't able to be accessed by the main function
  // initialize variables privately (good)
  // data encapsulation: putting most (if not all) member variables in private and having member functions "get" or "set" the values
  int m_day;
  int m_month;
  int m_year;
public: // things that are public are able to be accessed by the main function
  // constructor (most of the time, we want to make our own)
  // conditions of a constructor:
  // 1. has to have the same name as class name
  // 2. no return type (not even void)
  // 3. this function will not be called by user

  // this constructor accepts no arguments
  DateClass()
  {
    // assign variables to these set values (when creating an instance, if you do not include the day, month, and year, this constructor will be called)
    m_day = 1;
    m_month = 1;
    m_year = -13000;
  }

  // this constructor accepts three arguments
  DateClass(int day, int month, int year)
  {
    // assign member variables to the values pased in argument
    m_day = day;
    m_month = month;
    m_year = year;
  }
  // create a function to set the Date
  void setDate(int day, int month, int year)
  {
    assert((day < 32) && (day > 0));
    m_day = day;
    m_month = month;
    m_year = year;
  }
  // create a "setter" function that sets the day
  void setDay(int day)
  {
    m_day = day;
  }
  // create a "getter" function that gets the day
  int getDay()
  {
    return m_day;
  }
  // create a copy constructor (not reallly a constructor, more like a function)
  // reason to pass reference rather than DateClass:
  // takes too much memory to copy into the function!
  void copyConstructor(const DateClass &d)
  {
    m_day = d.m_day;
    m_month = d.m_month;
    m_year = d.m_year;
  }
  // create function/method in public (okay)
  void printDate()
  {
    std::cout << m_year << "/" << m_month << "/" << m_day << "\n";
  }
};

int main(int argc, char const *argv[]) {
  // this was done before making our constructor (that required 3 arguments)
  DateClass today; // create an instance (today is the object and belongs to the class DateClass)
  today.setDate(21, 10, 2019); // call setDate function
  today.printDate(); // call printDate function

  // this was done after making our constructors
  DateClass tomorrow(22, 10, 2019); // called on the default constructor (that accepts 3 arguments)
  tomorrow.printDate(); // call printDate function (this should print the values that we specified when creating our instance)
  tomorrow.setDate(23, 10, 2019); // we can reset our values using the setDate function
  tomorrow.printDate(); // to show that the values have changed.

  // create another instance
  DateClass beginningOfTime; // this will call on the default constructor (that we made) without arguments
  beginningOfTime.printDate();
  beginningOfTime.setDay(5);
  std::cout << beginningOfTime.getDay() << "\n";
  beginningOfTime.printDate();
  DateClass copyBeginning(beginningOfTime); // calls the implicit copy constructor (the one that c++ makes)
  copyBeginning.printDate(); // result should be the same as beginningOfTime object
  DateClass copyBeginning2; // create another instance
  copyBeginning2.copyConstructor(beginningOfTime); // call copy function that we made
  copyBeginning2.printDate(); // result should also be the same
  return 0;
}
