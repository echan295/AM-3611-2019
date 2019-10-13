#include <iostream>
#include <cassert>

// End of chapter 3
// command line arguments

int main(int argc, char const *argv[]) {
  //check if number of command line arguments is correct
  if (argc != 3)
  {
    std::cout << "Number of entries are incorrect\n";
    // exit program unsuccessfully
    return 1;
  }

  // example of prompting the user for a value---do not save value to argv
  int a;
  std::cout << "Enter an integer\n";
  std::cin >> a; // When prompting user, use different variable instead of argv

  // argc = argument count
  // argv = argument vector
  // elements in argv always string
  int N = atoi(argv[1]); // atoi for int
  double n = atof(argv[2]); // atof for float
  // std::cout << argc << "\n" << argv[1] << "\n";
  std::cout << N << "\n" << n << "\n";
  return 0;
}
