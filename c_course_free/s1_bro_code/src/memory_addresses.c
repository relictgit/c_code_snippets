#include "../header/memory_addresses.h"
#include <stdio.h>

short main_memory_addresses() {
  // memory = an array of bytes within RAM (street)
  // memory block = a single unit (byte) within memory, used to hold some values
  // (person) memory address = the address of where a memory block is located
  // (house address)

  char a = 'X';
  char b = 'Y';
  char c = 'Z';

  printf("sizeof a: %lu bytes\n", sizeof(a));
  printf("sizeof b: %lu bytes\n", sizeof(b));
  printf("sizeof c: %lu bytes\n", sizeof(c));

  printf("address of a: %p\n", &a);
  printf("address of b: %p\n", &b);
  printf("address of c: %p\n", &c);

  return 0;
}
