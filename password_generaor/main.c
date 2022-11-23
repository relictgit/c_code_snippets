#include "generator.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int passwd_lenght = 0;

  /* printf("Enter a length for the password that needs to be provided!\nYour "
         "Passwd length: ");
  scanf("%d", &passwd_lenght); */

  if (argc == 2) {
    passwd_lenght = atoi(argv[1]);
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
