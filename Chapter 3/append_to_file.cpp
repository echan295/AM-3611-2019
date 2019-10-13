// Hint for Assignment 2 problem 3.1(d)

#include <iostream>
#include <fstream>

int main(int argc, char const *argv[]) {
  // Declare array x
  double x[4] = {1, 2, 2, 4};

  // open data file called x.dat. std::ios::app indicates that if the files x.dat already exists, then to append the output to the existing file
  std::ofstream w_o("x.dat", std::ios::app);
  assert(w_o.is_open());

  // print elements of x onto data file
  for (int i = 0; i < 4; i++)
  {
    w_o << x[i] << "\t";
  }
  w_o << "\n";

  // close file
  w_o.close();
  return 0;
}
