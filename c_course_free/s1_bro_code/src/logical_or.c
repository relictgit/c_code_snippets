#include "../header/logical_operators.h"
#include <stdbool.h>
#include <stdio.h>

short logical_or ()
{
  // logical operators
  // --> || (OR) checks if at least 1 condition is true

  float temp = 25;
  bool sunny = true;

  if (temp <= 0 || temp >= 30 || sunny == false)
  {
    printf ("The weather is bad\n");
  }
  else
  {
    printf ("The weather is good\n");
  }

  return 0;
}
