#include <stdio.h>
#include <string.h>

int main() {
  const char filename[] = "example.txt";
  const char *read_mode = "r";
  /* const char *write_mode = "w"; */
  /* const char *append_mode = "a"; */
  /* const char *write_and_append_mode = "w+"; */
  char buffer[256];
  int lineNumber = 1;

  printf("This program will read in %s\n", filename);
  printf("Then this program will search for \"foo\" and\n");
  printf("print it onto the screen with the coresponding line number\n");
  printf("After this the entire line where \"foo\" has been found will be\n");
  printf("printed with \"foo\" being marked red like when using the grep "
         "command\n\n");

  FILE *file = NULL;
  if ((file = fopen(filename, read_mode)) == NULL) {
    printf("Fehler beim Öffnen der Datei!\n");
    return 1;
  }

  while (fgets(buffer, sizeof(buffer), file)) {
    char *searchString = "foo";
    char *searchResult = strstr(buffer, searchString);
    if (strstr(buffer, "foo") != NULL) {
      printf("foo wurde in Zeile %d gefunden\n", lineNumber);

      // Hier wird der gefundene String in roter Farbe ausgegeben
      // printf("\033[0;31m%s\033[0m", buffer);

      // Der Teil der Zeile vor dem Suchbegriff wird in normaler Farbe
      // geschrieben
      fwrite(buffer, sizeof(char), searchResult - buffer, stdout);

      // Der Suchbegriff wird in roter Farbe geschrieben
      printf("\033[0;31m%s\033[0m", searchString);

      // Der Teil der Zeile nach dem Suchbegriff wird in normaler Farbe
      // geschrieben
      printf("%s", searchResult + strlen(searchString));
    }
    lineNumber += 1;
  }

  fclose(file);

  return 0;
}
