#include "generator.h"
#include <malloc.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generator(unsigned long passwd_len) {
  // prerequisite initializations
  int randomizer = 0;
  short num_selectors = 0;
  short max_digit_num = 10;
  short max_symbol_num = 10;
  short max_letter_num = 26;

  // seed the random number generator
  // with the current time so that the
  // number will be different every time
  srand((unsigned int)(time(NULL)));

  // char sets of the characters to choose from
  // note: char arrays are recommended to be set to a fixed size
  char digits[10] = "0123456789";
  ++num_selectors;
  char letters_lower[26] = "abcdefghijklmnopqrstuvwxyz";
  ++num_selectors;
  char letters_upper[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  ++num_selectors;
  char symbols[10] = "!@_-$^&*%?";
  ++num_selectors;
  // printf("-----debug-----\nselector number: %i\n", num_selectors);

  // initialization of the password variable
  // char passwd[passwd_len]; // vla initialization is not working in C
  char *passwd = (char *)calloc(passwd_len, sizeof(char));

  if (passwd == NULL) {
    fprintf(stderr, "ERROR: Memory not allocated!\n");
    exit(EXIT_FAILURE);
  }

  // to select the randomizer inside the loop
  randomizer = rand() % num_selectors;

  // build up the password string and print it as the output onto the screen
  for (long unsigned counter = 0; counter < passwd_len; ++counter) {
    if (randomizer == 1) {
      passwd[counter] = digits[rand() % max_digit_num];
      randomizer = rand() % num_selectors;
      printf("%c", passwd[counter]);
    } else if (randomizer == 2) {
      passwd[counter] = letters_lower[rand() % max_letter_num];
      randomizer = rand() % num_selectors;
      printf("%c", passwd[counter]);
    } else if (randomizer == 3) {
      passwd[counter] = letters_upper[rand() % max_letter_num];
      randomizer = rand() % num_selectors;
      printf("%c", passwd[counter]);
    } else {
      passwd[counter] = symbols[rand() % max_symbol_num];
      randomizer = rand() % num_selectors;
      printf("%c", passwd[counter]);
    }
  }
  printf("\n");
}
