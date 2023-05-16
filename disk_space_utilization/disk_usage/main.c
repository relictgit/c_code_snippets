// #include "/usr/include/mailutils/python.h" => emerging the package
// dev-python/pygobject is neccesary
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

long int calculateFileSize(char *filePath);

void exploreDirectory(char *dirPath, long int *totalSize);

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Usage: %s [directory path]\n", argv[0]);
    return 1;
  }

  long int totalSize = 0;
  exploreDirectory(argv[1], &totalSize);
  printf("Total size: %ld bytes\n", totalSize);

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
      printf("%s, %ld bytes\n", childPath, fileSize);
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

/* embedding python
```python
def convert_size(size_bytes):
"""
Converts bytes to appropriate unit
"""
if size_bytes < 1024:
return f"{size_bytes} Bytes"
elif 1024 <= size_bytes < 1048576:
return f"{size_bytes / 1024:.2f} KB"
elif 1048576 <= size_bytes < 1073741824:
return f"{size_bytes / 1048576:.2f} MB"
elif 1073741824 <= size_bytes < 1099511627776:
return f"{size_bytes / 1073741824:.2f} GB"
else:
return f"{size_bytes / 1099511627776:.2f} TB"
```
* Um diese Funktion in deinem bestehenden Programm zu verwenden,
* musst du nur den Aufruf
* `print(f"Size: {os.path.getsize(file_path)}")` in
* `print(f"Size: {convert_size(os.path.getsize(file_path))}")`
* ändern.
* Dadurch wird die Bytegröße automatisch in eine besser lesbare Einheit
konvertiert.
*
* matterial:
* https://docs.python.org/3/library/stdtypes.html#mapping-types-dict
* https://docs.python.org/3/extending/embedding.html
*
* oder einfach eine C Funktion schreiben, die genau das gleiche macht.
*/
