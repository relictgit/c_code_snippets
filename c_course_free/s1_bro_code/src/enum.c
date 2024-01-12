#include "../header/enum.h"
#include <stdio.h>

short main_enum ()
{
  // enum = a user defined type of named integer identifiers
  //        helps to make a program more readable

  enum day today = Sun;

  // printf("today is: %d\n", today);

  if (/*today == 0 || today == 6*/ today == Sun || today == Sat)
  {
    printf ("It is weekend.\n");
  }
  else
  {
    printf ("I have to work today...\n");
  }

  return 0;
}
