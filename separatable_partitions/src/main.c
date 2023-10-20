#include <stdio.h>
#include <stdlib.h>
#include "../headers/separatable.h"
#include "../headers/root_mandaroty.h"

int main() {
  printf("this program will show the directories,\nwhich will be able to put separately into an fstab file located at /etc.\n");
  printf("as well this program will also show the directories,\nwich must be included in root.\n");

  print_separatable_directories();
  print_root_mandatory_directories();

  return 0;
}


