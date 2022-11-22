#include "generator.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  /* ToDo
   * 1. generate a random amount of characters.
   * 2. it must be a combination of digits, lower and upper case letters and
   * other characters
   * 3. the maximum number of characters should be considered as to be chosen by
   * the user
   */

  int passwd_lenght = 0;

  printf("Enter a length for the password that needs to be provided!\nYour "
         "Passwd length: ");
  scanf("%d", &passwd_lenght);

  generator(passwd_lenght);

  return EXIT_SUCCESS;
}
