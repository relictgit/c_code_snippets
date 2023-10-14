#ifndef MATCH_H_
#define MATCH_H_

typedef struct {
  int length;
  int offset;
} match;

match findMatch(char *buffer, int currentPosition, int bufferSize,
                int max_buf_size);

#endif /* MATCH_H_ */
