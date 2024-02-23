#include <stdio.h>
#include <string.h>

/* todo
 * Define the string first_name with the value John using the pointer notation,
 * and define the string last_name with the value Doe using the local array notation. */

int main() {
    /* define first_name */
    char *first_name = "John";
    /* define last_name */
    char last_name[] = "Doe";
    char name[100];

    last_name[0] = 'B';
    sprintf(name, "%s %s", first_name, last_name);
    if(strncmp(name, "John Boe", 100) == 0) {
        printf("Done!\n");
    }
    name[0] = '\0';
    strncat(name, first_name, 4);
    strncat(name, last_name, 20);
    printf("%s\n", name);
    return 0;
}
