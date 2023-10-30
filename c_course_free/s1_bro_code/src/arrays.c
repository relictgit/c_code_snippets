#include "../header/arrays.h"
#include <stdio.h>

short main_arrays() {
  // array = a data structure that can store many values of the same data type.

  double prices[] = {5.0, 10.0, 25.5};

  for (unsigned long i = 0; i < sizeof(prices) / sizeof(prices[0]); i++) {
    printf("price element %lu of prices is: €%lf\n", i, prices[i]);
  }

  return 0;
}
