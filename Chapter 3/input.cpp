#include <iostream>
#include <fstream>
#include <cassert>

int main(int argc, char const *argv[]) {
  // Declare variables to store values read from file
  double A[9][3];
  double b[3];

  // open data file that you want to read from
  std::ifstream read_file("output.dat");
  // make sure that the file that you are reading from exists/is open
  assert(read_file.is_open());

  // since we know that there are 10 rows in the data file, and we only want to read 9 of them into A, we perform the loop 9 times and store the values into a 9x3 array called A
  for (int i = 0; i < 9; i++)
  {
    // read values row by row from data file
    read_file >> A[i][0] >> A[i][1] >> A[i][2];
  }

  // separately read the last line from the data file and store in different variable called b
  read_file >> b[0] >> b[1] >> b[2];

  // print A to show that we have successfully inputted data from file
  for (int i = 0; i < 9; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      std::cout << A[i][j] << "\t";
    }
    std::cout << "\n";
  }

  // print b to show that we have successfully inputted data from file
  for (int i = 0; i < 3; i++)
  {
    std::cout << b[i] << "\n";
  }

  // close file
  read_file.close();
  return 0;
}
