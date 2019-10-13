// September 20, 2019
// while loops

#include <iostream>

int main(int argc, char const *argv[]) {
  int x = 0;
  int n = 5;
  int count = 0;
  while ((x < n) && (count < 30))
  // If OR, (x < n) always true
  // If AND (x < n) always true, but count < 30 not true when count == 30, therefore true && false == false
  {
    count++;
    x = x - 1;
    // x += 1; //another way of writing x = x+1
    // x++; // another way of writing x = x+1
    std::cout << x << "\n";
  }
  std::cout << "hello, your loop has stopped\n";
  return 0;
}
