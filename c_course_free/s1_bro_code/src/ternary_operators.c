#include "../header/ternary_operators.h"
#include <stdio.h>

int find_max (int num1, int num2)
{
  /* if/else notation */

  /*if (num1 > num2) {
    return num1;
  } else {
    return num2;
  }*/

  /* using ternary operators */
  return (num1 > num2) ? num1 : num2;
}

short main_ternary_operators ()
{
  // ternary operators = shortcut of if/else when
  //                     assigning/returning a value
  // (condition) ? value of if true : value if false
  int max = find_max (3, 4);
  printf ("the maximum number from 3 and 4 is: %d\n", max);
  return 0;
}
