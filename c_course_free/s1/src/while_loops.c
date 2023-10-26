#include "../header/while_loops.h"
#include <stdio.h>
#include <string.h>

short main_while_loop() {
  // while loops = repeats a section of code possibly unlimited times
  // WHILE some condition remain true
  // a while loop might not execute at all

  char name[25] = "";
  printf("whats your name: ");
  fgets(name, sizeof(name), stdin);
  name[strlen(name) - 1] = '\0';

  while (strlen(name) == 0) {
    printf("You did not enter your name\n");
    printf("What is your name: ");
    fgets(name, sizeof(name), stdin);
    name[strlen(name) - 1] = '\0';
  }

  printf("Hello %s\n", name);

  return 0;
}
