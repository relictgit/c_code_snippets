#include "../header/if_statements.h"
#include <stdio.h>
#include <stdlib.h>

short example_if_statements ()
{
  int age = 0;

  printf ("Enter your age: ");
  scanf ("%d", &age);

  if (age >= 18)
  {
    printf ("You are now signed up!\n");
  }
  else if (age < 0)
  {
    printf ("You have not been born yet!\n");
  }
  else
  {
    printf ("You are too young to sign up!\n");
  }

  return 0;
}
