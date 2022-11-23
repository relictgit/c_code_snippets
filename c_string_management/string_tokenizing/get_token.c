#include "get_token.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *get_specific_token(char string[], char delimeter[], int position) {
  char *string_token = NULL;
  string_token = strtok(string, delimeter);
  int counter = 1;
  while (string_token != NULL) {
    if (counter == position) {
      break;
    }
    string_token = strtok(NULL, delimeter);
    ++counter;
  }
  return string_token;
}

void tokenize_string() {
  char string[] = "This Text is Token 1:This text is Token2:Token3";
  printf("lets start with a easy task tokenizing a string\n");
  printf("string: %s\n", string);
  char *string_token = NULL;
  char delimeter[] = ":";
  int position = 3;
  printf("string tokenised by position 3: %s\n",
         get_specific_token(string, delimeter, position));
}
