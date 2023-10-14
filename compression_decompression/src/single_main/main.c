#include <stdio.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct {
  int length; // Länge des übereinstimmenden Teils
  int offset; // Offset vom Anfang der Sequenz
} match;

match findMatch(char *buffer, int currentPosition, int bufferSize) {
  match bestMatch = {0, 0}; // beste Übereinstimmung
  int maxLength = 0;        // maximale Länge der Übereinstimmung
  int searchLimit =
      currentPosition > MAX_BUFFER_SIZE ? MAX_BUFFER_SIZE : currentPosition;
  for (int i = 1; i < searchLimit; i++) {
    int sequenceLength = 0;
    while (buffer[currentPosition - i + sequenceLength] ==
           buffer[currentPosition + sequenceLength]) { // vergleiche Sequenz
      sequenceLength++;
      if (currentPosition + sequenceLength >= bufferSize) {
        break;
      }
    }
    if (sequenceLength > maxLength) { // speichere beste Übereinstimmung
      maxLength = sequenceLength;
      bestMatch.length = maxLength;
      bestMatch.offset = i;
    }
  }
  return bestMatch;
}

void compress(char *inputBuffer, int inputSize) {
  /* seems to work */
  char outputBuffer[MAX_BUFFER_SIZE]; // Ausgabe-Buffer
  int outputSize = 0;                 // Größe der Ausgabe
  int currentPosition = 0;            // aktuelle Position im Eingabe-Buffer

  while (currentPosition < inputSize) { // komprimiere den gesamten Buffer
    match currentMatch = findMatch(inputBuffer, currentPosition,
                                   inputSize); // finde beste Übereinstimmung
    if (currentMatch.length > 2) { // wenn Übereinstimmung größer als zwei
                                   // Zeichen ist, schreibe die gestauchte Form
      outputBuffer[outputSize++] = currentMatch.offset; // Offset schreiben
      outputBuffer[outputSize++] = currentMatch.length; // Länge schreiben
      currentPosition +=
          currentMatch.length; // springe zur Endposition der Übereinstimmung
    } else { // sonst schreibe das unbehandelte Zeichen in die Ausgabe
      outputBuffer[outputSize] = inputBuffer[currentPosition];
      outputSize++;
      currentPosition++;
    }
  }

  // schreibe die komprimierten Daten in die Konsole
  for (int i = 0; i < outputSize; i++) {
    printf("0x%02x ", outputBuffer[i]);
  }
}

void decompress(char *inputBuffer, int inputSize) {
  /* to be under maintenance */
  char outputBuffer[MAX_BUFFER_SIZE]; // Ausgabe-Buffer
  int outputSize = 0;                 // Größe der Ausgabe
  int currentPosition = 0;            // aktuelle Position im Eingabe-Buffer

  while (currentPosition < inputSize) { // dekomprimiere den gesamten Buffer
    char currentByte = inputBuffer[currentPosition];
    currentPosition++;
    if (currentByte < 0x10) { // unbehandeltes Byte schreiben
      outputBuffer[outputSize] = currentByte;
      printf("outputBuffer[outputSize]: %c\n", outputBuffer[outputSize]);
      outputSize++;
    } else {                                  // gestauchte Form dekomprimieren
      int offset = (currentByte & 0xf0) >> 4; // Offset bestimmen
      int length = currentByte & 0x0f;        // Länge bestimmen
      for (int i = 0; i < length; i++) { // dekomprimierte Sequenz schreiben
        outputBuffer[outputSize] = outputBuffer[outputSize - offset];
        printf("outputBuffer[outputSize]: %c\n", outputBuffer[outputSize]);
        outputSize++;
      }
    }
  }

  // schreibe die dekomprimierten Daten in die Konsole
  for (int i = 0; i < outputSize; i++) {
    printf("%c", outputBuffer[i]);
  }
}

int main(int argc, const char *argv[]) {
  char inputBuffer[MAX_BUFFER_SIZE];
  int inputSize = 0;

  // lese die Eingabe aus der Konsole
  printf("Bitte geben Sie den zu komprimierenden Text ein: ");
  fgets(inputBuffer, MAX_BUFFER_SIZE, stdin);
  inputSize = strlen(inputBuffer);

  // komprimiere und dekomprimiere den Text
  printf("Komprimierte Daten: ");
  compress(inputBuffer, inputSize);
  printf("\nDekomprimierter Text: ");
  decompress(inputBuffer, inputSize);

  return 0;
}
