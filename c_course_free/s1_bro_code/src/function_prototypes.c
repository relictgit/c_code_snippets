#include "../header/function_prototypes.h"
#include <stdio.h>

// if no header file is used the function prototype lands here
// void print_helloworld(char name[], int age);

short main_function_prototypes ()
{
  // function prototypes, what are those
  // function declaration, w/o a body, before main()
  // ensures that calls to a function are made with the correct arguments
  //
  // IMPORTANT NOTES
  // Many c compilers do not check for parameter matching
  // Missing arguments wil result in unexpected behavior
  // A function prototype causes the compiler to flag an error
  // if arguments are missing.
  // such thing is also happening while splitting the code into src and header
  // files but here the function prototypes and all other initializations such
  // as structs, etc. are placed within the header files and the declaration of
  // the source code is landing inside the src files.

  return 0;
}

// here would follow the function declaration
// void print_helloworld(char name[], int age) {}
