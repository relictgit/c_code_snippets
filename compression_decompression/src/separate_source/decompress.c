#include "decompress.h"
#include <stdio.h>
#include <string.h>

void decompress(char *inputBuffer, int inputSize, int max_buf_size) {
  char outputBuffer[max_buf_size];
  int outputSize = 0;
  int currentPosition = 0;

  while (currentPosition < inputSize) {
    char currentByte = inputBuffer[currentPosition];
    currentPosition++;

    if (currentByte < 0x10) {
      outputBuffer[outputSize] = currentByte;
      outputSize++;
    } else {
      int offset = (currentByte & 0xf0) >> 4;
      int length = currentByte & 0x0f;

      for (int i = 0; i < length; i++) {
        outputBuffer[outputSize] = outputBuffer[outputSize - offset];
        outputSize++;
      }
    }
  }

  for (int i = 0; i < outputSize; i++) {
    printf("%c", outputBuffer[i]);
  }
}
