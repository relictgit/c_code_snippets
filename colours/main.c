#include <stdio.h>

int main() {
  const char *string = "foo";

  printf("\033[0;30m%s\033[0m\n", string);  // Schwarz
  printf("\033[0;31m%s\033[0m\n", string);  // Rot
  printf("\033[0;32m%s\033[0m\n", string);  // Grün
  printf("\033[0;33m%s\033[0m\n", string);  // Gelb
  printf("\033[0;34m%s\033[0m\n", string);  // Blau
  printf("\033[0;35m%s\033[0m\n", string);  // Magenta
  printf("\033[0;36m%s\033[0m\n", string);  // Cyan
  printf("\033[0;37m%s\033[0m\n", string);  // Weiß

  return 0;
}

/*
Dieses Programm gibt den String "foo" in den Farben
  Schwarz,
  Rot,
  Grün,
  Gelb,
  Blau,
  Magenta,
  Cyan
  und Weiß aus.
Es verwendet Escape-Sequenzen, um die Farben festzulegen.
Das Format ist \033[<Code>m, wobei <Code> den Code für die gewünschte Farbe darstellt.
*/
