#include "../header/string_functions.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

short main_string_fun() {
  print_upper_string();
  print_lower_string();

  /* strcat(string1, string2); // appends string2 to the end of string1
   * strncat(string1, string2, 1); // appends n characters
   *                                 from string2 to string1
   * strcpy(string1, string2); // copy/replace string2 to string1
   * strncpy(string1, string2, 1); // copy/replace n characters
   *                                  of string2 to string1
   * strset(string1, '?'); // sets all characters of a string to a given
   *                          character (string = bro - result = ???)
   * strnset(string1, 'x', 1); // sets first n characters of a string
   *                              to a given character
   * strrev(string1); // reverse string
   * int result = strlen(string1); // returns the length of a string
   * int result = strcmp(string1, string2); // string compare all characters
   * if strings are the same it returns 0, else non 0
   * int result = strncmp(string1, string2, 1); // string compare n characters
   * int result = strcmpi(string1, string1); // string compare all (ignore case)
   * int result = strnicmp(string1, string1, 1); // string compare n characters
   *                                                (ignore case)
   */

  return 0;
}

void print_upper_string() {
  char string1[] = "Bro";
  char string1_upper[30] = "";
  char ch;
  int count = 0;
  // to upper
  while (string1[count]) {
    ch = string1[count];
    string1_upper[count] = toupper(ch);
    count++;
  }
  printf("The string is: %s\nto upper the string is: %s\n", string1,
         string1_upper);
}

void print_lower_string() {
  char string2[] = "Coding";
  char string2_lower[30] = "";
  char ch;
  int count = 0;
  // to lower
  count = 0;
  while (string2[count]) {
    ch = string2[count];
    string2_lower[count] = tolower(ch);
    count++;
  }
  printf("The string is: %s\nto lower the string is: %s\n", string2,
         string2_lower);
}
