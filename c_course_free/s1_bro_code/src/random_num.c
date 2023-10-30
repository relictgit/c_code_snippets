#include "../header/random_num.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

short main_random_num() {
  // pseudo random numbers = a set of values or elements
  //                         that are statistically random
  //                         (do not use these for any
  //                         sort of cryptographic security)

  srand(time(0));

  int num1 = (rand() % 6) + 1;
  int num2 = (rand() % 6) + 1;
  int num3 = (rand() % 6) + 1;

  printf("%d\n", num1);
  printf("%d\n", num2);
  printf("%d\n", num3);

  return 0;
}
