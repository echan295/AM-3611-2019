#include <iostream>
#include <fstream> // file stream
#include <cassert>
#include <cmath>

// Write to file (OUTPUT file)
int main(int argc, char const *argv[]) {
  double a[3] = {1.2, 3.2, .43};
  double pi = M_PI;

  // declare output
  // std::ofstream -> "type", write_output -> "variable"
  // "output.dat" -> filename
  std::ofstream write_output("output.dat");
  // ensures that output.dat is open/does exists
  assert(write_output.is_open());

  // loop 10 times to write to output 10 times
  for (int i = 0; i < 10; i++)
  {
    // similar to std::cout
    // write output to file called "output.dat"
    write_output << a[0] << "\t" << a[1] << "\t" << a[2] << "\t" << "\n";

    // precision of output (do not use value > 15 because double only stores 15 sig figs)
    write_output.precision(20);
    write_output << pi << "\n";
    // If you want to learn more about printing options, look at page 56 of class text
    // write_output.flush(); // used to print to file automatically to reduce size of memory storage, but SLOW
  }
  // closes files stream
  write_output.close();
  //another option, but you would not use both at the same time
  // write_output.flush();

  // if you try this after closing file stream, will not print to file
  write_output << a[0] << "\n";

  return 0;
}
