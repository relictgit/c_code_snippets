#include <stdio.h>

/* todo
 * The code below does not compile, because the grades variable is missing.
 * One of the grades is missing. Can you define it so the grade average will be 85?
 */

int main() {
    /* TODO: define the grades variable here */
    int grades[10];
    int average;

    grades[0] = 80;
    /* TODO: define the missing grade
       so that the average will sum to 85. */
    grades[1] = 85;
    grades[2] = 90;

    average = (grades[0] + grades[1] + grades[2]) / 3;
    printf("The average of the 3 grades is: %d", average);

    return 0;
}
