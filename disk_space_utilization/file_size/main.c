#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

off_t fsize(const char *filename) {
  struct stat st;

  if (stat(filename, &st) == 0) {
    return st.st_size;
  }
  return -1;
}

int main(int argc, const char *argv[]) {
  if (argc != 2) {
    printf("argc: %d\n", argc);
    printf("Usage: %s <file>\n", argv[0]);
    return 1;
  }

  const char *f_name = argv[1];
  printf("the size of the file %s is %lu bytes\n", f_name, fsize(f_name));

  return 0;
}
