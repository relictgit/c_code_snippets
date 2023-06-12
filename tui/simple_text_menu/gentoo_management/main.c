#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void execute_command(char *command, char *log_file) {
  const char ERROR_LOG[30] = "ERROR_LOG.out";
  FILE *log = fopen(log_file, "a");
  FILE *error_log = fopen(ERROR_LOG, "a");
  char buffer[512];
  FILE *fp = popen(command, "r");
  if (fp == NULL) {
    fprintf(error_log, "Error executing command: %s\n", command);
    fclose(error_log);
    fclose(log);
    return;
  }
  while (fgets(buffer, sizeof(buffer), fp) != NULL) {
    fputs(buffer, log);
    printf("%s", buffer);
  }
  pclose(fp);
  fclose(log);
  fclose(error_log);
}

int main() {
  char choice = '0';
  while (choice != 'q') {
    printf("\nMENU\n=====\n");
    printf("1. Update system\n");
    printf("2. to_be_continued\n");
    printf("q. Quit\n");

    printf("Enter your choice: ");
    scanf(" %c", &choice);

    switch (choice) {
    case '1':
      if (getuid() == 0) {
        execute_command("emerge --sync", "update_system_log.out");
       execute_command("emerge -vuDN @world", "update_system_log.out");
        execute_command("emerge -c", "update_system_log.out");
      } else {
        execute_command("doas emerge --sync", "update_system_log.out");
        execute_command("doas emerge -vuDN @world", "update_system_log.out");
        execute_command("doas emerge -c", "update_system_log.out");
      }
      break;

    case '2':
      printf("Functionality to_be_continued...\n");
      break;

    case 'q':
      printf("Exiting...\n");
      break;

    default:
      printf("Invalid choice!\n");
      break;
    }
  }
  return 0;
}
