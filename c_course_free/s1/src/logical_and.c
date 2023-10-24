#include "../header/logical_operators.h"
#include <stdbool.h>
#include <stdio.h>

short logical_and() {
  // logical operators
  // --> && (AND) checks if 2 conditions are true

  float temp = 25;
  bool sunny = false;

  if (temp >= 0 && temp <= 30 && sunny == true) {
    printf("The weather is good\n");
  } else {
    printf("The weather is bad\n");
  }

  return 0;
}
