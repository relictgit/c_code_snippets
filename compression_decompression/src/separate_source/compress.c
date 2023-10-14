#include "compress.h"
#include "match.h"
#include <stdio.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

void compress(char *inputBuffer, int inputSize, int max_buf_size) {
  char outputBuffer[MAX_BUFFER_SIZE];
  int outputSize = 0;
  int currentPosition = 0;

  while (currentPosition < inputSize) {
    match currentMatch =
        findMatch(inputBuffer, currentPosition, inputSize, max_buf_size);

    if (currentMatch.length > 2) {
      outputBuffer[outputSize++] = currentMatch.offset;
      outputBuffer[outputSize++] = currentMatch.length;
      currentPosition += currentMatch.length;
    } else {
      outputBuffer[outputSize] = inputBuffer[currentPosition];
      outputSize++;
      currentPosition++;
    }
  }

  for (int i = 0; i < outputSize; i++) {
    printf("0x%02x ", outputBuffer[i]);
  }
}
