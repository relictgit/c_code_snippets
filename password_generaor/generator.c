#include "generator.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generator(int passwd_len) {
  // prerequisite initializations
  int randomizer = 0;
  short num_selectors = 4;

  // seed the random number generator
  // with the current time so that the
  // number will be different every time
  srand((unsigned int)(time(NULL)));

  /* char sets of the characters to choose from */
  char digits[10] = "0123456789";
  char letters_lower[26] = "abcdefghijklmnopqrstuvwxyz";
  char letters_upper[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char symbols[10] = "!@_-$^&*%?";

  char passwd[passwd_len];

  // to select the randomizer inside the loop
  randomizer = rand() % num_selectors;

  for (int counter = 0; counter < passwd_len; ++counter) {
    if (randomizer == 1) {
      passwd[counter] = digits[rand() % 10];
      randomizer = rand() % num_selectors;
      printf("%c", passwd[counter]);
    } else if (randomizer == 2) {
      passwd[counter] = letters_lower[rand() % 26];
      randomizer = rand() % num_selectors;
      printf("%c", passwd[counter]);
    } else if (randomizer == 3) {
      passwd[counter] = letters_upper[rand() % 26];
      randomizer = rand() % num_selectors;
      printf("%c", passwd[counter]);
    } else {
      passwd[counter] = symbols[rand() % 10];
      randomizer = rand() % num_selectors;
      printf("%c", passwd[counter]);
    }
  }
}
