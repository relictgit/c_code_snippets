#include "generator.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int passwd_lenght = 0;

  printf("Enter a length for the password that needs to be provided!\nYour "
         "Passwd length: ");
  scanf("%d", &passwd_lenght);

  generator(passwd_lenght);

  return EXIT_SUCCESS;
}
