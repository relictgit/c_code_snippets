#include "../header/bitwise_operators.h"
#include <stdio.h>

short main_bitwise_operators() {
  // Bitwise operators = special operators used in bit level programming
  //                     (knowing binary is important for this topic)

  // & = AND
  // | = OR
  // ^ = XOR
  // << = left shift
  // >> = right shift

  int x = 6;      // 6 = 00000110
  int y = 12;     // 12 = 00001100
  int result = 0; // 0 = 00000000

  printf("example numbers are\n");
  printf("x: %d\ny: %d\nresult: %d\n", x, y, result);

  result = x & y;
  printf("result of x bitwise and y: %d\n", result);
  result = x | y;
  printf("result of x Bitwise or y: %d\n", result);
  result = x ^ y;
  printf("result of x Bitwise xor y: %d\n", result);
  result = y << 2;
  printf("result of y Bitwise left shift 2 time(s): %d\n", result);
  result = x >> 1;
  printf("result of x Bitwise right shift 1 time(s): %d\n", result);

  return 0;
}
