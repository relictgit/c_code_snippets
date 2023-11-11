#include "../header/hello_world.h"
#include <stdio.h>

int main ()
{
  const char *word = hello ();
  printf ("the function hello() returned: %s\n", word);
  return 0;
}
