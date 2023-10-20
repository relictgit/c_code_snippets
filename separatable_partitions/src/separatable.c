#include "../headers/separatable.h"
#include <stdio.h>
#include <stdlib.h>

void print_separatable_directories() {
  char *var = "/var is separated mostly due to performance reasons. /var "
              "contains continous changing data";
  char *run = "/run is mostly separated into a tmpfs";
  char *tmp = "/tmp is mostly separated into a tmpfs";
  char *opt = "/opt is recommended to be used separately in an LVM";
  char *srv = "/srv is recommended to be used separately in an LVM";
  char *boot = "/boot is almost all the time separated because it contains the "
               "boot code (deprecated MBR or modern UEFI)";
  char *home = "/home is a best practise to separate from the root system for "
               "logical reasons. Split the user data from the system data";

  printf("\nfunction: print_separatable_directories\n");
  printf("the following list includes the separatable directories.\n");
  printf("/var:\t%s\n", var);
  printf("/opt:\t%s\n", opt);
  printf("/srv:\t%s\n", srv);
  printf("/boot:\t%s\n", boot);
  printf("/home:\t%s\n", home);
  printf("/run:\t%s\n", run);
  printf("/tmp:\t%s\n", tmp);
  printf("finished\n");
}
