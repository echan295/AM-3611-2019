// September 13, 2019

#include <iostream>

int main(int argc, char const *argv[]) {
  std::string s;
  std::cout << "Enter a silly statement then press RETURN. \n";
  // to get user's string use getline instead of cin
  std::getline(std::cin, s);

  std::cout << s << "\n";
  return 0;
}
