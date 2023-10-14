#include "match.h"

match findMatch(char *buffer, int currentPosition, int bufferSize,
                int max_buf_size) {
  match bestMatch = {0, 0};
  int maxLength = 0;
  int searchLimit =
      currentPosition < max_buf_size ? currentPosition : max_buf_size;

  for (int i = 1; i < searchLimit; i++) {
    int sequenceLength = 0;
    while (buffer[currentPosition - i + sequenceLength] ==
           buffer[currentPosition + sequenceLength]) {
      sequenceLength++;
      if (currentPosition + sequenceLength >= bufferSize) {
        break;
      }
    }
    if (sequenceLength > maxLength) {
      maxLength = sequenceLength;
      bestMatch.length = maxLength;
      bestMatch.offset = i;
    }
  }
  return bestMatch;
}
