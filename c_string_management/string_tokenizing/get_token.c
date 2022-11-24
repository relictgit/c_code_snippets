#include "get_token.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void get_specific_token_referenze(char string[], char delimeter[], int position,
                                  char **string_token) {
  *string_token = strtok(string, delimeter);
  if (*string_token == NULL) {
    char *error = "There is nothing to tokenize!\n";
    printf("%s", error);
    exit(EXIT_FAILURE);
  }
  for (int counter = 1; counter < position; ++counter) {
    *string_token = strtok(NULL, delimeter);
  }
}

char *get_specific_token_value(char string[], char delimeter[], int position) {
  char *string_token = NULL;
  string_token = strtok(string, delimeter);
  if (string_token == NULL) {
    char *error = "There is nothing to tokenize!\n";
    printf("%s", error);
    return error;
  }
  for (int counter = 1; counter < position; ++counter) {
    string_token = strtok(NULL, delimeter);
  }
  return string_token;
}

void tokenize_string() {
  char string1[] = "This Text is Token 1:This text is Token2:Token3";
  char string2[] =
      "van-harem:Token:diddo:karlos:hamburger:good-old-crusty-crab";
  printf("lets start with a easy task tokenizing a string\n");
  printf("string1: %s\nstring2: %s\n", string1, string2);
  char *string_token = NULL;
  char delimeter[] = ":";
    int position = 1;
  printf("string1 tokenised by position %d\n and by call by value: %s\n",
         position, get_specific_token_value(string1, delimeter, position));
  get_specific_token_referenze(string2, delimeter, position, &string_token);
  printf("string2 tokenized by position: %d\ncall by referenze output: %s\n",
         position, string_token);
}
