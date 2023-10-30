/* user input function */
#include <stdio.h>
#include <string.h>

int user_input() {
  char name[25];
  int age;

  printf("Whats your name?");
  // scanf("%s", name); // reads user input until first whitespace appears,
  // there is a solution for this if whitespaces are needed
  fgets(name, sizeof(name), stdin);
  // name[strlen(name)-1] = '\0'; // need string.h, get rid of newline character
  printf("Hello %s\n\n", name);

  printf("How old are you?");
  scanf("%d", &age);
  printf("You are %d old\n", age);

  return 0;
}
