#include "../header/switch_statements.h"
#include <stdio.h>
#include <stdlib.h>

short example_switch_statement() {
  // switch = A more efficient alternative of using many "else if"
  //          switch_statements allows a value to be tested
  //          for equality against many cases

  char grade;

  printf("\nEnter a letter grade: ");
  scanf("%c", &grade);

  /* bad practise
  if (grade == 'A') {
    printf("perfect!\n");
  } else if (grade == 'B') {
    printf("You did good!\n");
  } else if (grade == 'C') {
    printf("You did okay\n");
  } else if (grade == 'D') {
    printf("At least it is not an E\n");
  } else if (grade == 'E') {
    printf("You suck, but at least it is not an F\n");
  } else if (grade == 'F') {
    printf("Congradulations... you fucked up and failed\n");
  } else {
    printf("that is not a valid grade\n");
  } */

  /* better practise */

  switch (grade) {
  case 'A':
    printf("perfect!\n");
    break;
  case 'B':
    printf("You did good!\n");
    break;
  case 'C':
    printf("You did okay\n");
    break;
  case 'D':
    printf("At least it is not an E\n");
    break;
  case 'E':
    printf("You suck, but at least it is not an F\n");
    break;
  case 'F':
    printf("Congradulations... you fucked up and failed\n");
    break;
  default:
    printf("that is not a valid grade\n");
    break;
  }

  return 0;
}
