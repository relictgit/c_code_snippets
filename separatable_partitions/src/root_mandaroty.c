#include <stdio.h>
#include <stdlib.h>
#include "../headers/root_mandaroty.h"

void print_root_mandatory_directories() {
  char *bin = "the /bin directory contains all the binaries that can be run at user level";
  char *sbin = "the /sbin directory contains all the binaries that can only be run at root user level (super user / admin)";
  char *usr = "the /usr directory contains also binaries in subdirectories like /usr/bin and /usr/sbin";
  
  printf("\nfunction: print_root_mandatory_directories\n");
  printf("information shown here: directories which should be included into the root file system\n");
  printf("/bin:\t%s\n", bin);
  printf("/sbin:\t%s\n", sbin);
  printf("/usr:\t%s\n", usr);
  printf("finished\n");
}

