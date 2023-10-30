#include "../header/return.h"
#include <stdio.h>

double square(double value) { return value * value; }

short main_return() {
  double value = 3.14159;
  double x = square(value);
  printf("square of %.2lf is: %.2lf\n", value, x);
  return 0;
}
