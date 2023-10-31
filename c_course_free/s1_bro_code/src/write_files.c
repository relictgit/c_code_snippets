#include "../header/write_files.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* file modes:
 * w -- write
 * a -- append
 */

short main_write_files() {
  /* file writing / creation
  FILE *fptr = NULL;
  if ((fptr = fopen("test.txt", "w")) == NULL) {
    fprintf(stderr, "ERROR: could not open file! Errorcode: %s\n",
            strerror(errno));
    exit(EXIT_FAILURE);
  } else {
    fprintf(fptr, "This is an example line\n");
    fclose(fptr);
  }
  */

  /* file deletion
  if (remove("test.txt") == 0) {
    printf("The file \"test.txt\" was deleted successfully\n");
  } else {
    printf("File could not be deleted... mabe it does not even exist.\n");
  }
  */

  return 0;
}
