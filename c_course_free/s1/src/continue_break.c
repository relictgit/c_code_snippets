#include "../header/continue_break.h"
#include <stdio.h>

short main_continue_break() {
  // continue = skips rest of code & forces the next iteration of the loop
  // break = exits a loop/switch

  for (int i = 1; i <= 20; i++) {
    if (i == 13) {
      continue;
    }
    if (i == 15) {
      break;
    }
    printf("index is: %d\n", i);
  }

  return 0;
}
