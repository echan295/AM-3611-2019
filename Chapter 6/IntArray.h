// This is called a header file (.h)

// #ifndef  INTARRAYHEADERDEF checks whether the token has been defined earlier in the file or in an included file
//#ifndef = if not defined, INTARRAYHEADERDEF is called a token
#ifndef  INTARRAYHEADERDEF
// if token has not been defined, then define using #define
// then define
#define INTARRAYHEADERDEF

// Declare class in header file
class IntArray
{
private:
  // similar to before, declare all variables in private
  int mlength;
  int* mA;
public:
  // similar to before, put all functions in public, but only put first line of function here
  // You can think of the following as the function prototype
  IntArray(int length);
  ~IntArray();
  int getLength();
  int getElement(int index);
  void setElement(int index, int value);
  void printArray();
};

#endif // end #ifndef
