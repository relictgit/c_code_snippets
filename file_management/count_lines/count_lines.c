#include <stdio.h>
#include <stdlib.h>

#include "count_lines.h"

int count_lines(FILE *fp) {
  int lines = 0;
  char ch;
  while (!feof(fp)) {
    ch = fgetc(fp);
    if (ch == '\n') {
      lines++;
    }
  }
  return lines;
}
