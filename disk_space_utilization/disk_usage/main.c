// #include "/usr/include/mailutils/python.h" => emerging the package
// dev-python/pygobject is neccesary
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

long int calculateFileSize(char *filePath);

void printFileSize(long int fileSize);

void exploreDirectory(char *dirPath, long int *totalSize);

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Usage: %s [directory path]\n", argv[0]);
    return 1;
  }

  long int totalSize = 0;
  exploreDirectory(argv[1], &totalSize);
  // printf("Total size: %ld bytes\n", totalSize);
  printf("Total size: ");
  printFileSize(totalSize);

  return 0;
}

void exploreDirectory(char *dirPath, long int *totalSize) {
  DIR *dir = opendir(dirPath);
  if (!dir) {
    printf("Could not open directory %s\n", dirPath);
    return;
  }

  struct dirent *entry;
  while ((entry = readdir(dir)) != NULL) {
    if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
      continue;
    }

    char childPath[1024];
    snprintf(childPath, sizeof(childPath), "%s/%s", dirPath, entry->d_name);

    if (entry->d_type == DT_DIR) {
      exploreDirectory(childPath, totalSize);
    } else {
      long int fileSize = calculateFileSize(childPath);
      // printf("%s, %ld bytes\n", childPath, fileSize);
      printf("%s:", childPath);
      printFileSize(fileSize);
      *totalSize += fileSize;
    }
  }

  closedir(dir);
}

long int calculateFileSize(char *filePath) {
  struct stat st;
  stat(filePath, &st);

  return st.st_size;
}

void printFileSize(long int fileSize) {
  char result[20]; // Array für das Ergebnis der sprintf Funktion
  /* Array mit den Größenordnungen */
  /* mögliche Größenordnungen / Byte Vielfache sind:
   * Bytes
   * Kilobytes
   * Megabytes
   * Gigabytes
   * Terrabtes
   * Petabytes
   * Exabytes
   * Zettabytes
   * Yottabytes
   * Ronnabytes
   * Quettabytes
   * siehe Dazu auch die Abbildung aus Wikipedia als Vorschaumatterial: https://de.wikipedia.org/wiki/Byte#Vergleichstabelle
   */
  const char *fileSizeUnits[] = {"Bytes", "KB", "MB", "GB",
                                 "TB", "PB", "EB", "ZB",
                                 "YB", "RB", "QB"};

  // Berechnung der Größenordnung und Umwandlung in die entsprechende Einheit
  int unitIndex = 0;
  double size = (double)fileSize;
  while (size >= 1024.0 &&
         unitIndex < 10) { // < 10 is the max count value of elements inside of
                          // the fileSizeUnits array
    size /= 1024.0;
    unitIndex++;
  }

  // Formatieren des Ergebnisses mit "sprintf"
  sprintf(result, "%.2f %s", size, fileSizeUnits[unitIndex]);

  // Ausgabe des Ergebnisses auf der Konsole
  printf("\t%s\n", result);
}
