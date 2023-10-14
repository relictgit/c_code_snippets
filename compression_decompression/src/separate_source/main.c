#include "compress.h"
#include "decompress.h"
#include <stdio.h>
#include <string.h>

int main(int argc, const char *argv[]) {
  int max_buf_size = 1024;
  char inputBuffer[max_buf_size];
  int inputSize = 0;

  printf("Bitte geben Sie den zu komprimierenden Text ein: ");
  fgets(inputBuffer, max_buf_size, stdin);
  inputSize = strlen(inputBuffer);

  printf("Komprimierte Daten: ");
  compress(inputBuffer, inputSize, max_buf_size);
  printf("\nDekomprimierter Text: ");
  decompress(inputBuffer, inputSize, max_buf_size);

  return 0;
}
