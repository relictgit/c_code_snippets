#include "generator.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  long unsigned passwd_lenght = 0;

  if (argc == 2) {
    passwd_lenght = (long unsigned)atoi(argv[1]);
    generator(passwd_lenght);
    return EXIT_SUCCESS;
  } else {
    fprintf(stderr,
            "----------PROBLEM----------\n"
            "arguments passed: %i\n"
            "arguments needed: 2\n"
            "Usage: %s <password_length>\n",
            argc, argv[0]);
    return EXIT_FAILURE;
  }
}
