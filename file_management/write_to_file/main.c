/* Description:  simple c file to write contents to a file
 * Author:       kvoss
 * Date created: 19.10.2023 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

void write_hello_world();

int main()
{
  write_hello_world();
  return 0;
}

void write_hello_world()
{
  char filename[] = "example.txt";
  FILE *fptr = NULL;
  char content_line_one[] = "Hello World!";

  if ((fptr = fopen(filename, "w")) == NULL)
  {
    fprintf(stderr, "ERROR - Could not open file: %s - error code: %s\n", filename, strerror(errno));
    exit(EXIT_FAILURE);
  }
  else
  {
    fprintf(fptr, "%s\n", content_line_one);
    fclose(fptr);
  }
}
