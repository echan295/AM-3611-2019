// Scope

#include <iostream>

int j; // global variable

int main(int argc, char const *argv[]) {
  {
    // local variable
    int i;
  }
  // please do not use same variable name as local and global
  j = 5 // this is okay because j is global
  i = 0; // out of scope (will give you errors)
  return 0;
}// everything in between curly braces is called "block"
