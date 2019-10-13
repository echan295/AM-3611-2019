#include <iostream>
#include <fstream> // file stream header
#include <cassert>

// Count the number of lines in file
int main(int argc, char const *argv[]) {
  // open file to read
  std::ifstream rf("output.dat");
  // makes sure that file is open/file exists
  assert(rf.is_open());

  // initialize count to 0 in order to count number of lines in file
  int count = 0;

  // declare variables to store values read from file
  double dummy1, dummy2, dummy3;

  // perform while loop to count # of lines
  // condition of the while loop is to make sure that we are not at the end of file (eof)
  while (!rf.eof()) // eof = end of file
  {
    // read in values from file row by row
    // remember we have 3 columns:
    // dummy1 stores the first values, dummy2 stores the second values, etc.
    rf >> dummy1 >> dummy2 >> dummy3;
    // rf.fail() makes sure that values from file has been read into variables dummy1, dummy2, and dummy3
    if (!rf.fail())
    {
      // increase count if values are stored into the variables successfully
      count++;
    }
    // previous example to show that without the if statement, you will not get the correct line count
    // count++;
  }
  // print number of lines in the file being read
  std::cout << count << "\n";

  // close file
  rf.close();
  return 0;
}
