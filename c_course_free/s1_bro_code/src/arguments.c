#include "../header/arguments.h"
#include <stdio.h>

void print_birthday(char name[], char age) {
  printf("Happy Birthday %s\n", name);
  printf("You are %d years old\n", age);
}

short function_for_printing_happy_birthday_with_parameter_fn() {
  char name[] = "Bro";
  char age = 23;

  print_birthday(name, age);

  return 0;
}
