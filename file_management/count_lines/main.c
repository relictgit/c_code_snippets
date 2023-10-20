#include <stdio.h>
#include <stdlib.h>

#include "count_lines.h"

int main() {
  FILE *fp = NULL;
  char file_name[] = "./some_file.txt";
  int lines = 0;

  if ((fp = fopen(file_name, "r")) == NULL) {
    fprintf(stderr,
            "ERROR: unable to open file!\nCheck if the file \"%s\" exists!\n",
            file_name);
    exit(EXIT_FAILURE);
  } else {
    lines = count_lines(fp);
  }
  fclose(fp);

  printf("The files name is: \"%s\"\nThe file line numbers are: \"%d\"\n",
         file_name, lines);
  return EXIT_SUCCESS;
}
